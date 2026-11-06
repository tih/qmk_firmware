ifeq ($(KEYBOARD), ergodox_ez/base)
UNICODE_COMMON    = yes
UNICODE_ENABLE    = no # "yes" in ergodox_ez and keyboardio/atreus, blocking UNICODEMAP_ENABLE
UNICODEMAP_ENABLE = yes
endif
CAPS_WORD_ENABLE  = yes
