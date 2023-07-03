/**
 *  ========================
 *      AUV4 CAN STANDARD
 *  ========================
 *
 *  Define actual values in `bb_can.hpp`
 *  - Namespaced values defined in this header should point to whatever is
 * defined in `bb_can.h`
 * 	- DO NOT DEFINE ACTUAL VALUES HERE
 * 	C++ compatible source files should use namespaced definitions instead of
 * macros
 */

#pragma once

#include <stdint.h>

namespace bb {

/*
 * CAN IDs are 11-bit (or 29-bit for extended frames)
 */
using can_id_t = uint32_t;

namespace can_id {
constexpr can_id_t THR_1_CTRL = BB_CAN_ID_THR_1_CTRL;
constexpr can_id_t THR_2_CTRL = BB_CAN_ID_THR_2_CTRL;
constexpr can_id_t ACT_CTRL = BB_CAN_ID_ACT_CTRL;
constexpr can_id_t PWR_CTRL = BB_CAN_ID_PWR_CTRL;
constexpr can_id_t HEARTBEAT = BB_CAN_ID_HEARTBEAT;
constexpr can_id_t TEMP_SBC = BB_CAN_ID_TEMP_SBC;

constexpr can_id_t STB_STAT = BB_CAN_ID_STB_STAT;
constexpr can_id_t LED_CTRL = BB_CAN_ID_LED_CTRL;
constexpr can_id_t BUTTON_STAT = BB_CAN_ID_BUTTON_STAT;

constexpr can_id_t THR_1_RPM = BB_CAN_ID_THR_1_RPM;
constexpr can_id_t THR_2_RPM = BB_CAN_ID_THR_2_RPM;
constexpr can_id_t THR_1_DUTY = BB_CAN_ID_THR_1_DUTY;
constexpr can_id_t THR_2_DUTY = BB_CAN_ID_THR_2_DUTY;

constexpr can_id_t BATT_1_STAT = BB_CAN_ID_BATT_1_STAT;
constexpr can_id_t PMB_1_STAT = BB_CAN_ID_PMB_1_STAT;
constexpr can_id_t BATT_2_STAT = BB_CAN_ID_BATT_2_STAT;
constexpr can_id_t PMB_2_STAT = BB_CAN_ID_PMB_2_STAT;

constexpr can_id_t PWR_STAT = BB_CAN_ID_PWR_STAT;

constexpr can_id_t ERR_TAB = BB_CAN_ID_ERR_TAB;
constexpr can_id_t ERR_STB = BB_CAN_ID_ERR_STB;
constexpr can_id_t ERR_PMB_1 = BB_CAN_ID_ERR_PMB_1;
constexpr can_id_t ERR_PMB_2 = BB_CAN_ID_ERR_PMB_2;
constexpr can_id_t ERR_SBCCAN = BB_CAN_ID_ERR_SBCCAN;
}; // namespace can_id

namespace can_uniso_id {
constexpr can_id_t VESC_1 = BB_CAN_UNISO_ID_VESC_1;
constexpr can_id_t VESC_2 = BB_CAN_UNISO_ID_VESC_2;
constexpr can_id_t VESC_3 = BB_CAN_UNISO_ID_VESC_3;
constexpr can_id_t VESC_4 = BB_CAN_UNISO_ID_VESC_4;
constexpr can_id_t VESC_5 = BB_CAN_UNISO_ID_VESC_5;
constexpr can_id_t VESC_6 = BB_CAN_UNISO_ID_VESC_6;
constexpr can_id_t VESC_7 = BB_CAN_UNISO_ID_VESC_7;
constexpr can_id_t VESC_8 = BB_CAN_UNISO_ID_VESC_8; // Reserved
constexpr can_id_t ACT_HEARTBEAT = BB_CAN_UNISO_ID_ACT_HEARTBEAT;

// All VESC IDs for convenience
constexpr can_id_t VESC_IDS[] = {VESC_1, VESC_2, VESC_3, VESC_4,
                                 VESC_5, VESC_6, VESC_7, VESC_8};
} // namespace can_uniso_id

/*
 *	Heartbeat IDs
 * 	- Packet data for bb::can_id::HEARTBEAT
 */
namespace heartbeat_id {
constexpr uint8_t SBC = BB_HEARTBEAT_ID_SBC;
constexpr uint8_t SBCCAN = BB_HEARTBEAT_ID_SBCCAN;
constexpr uint8_t TAB = BB_HEARTBEAT_ID_TAB;
constexpr uint8_t STB = BB_HEARTBEAT_ID_STB;
constexpr uint8_t ACT = BB_HEARTBEAT_ID_ACT;
constexpr uint8_t PMB_1 = BB_HEARTBEAT_ID_PMB_1;
constexpr uint8_t PMB_2 = BB_HEARTBEAT_ID_PMB_2;
}; // namespace heartbeat_id

/*
 *	Actuation Bits
 *	- Packet data for bb::can_id::ACT_CTRL
 */
namespace actuation_bit {
constexpr uint8_t ACTIVATE_GRABBER = BB_ACTUATION_BIT_ACTIVATE_GRABBER;
constexpr uint8_t RELEASE_GRABBER = BB_ACTUATION_BIT_RELEASE_GRABBER;
constexpr uint8_t FIRE_TOP = BB_ACTUATION_BIT_FIRE_TOP;
constexpr uint8_t FIRE_BOTTOM = BB_ACTUATION_BIT_FIRE_BOTTOM;
constexpr uint8_t FIRE_DROPPER = BB_ACTUATION_BIT_FIRE_DROPPER;
} // namespace actuation_bit

/*
 *	Power Control Bits
 *	- Packet data for bb::can_id::PWR_CTRL and bb::can_id::PWR_STAT
 */
namespace power_bit {
constexpr uint8_t SWITCH = BB_POWER_BIT_SWITCH;
constexpr uint8_t ACOUSTICS = BB_POWER_BIT_ACOUSTICS;
constexpr uint8_t ORIN = BB_POWER_BIT_ORIN;
constexpr uint8_t STB = BB_POWER_BIT_STB;
constexpr uint8_t TAB = BB_POWER_BIT_TAB;
constexpr uint8_t DVL = BB_POWER_BIT_DVL;
constexpr uint8_t SONAR = BB_POWER_BIT_SONAR;
constexpr uint8_t FOG = BB_POWER_BIT_FOG;
} // namespace power_bit

}; // namespace bb
