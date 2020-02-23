#pragma once

#include "quantum.h"
#include "version.h"

#if defined(UNICODEMAP_ENABLE) || defined(UNICODE_ENABLE)
#    include "unicode.h"
#endif

#define LS(kc) MT(MOD_LSFT, KC_##kc)
#define LC(kc) MT(MOD_LCTL, KC_##kc)
#define LG(kc) MT(MOD_LGUI, KC_##kc)
#define LA(kc) MT(MOD_LALT, KC_##kc)
#define RS(kc) MT(MOD_RSFT, KC_##kc)
#define RC(kc) MT(MOD_RCTL, KC_##kc)
#define RG(kc) MT(MOD_RGUI, KC_##kc)
#define RA(kc) MT(MOD_RALT, KC_##kc)

#define NM(kc) LT(_NUMBER, KC_##kc)
#define SM(kc) LT(_SYMBOL, KC_##kc)
