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
#include QMK_KEYBOARD_H
#include "keymap_uk.h"



/* Keymap *********************************************************************/
#define LAYOUT_malcocer( \
    L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29,                     R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
) \
{ \
    { KC_NO, KC_NO, L05,   L04,   L03,   L02,   L01,   L00   }, \
    { KC_NO, KC_NO, L17,   L16,   L15,   L14,   L13,   L12   }, \
    { KC_NO, KC_NO, L29,   L28,   L27,   L26,   L25,   L24   }, \
    { L44,   L43,   L42,   L41,   L40,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, R06,   R07,   R08,   R09,   R10,   R11   }, \
    { KC_NO, KC_NO, R18,   R19,   R20,   R21,   R22,   R23   }, \
    { KC_NO, KC_NO, R34,   R35,   R36,   R37,   R38,   R39   }, \
    { R45,   R46,   R47,   R48,   R49,   KC_NO, KC_NO, KC_NO }, \
}

enum layers {
    ALPHA = 0,
    SYMBOL,
    NUMERIC,
    MEDIA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Alpha layer (base)
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────╮                                                 ╭──────┬──────┬──────┬──────┬──────┬────────╮
 * │  ` ¬   │   Q  │   W  │   E  │   R  │   T  │                                                 │   Y  │   U  │   I  │   O  │   P  │  - _   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                                                 ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  \ │   │   A  │   S  │  D   │   F  │   G  │                                                 │   H  │   J  │   K  │   L  │ ;  : │  # ~   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────╮                     ╭──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Meta  │   Z  │   X  │   C  │   V  │   B  │      │      │                     │      │      │   N  │   M  │ ,  < │ . >  │ /  ? │  ' @   │
 * ╰────────┴──────┴──────┼──────┼──────┼──────┤ Tab  │ Esc  │                     │ Enter│ Space├──────┼──────┼──────┼──────┴──────┴────────╯
 *                        │      │ Caps │ Bksp │ Num  │ Symb │                     │ Symb │  Num │ Bksp │ Del  │      │
 *                        │      │ LCtl │ LSft │      │      │                     │      │      │ RSft │ LAlt │      │
 *                        ╰──────┴──────┴──────┴──────┴──────╯                     ╰──────┴──────┴──────┴──────┴──────╯
 *
 */
    [ALPHA] = LAYOUT_malcocer(
      UK_GRV,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    UK_MINS,
      UK_BSLS,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                             KC_H,    KC_J,    KC_K,    KC_L,    UK_SCLN, UK_HASH,
      KC_LGUI,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                             KC_N,    KC_M,    UK_COMM, UK_DOT,  UK_SLSH, RGUI_T(UK_QUOT),
           XXXXXXX, LCTL_T(KC_CAPS), LSFT_T(KC_BSPC), LT(NUMERIC, KC_TAB), LT(SYMBOL, KC_ESC),     LT(SYMBOL, KC_ENT), LT(NUMERIC, KC_SPC), RSFT_T(KC_BSPC), LALT_T(KC_DEL), XXXXXXX
    ),
/*
 * Symbols layer
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────╮                                                 ╭──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │  !   │  "   │  {   │  }   │  │   │                                                 │      │  &   │  \   │  €   │  £   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                                                 ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  ^   │  $   │  (   │  )   │  `   │                                                 │  -   │  +   │  /   │  *   │  %   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────╮                     ╭──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │  [   │  ]   │  ~   │      │      │                     │      │      │      │      │      │      │      │        │
 * ╰────────┴──────┴──────┼──────┼──────┼──────┤  =   │  :   │                     │  :   │  =   ├──────┼──────┼──────┼──────┴──────┴────────╯
 *                        │      │      │      │ Num  │      │                     │      │ Num  │      │      │      │
 *                        │      │      │      │      │      │                     │      │      │      │      │      │
 *                        ╰──────┴──────┴──────┴──────┴──────╯                     ╰──────┴──────┴──────┴──────┴──────╯
 */
    [SYMBOL] = LAYOUT_malcocer(
      _______, UK_EXLM, UK_DQUO, UK_LCBR, UK_RCBR, UK_PIPE,                                     _______, UK_AMPR, UK_BSLS, UK_EURO,  UK_PND, _______,
      _______, UK_CIRC, UK_DLR,  UK_LPRN, UK_RPRN, UK_GRV,                                      UK_MINS, UK_PLUS, UK_SLSH, UK_ASTR, UK_PERC, _______,
      _______, _______, _______, UK_LBRC, UK_RBRC, UK_TILD,                                     _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, LT(NUMERIC,UK_EQL), UK_SCLN,  UK_COLN,  LT(NUMERIC,KC_EQL), _______, _______, _______
    ),
/*
 * Numeric layer
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────╮                                                 ╭──────┬──────┬──────┬──────┬──────┬────────╮
 * │Unicode │  F1  │ F2   │ F3   │ F4   │ F5   │                                                 │ F6   │ F7   │ F8   │ F9   │ F10  │  F11   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                                                 ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │   0    │   1  │  2   │  3   │  4   │  5   │                                                 │  6   │  7   │  8   │  9   │  0   │  F12   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────╮                     ╭──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ BTN1 │ BTN3 │ BTN2 │      │      │      │                     │      │      │      │      │      │      │      │        │
 * ╰────────┴──────┴──────┼──────┼──────┼──────┤      │      │                     │      │      ├──────┼──────┼──────┼──────┴──────┴────────╯
 *                        │      │      │      │      │      │                     │      │      │      │      │      │
 *                        │      │      │      │      │      │                     │      │      │      │      │      │
 *                        ╰──────┴──────┴──────┴──────┴──────╯                     ╰──────┴──────┴──────┴──────┴──────╯
 */
    [NUMERIC] = LAYOUT_malcocer(
      RCS(KC_U), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
      _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,                                     _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Media layer
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────╮                                                 ╭──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │ Mute │MicMut│      │                                                 │ Home │  7   │  8   │  9   │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                                                 ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ Prev │ Play │ Next │      │                                                 │ End  │  4   │  5   │  6   │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────╮                     ╭──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Reset  │      │      │      │      │      │      │      │                     │      │      │ App  │  1   │  2   │  3   │      │        │
 * ╰────────┴──────┴──────┼──────┼──────┼──────┤      │      │                     │      │      ├──────┼──────┼──────┼──────┴──────┴────────╯
 *                        │      │      │      │      │      │                     │      │      │      │      │      │
 *                        │      │      │      │      │      │                     │      │      │  0   │  .   │      │
 *                        ╰──────┴──────┴──────┴──────┴──────╯                     ╰──────┴──────┴──────┴──────┴──────╯
 */
    [MEDIA] = LAYOUT_malcocer(
      _______, _______, _______, KC_MUTE, KC_F20,  _______,                                 KC_HOME, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                 KC_END,  KC_KP_4, KC_KP_5, KC_KP_6, _______, _______,
      RESET,   _______, _______, _______, _______, _______,                                 KC_APP,  KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_PDOT, _______
    ),
// /*
//  * Layer template
//  *
//  * ╭────────┬──────┬──────┬──────┬──────┬──────╮                                                 ╭──────┬──────┬──────┬──────┬──────┬────────╮
//  * │        │      │      │      │      │      │                                                 │      │      │      │      │      │        │
//  * ├────────┼──────┼──────┼──────┼──────┼──────┤                                                 ├──────┼──────┼──────┼──────┼──────┼────────┤
//  * │        │      │      │      │      │      │                                                 │      │      │      │      │      │        │
//  * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────╮                     ╭──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
//  * │        │      │      │      │      │      │      │      │                     │      │      │      │      │      │      │      │        │
//  * ╰────────┴──────┴──────┼──────┼──────┼──────┤      │      │                     │      │      ├──────┼──────┼──────┼──────┴──────┴────────╯
//  *                        │      │      │      │      │      │                     │      │      │      │      │      │
//  *                        │      │      │      │      │      │                     │      │      │      │      │      │
//  *                        ╰──────┴──────┴──────┴──────┴──────╯                     ╰──────┴──────┴──────┴──────┴──────╯
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, SYMBOL, NUMERIC, MEDIA);
}



