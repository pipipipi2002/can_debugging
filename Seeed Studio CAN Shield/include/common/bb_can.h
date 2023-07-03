/**
 *  ========================
 *      AUV4 CAN STANDARD
 *  ========================
 *
 *  Define actual values in this header file ONLY -- this is the single source of truth
 *  - Names should follow the syntax: BB_<TYPE>_<NAME>
 *  - Best to roughly follow the naming used in the namespaced version defined in `bb_can.hpp`
 *  This header file is necessary to support C files (STM32)
 *  - Namespaced definitions in `bb_can.hpp` only work for C++ files
 */

#pragma once

#include <stdint.h>

#define BB_MASK(x) (1UL << (x))

// clang-format off

/*
 * CAN IDs
 */
#define BB_CAN_ID_THR_1_CTRL                (0)
#define BB_CAN_ID_THR_2_CTRL                (1)
#define BB_CAN_ID_ACT_CTRL                  (2)
#define BB_CAN_ID_PWR_CTRL                  (3)
#define BB_CAN_ID_HEARTBEAT                 (4)
#define BB_CAN_ID_TEMP_SBC                  (5)

#define BB_CAN_ID_STB_STAT                  (11)
#define BB_CAN_ID_LED_CTRL                  (12)
#define BB_CAN_ID_BUTTON_STAT               (13)

#define BB_CAN_ID_THR_1_RPM                 (17)
#define BB_CAN_ID_THR_2_RPM                 (18)
#define BB_CAN_ID_THR_1_DUTY                (19)
#define BB_CAN_ID_THR_2_DUTY                (20)

#define BB_CAN_ID_BATT_1_STAT               (23)
#define BB_CAN_ID_PMB_1_STAT                (24)
#define BB_CAN_ID_BATT_2_STAT               (25)
#define BB_CAN_ID_PMB_2_STAT                (26)

#define BB_CAN_ID_PWR_STAT                  (30)

#define BB_CAN_ID_ERR_TAB                   (32)
#define BB_CAN_ID_ERR_STB                   (33)
#define BB_CAN_ID_ERR_PMB_1                 (34)
#define BB_CAN_ID_ERR_PMB_2                 (35)
#define BB_CAN_ID_ERR_SBCCAN                (36)

/*
 *  UNISO CAN IDs
 */
#define BB_CAN_UNISO_ID_VESC_1              (1)
#define BB_CAN_UNISO_ID_VESC_2              (2)
#define BB_CAN_UNISO_ID_VESC_3              (3)
#define BB_CAN_UNISO_ID_VESC_4              (4)
#define BB_CAN_UNISO_ID_VESC_5              (5)
#define BB_CAN_UNISO_ID_VESC_6              (6)
#define BB_CAN_UNISO_ID_VESC_7              (7)
#define BB_CAN_UNISO_ID_VESC_8              (8)
#define BB_CAN_UNISO_ID_ACT_HEARTBEAT       (10)

/*
 *  Heartbeat IDs
 */
#define BB_HEARTBEAT_ID_SBC                 (1)
#define BB_HEARTBEAT_ID_SBCCAN              (2)
#define BB_HEARTBEAT_ID_TAB                 (4)
#define BB_HEARTBEAT_ID_STB                 (5)
#define BB_HEARTBEAT_ID_ACT                 (6)
#define BB_HEARTBEAT_ID_PMB_1               (7)
#define BB_HEARTBEAT_ID_PMB_2               (8)

/*
 *  Actuation Bits
 */
#define BB_ACTUATION_BIT_ACTIVATE_GRABBER   BB_MASK(0)
#define BB_ACTUATION_BIT_RELEASE_GRABBER    BB_MASK(1)
#define BB_ACTUATION_BIT_FIRE_TOP           BB_MASK(2)
#define BB_ACTUATION_BIT_FIRE_BOTTOM        BB_MASK(4)
#define BB_ACTUATION_BIT_FIRE_DROPPER       BB_MASK(6)

/*
 *  Power Control Bits
 */
// Need bit positions as well because SBC-CAN is cringe
#define BB_POWER_BITPOS_SWITCH              0
#define BB_POWER_BITPOS_ACOUSTICS           1
#define BB_POWER_BITPOS_ORIN                2
#define BB_POWER_BITPOS_STB                 3
#define BB_POWER_BITPOS_TAB                 4
#define BB_POWER_BITPOS_DVL                 5
#define BB_POWER_BITPOS_SONAR               6
#define BB_POWER_BITPOS_FOG                 7

#define BB_POWER_BIT_SWITCH                 BB_MASK(BB_POWER_BITPOS_SWITCH)
#define BB_POWER_BIT_ACOUSTICS              BB_MASK(BB_POWER_BITPOS_ACOUSTICS)
#define BB_POWER_BIT_ORIN                   BB_MASK(BB_POWER_BITPOS_ORIN)
#define BB_POWER_BIT_STB                    BB_MASK(BB_POWER_BITPOS_STB)
#define BB_POWER_BIT_TAB                    BB_MASK(BB_POWER_BITPOS_TAB)
#define BB_POWER_BIT_DVL                    BB_MASK(BB_POWER_BITPOS_DVL)
#define BB_POWER_BIT_SONAR                  BB_MASK(BB_POWER_BITPOS_SONAR)
#define BB_POWER_BIT_FOG                    BB_MASK(BB_POWER_BITPOS_FOG)

// clang-format on

// Only include namespaced definitions for .cpp files
#ifdef __cplusplus
#include "bb_can.hpp"
#endif // __cplusplus
