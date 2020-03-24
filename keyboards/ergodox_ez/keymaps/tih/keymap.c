#include QMK_KEYBOARD_H

#include "tih.h"

enum layer_names {
  BASE = 0, // Default layer; US ASCII
#ifdef UNICODEMAP_ENABLE
  CYRL,     // Russian Cyrillic
  GREK,     // Greek
  TONO,     // Greek with Tonos
  DIAL,     // Greek with Dialytika
#endif
  NAVI,     // Navigation keys
  MODS      // Modifier key overlay
};

#ifndef UNICODEMAP_ENABLE
#define CYRL NAVI
#define GREK NAVI
#endif

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
#ifdef UNICODEMAP_ENABLE
  GACC,
  ALPT,
  EPST,
  ETAT,
  IOTT,
  OMIT,
  UPST,
  OMET,
  IOTD,
  UPSD,
#endif
  DIGS
};

#define MOD_CTL LM(MODS,MOD_LCTL)
#define MOD_ALT LM(MODS,MOD_LALT)
#define MOD_GUI LM(MODS,MOD_LGUI)

#define SUP_LEFT LGUI(KC_LEFT)
#define SUP_RGHT LGUI(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | Meta |           | Comp |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Cyr. |           | Grk. |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   | A/Ct | S/Sh | D/Al | F/Su |   G  |------|           |------|   H  | J/Su | K/Al | L/Sh | ;/Ct | '/Meta |
 * |--------+------+------+------+------+------| Sup- |           | Sup- |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | left |           | rght |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  | Navi  | Super| Alt  |   `  |   =  |                                       |   [  |   ]  |  Alt | Super| Navi  |
 *  `-----------------------------------'                                       `-----------------------------------'
 *                                        ,--------------.     ,--------------.
 *                                        |   <-  |  ->  |     |   V  |   ^   |
 *                                 ,------|-------|------|     |------+-------+------.
 *                                 |      |       | Home |     | PgUp |       |      |
 *                                 | Back-|  Del  |------|     |------| Enter |Space |
 *                                 | space|       | End  |     | PgDn |       |      |
 *                                 `---------------------'     `---------------------'
 */

[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,   KC_1,         KC_2,         KC_3,         KC_4,           KC_5, KC_ALGR,
  KC_TAB,   KC_Q,         KC_W,         KC_E,         KC_R,           KC_T, TG(CYRL),
  KC_LCTL,  LCTL_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F),   KC_G,
  KC_LSFT,  KC_Z,         KC_X,         KC_C,         KC_V,           KC_B, SUP_LEFT,
  TT(NAVI), KC_LGUI,      KC_LALT,      KC_GRV,       KC_EQL,
                                                                   KC_LEFT, KC_RIGHT,
                                                                            KC_HOME,
                                                           KC_BSPC, KC_DEL, KC_END,
  // right hand
  KC_RGUI,  KC_6, KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,
  TG(GREK), KC_Y, KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
            KC_H, LGUI_T(KC_J), LALT_T(KC_K), LSFT_T(KC_L), LCTL_T(KC_SCLN), ALGR_T(KC_QUOT),
  SUP_RGHT, KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
                  KC_LBRC,      KC_RBRC,      KC_LALT,      KC_LGUI,         TT(NAVI),
  KC_DOWN, KC_UP,
  KC_PGUP,
  KC_PGDN, KC_ENT, KC_SPC
),

#ifdef UNICODEMAP_ENABLE