/* OLED display ***************************************************************/
#ifdef OLED_ENABLE
static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case ALPHA:
            oled_write_P(PSTR("Alpha\n"), false);
            break;
        case SYMBOL:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case NUMERIC:
            oled_write_P(PSTR("Numeric\n"), false);
            break;
        case MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_left()) render_status();
    return false;
}
#endif //OLED_ENABLE



/* Encoders *******************************************************************/
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    // Left encoder
    if (index == 0) {
        switch (biton32(layer_state)) {
            case NUMERIC:
                // Mouse wheel
                if (clockwise) { tap_code(KC_WH_R); }
                else { tap_code(KC_WH_L); }
            case SYMBOL:
                // Left/Right
                if (clockwise) { tap_code(KC_RIGHT); }
                else { tap_code(KC_LEFT); }
                break;
            case MEDIA:
                // Brightness
                if (clockwise) { tap_code(KC_BRIU); }
                else { tap_code(KC_BRID); }
                break;
            case ALPHA:
            default:
                // Tab
                if (clockwise) { tap_code(KC_TAB); }
                else { tap_code16(LSFT(KC_TAB)); }
                break;
        }

    // Right encoder
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case NUMERIC:
                // Mouse wheel
                if (clockwise) { tap_code(KC_WH_D); }
                else { tap_code(KC_WH_U); }
                break;
            case SYMBOL:
                // Up/down
                if (clockwise) { tap_code(KC_DOWN); }
                else { tap_code(KC_UP); }
                break;
            case MEDIA:
                // Volume
                if (clockwise) { tap_code(KC_VOLU); }
                else { tap_code(KC_VOLD); }
                break;
            case ALPHA:
            default:
                // Page up/Page down
                if (clockwise) { tap_code(KC_PGDN); }
                else { tap_code(KC_PGUP); }
                break;
        }

    }
    return false;

}
#endif //ENCODER_ENABLE



/* Trackball ******************************************************************/
#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_user(void) {
    pimoroni_trackball_set_rgbw(0x00, 0x00, 0x00, 0x40);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    switch (biton32(layer_state)) {
        case NUMERIC:
            // Slower
            mouse_report.x = mouse_report.x / 2;
            mouse_report.y = mouse_report.y / 2;
            break;
        case SYMBOL:
            // Faster
            mouse_report.x = mouse_report.x * 2;
            mouse_report.y = mouse_report.y * 2;
            break;
        case ALPHA:
        default:
            break;
    }
    return mouse_report;
}

bool led_update_user(led_t led_state){
      if (led_state.caps_lock) pimoroni_trackball_set_rgbw(0x40, 0x00, 0x00, 0x00);
      else pimoroni_trackball_set_rgbw(0x00, 0x00, 0x00, 0x40);
      return false;
}
#endif //POINTING_DEVICE_ENABLE
