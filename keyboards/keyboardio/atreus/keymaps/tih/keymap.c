#include QMK_KEYBOARD_H

#include "tih.h"

enum layer_names {
  BASE = 0, // Default layer; US ASCII
  NUMS,     // Symbols and numerals
  NAVI,     // Navigation keys
  MODS      // Modifier key overlay
};

#define MOD_CTL LM(MODS,MOD_LCTL)
#define MOD_ALT LM(MODS,MOD_LALT)
#define MOD_GUI LM(MODS,MOD_LGUI)

#define SUP_LEFT LGUI(KC_LEFT)
#define SUP_RGHT LGUI(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                              KC_Y,          KC_U,         KC_I,         KC_O,         KC_P,
    LCTL_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), LT(NUMS,KC_G),                     LT(NUMS,KC_H), LGUI_T(KC_J), LALT_T(KC_K), LSFT_T(KC_L), LCTL_T(KC_SCLN),
    KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,          SUP_LEFT, SUP_RGHT, KC_N,          KC_M,         KC_COMM,      KC_DOT,       KC_SLSH ,
    KC_LGUI,      KC_LALT,      KC_GRV,       KC_EQL,       KC_BSPC,       KC_DEL,   KC_ENT,   KC_SPC,        KC_LBRC,      KC_RBRC,      KC_ALGR,      TG(NAVI)),

  [NUMS] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_ESC,  KC_CAPS, KC_GRV,  KC_EQL,  KC_TAB,  _______, _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

  [NAVI] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LGUI, KC_BTN2, KC_BTN3, KC_BTN1, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    MOD_GUI, MOD_ALT, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   _______),

    
  [MODS] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    _______,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};
