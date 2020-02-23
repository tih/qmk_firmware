#include QMK_KEYBOARD_H

#include "tih.h"

#define BASE 0 // default layer; US ASCII
#define CYRL 1 // Russian Cyrillic
#define GREK 2 // Greek
#define SYMB 3 // symbols
#define MDIA 4 // media keys

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L3  |           |  L3  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |A/Ctrl|   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L4|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L3|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L3  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | App  | LGui |       | Alt  |Ctl/Esc|
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 | Space|Back- |------|       |------|  Tab  |Enter |
 *                                 |      |space | End  |       | PgDn |       |      |
 *                                 `--------------------'       `---------------------'
 */

[BASE] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,
  KC_DEL,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),
  KC_LCTL,         CTL_T(KC_A), KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),
  LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,
                                                           ALT_T(KC_APP), KC_LGUI,
                                                                          KC_HOME,
                                                         KC_SPC, KC_BSPC, KC_END,
  // right hand
  KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS,
  TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
                KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
                         KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,           TT(SYMB),
  KC_LALT, CTL_T(KC_ESC),
  KC_PGUP,
  KC_PGDN, KC_TAB, KC_ENT
),

/* Keymap 1: Cyrillic
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Я  |   В  |   Е  |   Р  |   Т  |      |           |      |   Ы  |   У  |   И  |   О  |   П  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   А  |   С  |   Д  |   Ф  |   Г  |------|           |------|   Ч  |   Й  |   К  |   Л  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   З  |   Х  |   Ц  |   Ж  |   Б  |      |           |      |   Н  |   М  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |   Ю  |   Ъ  |   Ь  |                                       |   Ш  |   Щ  |   Э  |   Ё  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[CYRL] = LAYOUT_ergodox(
  // left hand
  _______, _______,   _______, _______, _______, _______, _______,
  _______, YA,        VE,      IE,      ER,      TE,      _______,
  _______, CTL_T(AH), ES,      DE,      EF,      GHE,
  _______, ZE,        HA,      TSE,     ZHE,     BE,      _______,
  _______, _______,   YU,      HARD,    SOFT,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
  // right hand
  _______, _______,   _______, _______, _______, _______, _______,
  _______, YERU,      UU,      IH,      OH,      PE,      _______,
           CHE,       SIH,     KA,      EL,      _______, _______,
  _______, EN,        EM,      _______, _______, _______, _______,
                      SHA,     SCHA,    EH,      IO,       _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Keymap 2: Greek
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L3  |           |  L3  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L4|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L3|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L3  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[GREK] = LAYOUT_ergodox(
  // left hand
  _______, _______,   _______, _______, _______, _______, _______,
  _______, YA,        VE,      IE,      ER,      TE,      _______,
  _______, CTL_T(AH), ES,      DE,      EF,      GHE,
  _______, ZE,        HA,      TSE,     ZHE,     BE,      _______,
  _______, _______,   YU,      HARD,    SOFT,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
  // right hand
  _______, _______,   _______, _______, _______, _______, _______,
  _______, YERU,      UU,      IH,      OH,      PE,      _______,
           CHE,       SIH,     KA,      EL,      _______, _______,
  _______, EN,        EM,      _______, _______, _______, _______,
                      SHA,     SCHA,    EH,      IO,       _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Keymap 3: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               RGB_MOD, KC_TRNS,
                                                        KC_TRNS,
                                      RGB_VAD, RGB_VAI, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  RGB_TOG, KC_TRNS,
  KC_TRNS,
  KC_TRNS, RGB_HUD, RGB_HUI
),

/* Keymap 4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
  }
  return true;
}

void matrix_init_user(void) {

  set_unicode_input_mode(UC_LNX);
};

layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
	ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 4:
        ergodox_right_led_3_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
