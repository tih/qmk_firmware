UNICODE_ENABLE    = no # "yes" in ergodox_ez default keymap, blocking UNICODEMAP_ENABLE
UNICODEMAP_ENABLE = yes

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
  SRC += unicode.c
endif
