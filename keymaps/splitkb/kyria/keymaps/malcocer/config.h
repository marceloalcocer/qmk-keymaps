/* Copyright 2021 Marcelo Alcocer <marcelo.j.p.alcocer@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once



/* OLED display ***************************************************************/
#ifdef OLED_ENABLE
    #define OLED_TIMEOUT 1000
    #define OLED_BRIGHTNESS 128
    #define OLED_DISPLAY_128X64
#endif



/* Handedness *****************************************************************/
#define EE_HANDS            // Set handedness by EEPROM



/* Encoders *******************************************************************/
#define ENCODER_DIRECTION_FLIP
#define ENCODER_DIRECTION_FLIP_RIGHT
#define ENCODER_RESOLUTION 2
#define ENCODER_RESOLUTION_RIGHT 2



/* Misc ***********************************************************************/
#define TAPPING_TERM 125    // Tweak tapping term

