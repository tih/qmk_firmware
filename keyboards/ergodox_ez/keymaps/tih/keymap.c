#include QMK_KEYBOARD_H

#include "tih.h"

#define BASE 0 // default layer; US ASCII
#define CYRL 1 // Russian Cyrillic
#define GREK 2 // Greek
#define TONO 3 // Greek with Tonos
#define DIAL 4 // Greek with Dialytika
#define CONT 5 // Ctrl-key overlay for Unicode layers
#define SYMB 6 // symbols
#define MDIA 7 // media keys

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  GACC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Sym- |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| bols |           | Media|------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;/Med.|' / GUI |
 * |--------+------+------+------+------+------| Cyr. |           | Grk. |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  |Grv/Sym|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~Symb  |
 *  `-----------------------------------'                                       `------------------------------------'
 *                                        ,--------------.     ,--------------.
 *                                        |  App  | LGui |     | Alt  |Ctl/Esc|
 *                                 ,------|-------|------|     |------+-------+------.
 *                                 |      |       | Home |     | PgUp |       |      |
 *                                 | Enter|  Tab  |------|     |------| Back- |Space |
 *                                 |      |       | End  |     | PgDn | space |      |
 *                                 `---------------------'     `---------------------'
 */

[BASE] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,    KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,
  KC_TAB,          KC_Q,    KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),
  KC_LCTL,         KC_A,    KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,    KC_X,          KC_C,    KC_V,    KC_B,    TG(CYRL),
  LT(SYMB,KC_GRV), KC_QUOT, LALT(KC_LSFT), KC_LEFT, KC_RGHT,
                                                       ALT_T(KC_APP), KC_LGUI,
                                                                      KC_HOME,
                                                      KC_ENT, KC_TAB, KC_END,
  // right hand
  KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_MINS,
  TG(MDIA),     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
                KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  TG(GREK),     KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
                         KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,           TT(SYMB),
  KC_LALT, CTL_T(KC_ESC),
  KC_PGUP,
  KC_PGDN, KC_BSPC, KC_SPC
),

/* Cyrillic:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Я  |   В  |   Е  |   Р  |   Т  |      |           |      |   Ы  |   У  |   И  |   О  |   П  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Ctl  |   А  |   С  |   Д  |   Ф  |   Г  |------|           |------|   Ч  |   Й  |   К  |   Л  |      |        |
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
  _______,           _______, _______, _______, _______, _______, _______,
  _______,           YA,      VE,      IE,      ER,      TE,      _______,
  LM(CONT,MOD_LCTL), AH,      ES,      DE,      EF,      GHE,
  _______,           ZE,      HA,      TSE,     ZHE,     BE,      _______,
  _______,           _______, YU,      HARD,    SOFT,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, YERU,    UU,      IH,      OH,      PE,      _______,
           CHE,     SIH,     KA,      EL,      _______, _______,
  _______, EN,      EM,      _______, _______, _______, _______,
                    SHA,     SCHA,    EH,      IO,      _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Greek:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ;  |   ς  |   Ε  |   Ρ  |   Τ  |      |           |      |   Υ  |   Θ  |   Ι  |   Ο  |   Π  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Ctl  |   Α  |   Σ  |   Δ  |   Φ  |   Γ  |------|           |------|   Η  |   Ξ  |   Κ  |   Λ  | acc. |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Ζ  |   Χ  |   Ψ  |   Ω  |   Β  |      |           |      |   Ν  |   Μ  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
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
  _______,           _______, _______, _______, _______, _______, _______,
  _______,           KC_SCLN, FSIGMA,  EPSILON, RHO,     TAU,     _______,
  LM(CONT,MOD_LCTL), ALPHA,   SIGMA,   DELTA,   PHI,     GAMMA,
  _______,           ZETA,    CHI,     PSI,     OMEGA,   BETA,    _______,
  _______,           _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, UPSILON, THETA,   IOTA,    OMICRON, PI,      _______,
           ETA,     XI,      KAPPA,   LAMBDA,  GACC,    _______,
  _______, NU,      GKMU,    _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

[TONO] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, OMEGAT,  _______, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, UPSILT,  _______, IOTAT,   OMICRT,  _______, _______,
           ETAT,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

[DIAL] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, UPSILD,  _______, IOTAD,   _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Ctrl-key overlay for use with Unicode maps:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[CONT] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
  _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
           KC_H,    KC_J,    KC_K,    KC_L,    _______, _______,
  _______, KC_N,    KC_M,    _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Symbol Layer:
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
 *                                         ,-------------.       ,-------------.
 *                                         |Animat|      |       |Toggle|Solid |
 *                                  ,------|------|------|       |------+------+------.
 *                                  |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                  |ness- |ness+ |------|       |------|      |      |
 *                                  |      |      |      |       |      |      |      |
 *                                  `--------------------'       `--------------------'
 */

[SYMB] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
  EPRM,    _______, _______, _______, _______,
                                               RGB_MOD, _______,
                                                        _______,
                                      RGB_VAD, RGB_VAI, _______,
  // right hand
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, KC_DOT,  KC_0,    KC_EQL,  _______,
  RGB_TOG, _______,
  _______,
  _______, RGB_HUD, RGB_HUI
),

/* Media and mouse keys:
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
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_BTN1, KC_BTN2,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, KC_MPLY,
  _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                    KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
  _______, _______,
  _______,
  _______, _______, KC_WBAK
)

};

void matrix_init_user(void) {

  set_unicode_input_mode(UC_LNX);
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
    case GACC:
      if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) ||
	  (keyboard_report->mods & MOD_BIT (KC_RSFT))) {
	set_oneshot_layer(DIAL, ONESHOT_START);
      } else {
	set_oneshot_layer(TONO, ONESHOT_START);
      }
      return false;
    }
  } else {
    switch (keycode) {
    case GACC:
    case KC_LSFT:
    case KC_RSFT:
      clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;
    default:
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        break;
      case 1:
        ergodox_right_led_3_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
	ergodox_right_led_3_on();
        ergodox_right_led_2_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        break;
      case 5:
        ergodox_right_led_3_on();
        ergodox_right_led_1_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_1_on();
        break;
      case 7:
        ergodox_right_led_3_on();
        ergodox_right_led_2_on();
        ergodox_right_led_1_on();
        break;
      default:
        break;
    }

  return state;
};
