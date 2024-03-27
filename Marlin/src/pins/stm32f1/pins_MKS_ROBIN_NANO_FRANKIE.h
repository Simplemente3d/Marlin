/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F103VET6) Frankie board pin assignments
 * https://github.com/makerbase-mks/MKS-Robin-Nano-V1.X/tree/master/hardware
 * This board uses the E1 heater instead of E0. This is due to the E0 MOSFET
 * failing after a short. All other pins remain the same.
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME "MKS Robin Nano Frankie"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_JTAG

//
// Thermocouples
//
//#define TEMP_0_CS_PIN                     PE5   // TC1 - CS1
//#define TEMP_0_CS_PIN                     PE6   // TC2 - CS2

//#define LED_PIN                           PB2

//
// Heaters / Fans Override when Heater_0_PIN (PC3)
// blows out its MOSFET
//

#ifndef HEATER_0_PIN
  #define HEATER_0_PIN                    PB0 // Originally PC3
#endif

#ifndef FAN1_PIN
  #define FAN1_PIN                        PC3
#endif

#include "pins_MKS_ROBIN_NANO_common.h"

#if HAS_TFT_LVGL_UI && FAN1_PIN != PC3 && HEATER_1_PIN != PC3
  #define BOARD_INIT() OUT_WRITE(PC3, LOW)
#endif

