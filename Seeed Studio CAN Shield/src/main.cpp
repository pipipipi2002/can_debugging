// demo: CAN-BUS Shield, receive data and save to sd card, can.csv
// when in interrupt mode, the data coming can't be too fast, must >20ms, or
// else you can use check mode NOTE: Only CAN Bus Shield V2.0 has SD slot, for
// other versions, you need an SD card Shield as well loovee, Jun 12, 2017

#include <SD.h>
#include <SPI.h>
#include <stdint.h>
File myFile;

const int SPI_CS_PIN = 9;
const int CAN_INT_PIN = 2;

#include "mcp2515_can.h"
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin

unsigned char flagRecv = 0;
unsigned char len = 0;
unsigned char buf[8];
char str[20];

void MCP2515_ISR();

void setup() {
  SERIAL_PORT_MONITOR.begin(115200);
  attachInterrupt(digitalPinToInterrupt(CAN_INT_PIN), MCP2515_ISR,
                  FALLING);                  // start interrupt
  while (CAN_OK != CAN.begin(CAN_500KBPS)) { // init can bus : baudrate = 500k
    SERIAL_PORT_MONITOR.println("CAN init fail, retry...");
    delay(100);
  }
  SERIAL_PORT_MONITOR.println("CAN init ok!");

  if (!SD.begin(4)) {
    SERIAL_PORT_MONITOR.println("SD init fail!");
    while (1)
      ;
  }
  SERIAL_PORT_MONITOR.println("SD init OK.");
}

void MCP2515_ISR() { flagRecv = 1; }

void loop() {
  if (flagRecv) {
    // check if get data

    flagRecv = 0; // clear flag
    unsigned long id = 0;
    uint16_t batt_current = 0;
    uint16_t batt_voltage = 0;
    uint16_t batt_capacity = 0;
    uint16_t batt_soc = 0;
    uint16_t batt_press = 0;
    uint16_t batt_temp = 0;

    myFile = SD.open("can.csv", FILE_WRITE);

    while (CAN_MSGAVAIL == CAN.checkReceive()) {
      // read data,  len: data length, buf: data buf
      CAN.readMsgBufID(&id, &len, buf);

      switch (id) {
      case 23: // Battery 1 Statistics
      case 25: // Battery 2 Statistics
        batt_current = (uint16_t)buf[0] | (uint16_t)buf[1] << 8;
        batt_voltage = (uint16_t)buf[2] | (uint16_t)buf[3] << 8;
        batt_capacity = (uint16_t)buf[4] | (uint16_t)buf[5] << 8;
        batt_soc = (uint16_t)buf[6] | (uint16_t)buf[7] << 8;
        break;
      case 24: // Hull 1 Statistics
      case 26: // Hull 2 Statistics
        batt_temp = (uint16_t)buf[0] | (uint16_t)buf[1] << 8;
        batt_press = (uint16_t)buf[2] | (uint16_t)buf[3] << 8;
        break;
      default:
        break;
      }

      SERIAL_PORT_MONITOR.println(id);
      myFile.print(id);
      myFile.print(",");

      if (id == 23 || id == 25) {
        SERIAL_PORT_MONITOR.print("Voltage: ");
        SERIAL_PORT_MONITOR.println(batt_voltage);
        myFile.print(batt_voltage);
        myFile.print(",");

        SERIAL_PORT_MONITOR.print("Current: ");
        SERIAL_PORT_MONITOR.println(batt_current);
        myFile.print(batt_current);
        myFile.print(",");

        SERIAL_PORT_MONITOR.print("Capacity: ");
        SERIAL_PORT_MONITOR.println(batt_capacity);
        myFile.print(batt_capacity);
        myFile.print(",");

        SERIAL_PORT_MONITOR.print("SOC: ");
        SERIAL_PORT_MONITOR.println(batt_soc);
        myFile.print(batt_soc);
        myFile.print(",");
      } else if (id == 24 || id == 26) {
        SERIAL_PORT_MONITOR.print("Temperature: ");
        SERIAL_PORT_MONITOR.println(batt_temp);
        myFile.print(batt_temp);
        myFile.print(",");

        SERIAL_PORT_MONITOR.print("Pressure: ");
        SERIAL_PORT_MONITOR.println(batt_press);
        myFile.print(batt_press);
        myFile.print(",");
      } else {
        for (int i = 0; i < len; i++) {
          SERIAL_PORT_MONITOR.print(buf[i]);
          SERIAL_PORT_MONITOR.print(",");

          myFile.print(buf[i]);
          myFile.print(",");
        }
        SERIAL_PORT_MONITOR.println();
      }

      myFile.println();
    }

    myFile.close();
  }
}

// END FILE
