#include "unicode.h"

#ifdef UNICODEMAP_ENABLE
const uint32_t PROGMEM unicode_map[] = {
    FOREACH_UNICODE(UCM_ENTRY)
};

char *greek_accents[] = {
  /* UALPT */ "0386", /* Ά */
  /* LALPT */ "03AC", /* ά */
  /* UEPST */ "0388", /* Έ */
  /* LEPST */ "03AD", /* έ */
  /* UETAT */ "0389", /* Ή */
  /* LETAT */ "03AE", /* ή */
  /* UIOTT */ "038A", /* Ί */
  /* LIOTT */ "03AF", /* ί */
  /* UOMIT */ "038C", /* Ό */
  /* LOMIT */ "03CC", /* ό */
  /* UUPST */ "038E", /* Ύ */
  /* LUPST */ "03CD", /* ύ */
  /* UOMET */ "038F", /* Ώ */
  /* LOMET */ "03CE", /* ώ */
  /* UIOTD */ "03AA", /* Ϊ */
  /* LIOTD */ "03CA", /* ϊ */
  /* UUPSD */ "03AB", /* Ϋ */
  /* LUPSD */ "03CB"  /* ϋ */
};

#endif