/* Cyrillic:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    Ю   |   Я  |   В  |   Е  |   Р  |   Т  |      |           |      |   Ы  |   У  |   И  |   О  |   П  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Ctl  |   А  |   С  |   Д  |   Ф  |   Г  |------|           |------|   Ч  |   Й  |   К  |   Л  |   Э  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   З  |   Х  |   Ц  |   Ж  |   Б  |      |           |      |   Н  |   М  |      |      |   Ё  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | Super|  Alt |   Ъ  |   Ь  |                                       |   Ш  |   Щ  | Alt  | Super|      |
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
  _______, _______, _______, _______, _______, _______, _______,
  YU,      YA,      VE,      IE,      ER,      TE,      _______,
  MOD_CTL, AH,      ES,      DE,      EF,      GHE,
  _______, ZE,      HA,      TSE,     ZHE,     BE,      _______,
  _______, MOD_GUI, MOD_ALT, HARD,    SOFT,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, YERU,    UU,      IH,      OH,      PE,      _______,
           CHE,     SIH,     KA,      EL,      EH,      _______,
  _______, EN,      EM,      _______, _______, IO,      _______,
                    SHA,     SCHA,    MOD_ALT, MOD_GUI, _______,
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
 *   |      | Super| Alt  |      |      |                                       |      |      | Alt  | Super|      |
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
  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_SCLN, FSIGMA,  EPSILON, RHO,     TAU,     _______,
  MOD_CTL, ALPHA,   SIGMA,   DELTA,   PHI,     GAMMA,
  _______, ZETA,    CHI,     PSI,     OMEGA,   BETA,    _______,
  _______, MOD_GUI, MOD_ALT, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, UPSILON, THETA,   IOTA,    OMICRON, PI,      _______,
           ETA,     XI,      KAPPA,   LAMBDA,  GACC,    _______,
  _______, NU,      GKMU,    _______, _______, _______, _______,
                    _______, _______, MOD_ALT, MOD_GUI, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

[TONO] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, EPST,    _______, _______, _______,
  _______, ALPT,    _______, _______, _______, _______,
  _______, _______, _______, _______, OMET,    _______, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                     _______,  _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, UPST,    _______, IOTT,    OMIT,    _______, _______,
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
  _______, UPSD,    _______, IOTD,    _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

#endif

/* Navigation layer:
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |  F1  |  F2  |  F3  |  F4  |  F5  |Reset |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  F12   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    Ctl  | Super| Rclk | Mclk | Lclk |      |------|           |------|      |MsLeft|MsDown| MsUp |MsRght|        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | Home | PgDn | PgUp | End  |      |      |           |      |      | Left | Down |  Up  | Rght |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       | Super|  Alt |      |      |                                       |      |      |  Alt | Super|      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         |      |      |       |      |      |
 *                                  ,------|------|------|       |------+------+------.
 *                                  |      |      |      |       |      |      |      |
 *                                  | Back | Fwd  |------|       |------|      |Reload|
 *                                  |      |      |      |       |      |      |      |
 *                                  `--------------------'       `--------------------'
 */

[NAVI] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RESET,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______,
  MOD_CTL, KC_LGUI, KC_BTN2, KC_BTN3, KC_BTN1, _______,
  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  _______, MOD_GUI, MOD_ALT, _______, _______,
                                               _______, _______, 
                                                        _______,
                                      KC_BTN4, KC_BTN5, _______,
  // right hand
  DIGS,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
           _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                    _______, _______, MOD_ALT, MOD_GUI, _______,
  _______, _______,
  _______,
  _______, _______, C(KC_R)
),

/* Modifier key overlay:
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

[MODS] = LAYOUT_ergodox(
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
)

};

#ifdef UNICODEMAP_ENABLE
void matrix_init_user(void) {

  set_unicode_input_mode(UC_LNX);
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed) {
    switch (keycode) {
    case VRSN:
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      return false;
    case DIGS:
      SEND_STRING ("12345");
      return false;
#ifdef UNICODEMAP_ENABLE
    case GACC:
      if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
	set_oneshot_layer(DIAL, ONESHOT_START);
      } else {
	set_oneshot_layer(TONO, ONESHOT_START);
      }
      return false;
    case ALPT:
    case ETAT:
    case IOTT:
    case OMIT:
    case UPST:
    case OMET:
    case IOTD:
    case UPSD:
      if (keyboard_report->mods & MOD_BIT(KC_LSFT) ||
	  keyboard_report->mods & MOD_BIT(KC_RSFT))
	send_unicode_hex_string(greek_accents[(keycode-ALPT)*2]);
      else
	send_unicode_hex_string(greek_accents[(keycode-ALPT)*2+1]);
      return false;
#endif
    }
  } else {
#ifdef UNICODEMAP_ENABLE
    switch (keycode) {
    case GACC:
      clear_oneshot_layer_state(ONESHOT_PRESSED);
      return false;
    case KC_LSFT:
    case KC_RSFT:
      break;
    case ALPT:
    case EPST:
    case ETAT:
    case IOTT:
    case OMIT:
    case UPST:
    case OMET:
    case IOTD:
    case UPSD:
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    default:
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
#endif
  }
  return true;
}

#ifdef UNICODEMAP_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {

  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);

  if ((layer == BASE) ||
      (layer == MODS))
    return state;

  if (layer == NAVI) {
    ergodox_right_led_1_on();
    return state;
  }

  if (layer_state_cmp(state, CYRL)) {
    ergodox_right_led_3_on();
  }
  if (layer_state_cmp(state, GREK)) {
    ergodox_right_led_3_off();
    ergodox_right_led_2_on();
  }
  if (layer_state_cmp(state, TONO) ||
      layer_state_cmp(state, DIAL))
    ergodox_right_led_1_on();

  return state;
};

#else

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

#endif
