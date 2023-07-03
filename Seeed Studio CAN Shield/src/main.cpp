#include "common/bb_can.h"
#include <Arduino.h>
#include <can.h>
#include <stdint.h>

#define CAN_CS (9) // Seeed Studio CAN Shield
//#define CAN_CS (10) // BB CAN Shield
#define HB_LOOP (1000);

void CAN_init();
void publishCAN_heartbeat(int device_id);

MCP_CAN CAN(CAN_CS);

static uint32_t hb_loop = 0;

uint32_t id = 0;
uint8_t len = 0;
uint8_t buf[8];

void setup() {
  pinMode(CAN_CS, OUTPUT);
  digitalWrite(CAN_CS, HIGH);
  Serial.begin(115200);
  Serial.println("Initialisation");
  CAN_init();
}

void loop() {

  uint16_t current = 0;
  uint16_t voltage = 0;
  uint16_t soc = 0;
  uint16_t capacity = 0;

  uint16_t pressure = 0;
  uint16_t temperature = 0;
  // if (millis() - hb_loop > 1000) {
  //   publishCAN_heartbeat(bb::heartbeat_id::PMB_1);
  //   hb_loop = millis();
  // }
  if (CAN_MSGAVAIL == CAN.checkReceive()) {
    CAN.readMsgBufID(&id, &len, buf);
    Serial.print("Can id: ");
    Serial.println(CAN.getCanId());

    switch (CAN.getCanId()) {
    case bb::can_id::HEARTBEAT:
      uint8_t device = CAN.parseCANFrame(buf, 0, 1);
      Serial.print("Device Heartbeat: ");
      Serial.println(device);
      break;
    case bb::can_id::BATT_1_STAT:
    case bb::can_id::BATT_2_STAT:
      current = CAN.parseCANFrame(buf, 0, 2);
      voltage = CAN.parseCANFrame(buf, 2, 2);
      soc = CAN.parseCANFrame(buf, 4, 2);
      capacity = CAN.parseCANFrame(buf, 6, 2);
      Serial.print("Current: ");
      Serial.println(current);
      Serial.print("Voltage: ");
      Serial.println(voltage);
      Serial.print("SOC: ");
      Serial.println(soc);
      Serial.print("Capacity: ");
      Serial.println(capacity);
      break;

    case bb::can_id::PMB_1_STAT:
    case bb::can_id::PMB_2_STAT:
      pressure = CAN.parseCANFrame(buf, 2, 2);
      temperature = CAN.parseCANFrame(buf, 0, 2);
      Serial.print("Temperature: ");
      Serial.println(temperature);
      Serial.print("Pressure: ");
      Serial.println(pressure);
      break;

    default:
      for (int i = 0; i < len; i++) {
        Serial.print(buf[i]);
        Serial.print(",");
      }
      Serial.println();
      break;
    }
    CAN.clearMsg();
  }
}

void CAN_init() {
START_INIT:
  if (CAN_OK == CAN.begin(CAN_500KBPS)) // init can bus : baudrate = 2220Kbps
  {
    Serial.println("CAN BUS: OK");
  } else {
    Serial.println("CAN BUS: FAILED");
    Serial.println("CAN BUS: Reinitializing");
    delay(1000);
    goto START_INIT;
  }
  Serial.println("INITIATING TRANSMISSION...");
}

void publishCAN_heartbeat(int device_id) {
  id = bb::can_id::HEARTBEAT;
  len = 1;
  buf[0] = device_id;
  CAN.sendMsgBuf(bb::can_id::HEARTBEAT, 0, 1, buf);
}