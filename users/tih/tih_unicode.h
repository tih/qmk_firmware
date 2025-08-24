#if defined(UNICODEMAP_ENABLE)

#include "quantum.h"

#define FOREACH_UNICODE(M)			\
  M(UAE,   0x00C6) /* Æ */			\
  M(UOE,   0x00D8) /* Ø */			\
  M(UAA,   0x00C5) /* Å */			\
  M(LAE,   0x00E6) /* æ */			\
  M(LOE,   0x00F8) /* ø */			\
  M(LAA,   0x00E5) /* å */			\
  M(UAH,   0x0410) /* А */			\
  M(UBE,   0x0411) /* Б */			\
  M(UVE,   0x0412) /* В */			\
  M(UGHE,  0x0413) /* Г */			\
  M(UDE,   0x0414) /* Д */			\
  M(UIE,   0x0415) /* Е */			\
  M(UIO,   0x0401) /* Ё */			\
  M(UZHE,  0x0416) /* Ж */			\
  M(UZE,   0x0417) /* З */			\
  M(UIH,   0x0418) /* И */			\
  M(USIH,  0x0419) /* Й */			\
  M(UKA,   0x041A) /* К */			\
  M(UEL,   0x041B) /* Л */			\
  M(UEM,   0x041C) /* М */			\
  M(UEN,   0x041D) /* Н */			\
  M(UOH,   0x041E) /* О */			\
  M(UPE,   0x041F) /* П */			\
  M(UER,   0x0420) /* Р */			\
  M(UES,   0x0421) /* С */			\
  M(UTE,   0x0422) /* Т */			\
  M(UUU,   0x0423) /* У */			\
  M(UEF,   0x0424) /* Ф */			\
  M(UHA,   0x0425) /* Х */			\
  M(UTSE,  0x0426) /* Ц */			\
  M(UCHE,  0x0427) /* Ч */			\
  M(USHA,  0x0428) /* Ш */			\
  M(USCHA, 0x0429) /* Щ */			\
  M(UHARD, 0x042A) /* Ъ */			\
  M(UYERU, 0x042B) /* Ы */			\
  M(USOFT, 0x042C) /* Ь */			\
  M(UEH,   0x042D) /* Э */			\
  M(UYU,   0x042E) /* Ю */			\
  M(UYA,   0x042F) /* Я */			\
  M(LAH,   0x0430) /* а */			\
  M(LBE,   0x0431) /* б */			\
  M(LVE,   0x0432) /* в */			\
  M(LGHE,  0x0433) /* г */			\
  M(LDE,   0x0434) /* д */			\
  M(LIE,   0x0435) /* е */			\
  M(LIO,   0x0451) /* ё */			\
  M(LZHE,  0x0436) /* ж */			\
  M(LZE,   0x0437) /* з */			\
  M(LIH,   0x0438) /* и */			\
  M(LSIH,  0x0439) /* й */			\
  M(LKA,   0x043A) /* к */			\
  M(LEL,   0x043B) /* л */			\
  M(LEM,   0x043C) /* м */			\
  M(LEN,   0x043D) /* н */			\
  M(LOH,   0x043E) /* о */			\
  M(LPE,   0x043F) /* п */			\
  M(LER,   0x0440) /* р */			\
  M(LES,   0x0441) /* с */			\
  M(LTE,   0x0442) /* т */			\
  M(LUU,   0x0443) /* у */			\
  M(LEF,   0x0444) /* ф */			\
  M(LHA,   0x0445) /* х */			\
  M(LTSE,  0x0446) /* ц */			\
  M(LCHE,  0x0447) /* ч */			\
  M(LSHA,  0x0448) /* ш */			\
  M(LSCHA, 0x0449) /* щ */			\
  M(LHARD, 0x044A) /* ъ */			\
  M(LYERU, 0x044B) /* ы */			\
  M(LSOFT, 0x044C) /* ь */			\
  M(LEH,   0x044D) /* э */			\
  M(LYU,   0x044E) /* ю */			\
  M(LYA,   0x044F) /* я */			\
  M(UALP,  0x0391) /* Α */			\
  M(UBET,  0x0392) /* Β */			\
  M(UGAM,  0x0393) /* Γ */			\
  M(UDEL,  0x0394) /* Δ */			\
  M(UEPS,  0x0395) /* Ε */			\
  M(UZET,  0x0396) /* Ζ */			\
  M(UETA,  0x0397) /* Η */			\
  M(UTHE,  0x0398) /* Θ */			\
  M(UIOT,  0x0399) /* Ι */			\
  M(UKAP,  0x039A) /* Κ */			\
  M(ULAM,  0x039B) /* Λ */			\
  M(UMU,   0x039C) /* Μ */			\
  M(UNU,   0x039D) /* Ν */			\
  M(UXI,   0x039E) /* Ξ */			\
  M(UOMI,  0x039F) /* Ο */			\
  M(UPI,   0x03A0) /* Π */			\
  M(URHO,  0x03A1) /* Ρ */			\
  M(USIG,  0x03A3) /* Σ */			\
  M(UTAU,  0x03A4) /* Τ */			\
  M(UUPS,  0x03A5) /* Υ */			\
  M(UPHI,  0x03A6) /* Φ */			\
  M(UCHI,  0x03A7) /* Χ */			\
  M(UPSI,  0x03A8) /* Ψ */			\
  M(UOME,  0x03A9) /* Ω */			\
  M(LALP,  0x03B1) /* α */			\
  M(LBET,  0x03B2) /* β */			\
  M(LGAM,  0x03B3) /* γ */			\
  M(LDEL,  0x03B4) /* δ */			\
  M(LEPS,  0x03B5) /* ε */			\
  M(LZET,  0x03B6) /* ζ */			\
  M(LETA,  0x03B7) /* η */			\
  M(LTHE,  0x03B8) /* θ */			\
  M(LIOT,  0x03B9) /* ι */			\
  M(LKAP,  0x03BA) /* κ */			\
  M(LLAM,  0x03BB) /* λ */			\
  M(LMU,   0x03BC) /* μ */			\
  M(LNU,   0x03BD) /* ν */			\
  M(LXI,   0x03BE) /* ξ */			\
  M(LOMI,  0x03BF) /* ο */			\
  M(LPI,   0x03C0) /* π */			\
  M(LRHO,  0x03C1) /* ρ */			\
  M(LFSIG, 0x03C2) /* ς */			\
  M(LSIG,  0x03C3) /* σ */			\
  M(LTAU,  0x03C4) /* τ */			\
  M(LUPS,  0x03C5) /* υ */			\
  M(LPHI,  0x03C6) /* φ */			\
  M(LCHI,  0x03C7) /* χ */			\
  M(LPSI,  0x03C8) /* ψ */			\
  M(LOME,  0x03C9) /* ω */			\
  M(UALPT, 0x0386) /* Ά */			\
  M(UEPST, 0x0388) /* Έ */			\
  M(UETAT, 0x0389) /* Ή */			\
  M(UIOTT, 0x038A) /* Ί */			\
  M(UOMIT, 0x038C) /* Ό */			\
  M(UUPST, 0x038E) /* Ύ */			\
  M(UOMET, 0x038F) /* Ώ */			\
  M(UIOTD, 0x03AA) /* Ϊ */			\
  M(UUPSD, 0x03AB) /* Ϋ */			\
  M(LALPT, 0x03AC) /* ά */			\
  M(LEPST, 0x03AD) /* έ */			\
  M(LETAT, 0x03AE) /* ή */			\
  M(LIOTT, 0x03AF) /* ί */			\
  M(LOMIT, 0x03CC) /* ό */			\
  M(LUPST, 0x03CD) /* ύ */			\
  M(LOMET, 0x03CE) /* ώ */			\
  M(LIOTD, 0x03CA) /* ϊ */			\
  M(LUPSD, 0x03CB) /* ϋ */

#if 0
#define UCM_NAME(name, code)    UCM_ ## name,            // UCM_LALP,
#define UCM_ENTRY(name, code)   [UCM_ ## name] = code,   // [UCM_LALP] = 0x03B1,
#define UC_KEYCODE(name, code)  name = UC(code),         // LALP = UC(0x03B1),
#define UCM_NAMEVAL(name, code)    UCM_ ## name = code,  // UCM_LALP = 0x03B1,
#define UCM_KEYCODE(name, code) name = UM(UCM_ ## name), // LALP = UM(UCM_LALP)
#endif

#define UCM_NAME(name, code)    name,                    // LALP,
#define UCM_ENTRY(name, code)   [name] = code,           // [LALP] = 0x03B1,

enum unicode_names {
  FOREACH_UNICODE(UCM_NAME)
};

const uint32_t PROGMEM unicode_map[] = {
  FOREACH_UNICODE(UCM_ENTRY)
};

#define AELIG   UP(LAE,   UAE)
#define OSLASH  UP(LOE,   UOE)
#define ARING   UP(LAA,   UAA)

#define AH      UP(LAH,   UAH)
#define BE      UP(LBE,   UBE)
#define VE      UP(LVE,   UVE)
#define GHE     UP(LGHE,  UGHE)
#define DE      UP(LDE,   UDE)
#define IE      UP(LIE,   UIE)
#define IO      UP(LIO,   UIO)
#define ZHE     UP(LZHE,  UZHE)
#define ZE      UP(LZE,   UZE)
#define IH      UP(LIH,   UIH)
#define SIH     UP(LSIH,  USIH)
#define KA      UP(LKA,   UKA)
#define EL      UP(LEL,   UEL)
#define EM      UP(LEM,   UEM)
#define EN      UP(LEN,   UEN)
#define OH      UP(LOH,   UOH)
#define PE      UP(LPE,   UPE)
#define ER      UP(LER,   UER)
#define ES      UP(LES,   UES)
#define TE      UP(LTE,   UTE)
#define UU      UP(LUU,   UUU)
#define EF      UP(LEF,   UEF)
#define HA      UP(LHA,   UHA)
#define TSE     UP(LTSE,  UTSE)
#define CHE     UP(LCHE,  UCHE)
#define SHA     UP(LSHA,  USHA)
#define SCHA    UP(LSCHA, USCHA)
#define HARD    UP(LHARD, UHARD)
#define YERU    UP(LYERU, UYERU)
#define SOFT    UP(LSOFT, USOFT)
#define EH      UP(LEH,   UEH)
#define YU      UP(LYU,   UYU)
#define YA      UP(LYA,   UYA)

#define ALPHA   UP(LALP,  UALP)
#define BETA    UP(LBET,  UBET)
#define GAMMA   UP(LGAM,  UGAM)
#define DELTA   UP(LDEL,  UDEL)
#define EPSILON UP(LEPS,  UEPS)
#define ZETA    UP(LZET,  UZET)
#define ETA     UP(LETA,  UETA)
#define THETA   UP(LTHE,  UTHE)
#define IOTA    UP(LIOT,  UIOT)
#define KAPPA   UP(LKAP,  UKAP)
#define LAMBDA  UP(LLAM,  ULAM)
#define GKMU    UP(LMU,   UMU)
#define NU      UP(LNU,   UNU)
#define XI      UP(LXI,   UXI)
#define OMICRON UP(LOMI,  UOMI)
#define PI      UP(LPI,   UPI)
#define RHO     UP(LRHO,  URHO)
#define SIGMA   UP(LSIG,  USIG)
#define FSIGMA  UP(LFSIG, USIG)
#define TAU     UP(LTAU,  UTAU)
#define UPSILON UP(LUPS,  UUPS)
#define PHI     UP(LPHI,  UPHI)
#define CHI     UP(LCHI,  UCHI)
#define PSI     UP(LPSI,  UPSI)
#define OMEGA   UP(LOME,  UOME)

#if 0 /* some of these are > 127 */

#define ALPHAT  UP(LALPT, UALPT)
#define EPSILT  UP(LEPST, UEPST)
#define ETAT    UP(LETAT, UETAT)
#define IOTAT   UP(LIOTT, UIOTT)
#define OMICRT  UP(LOMIT, UOMIT)
#define UPSILT  UP(LUPST, UUPST)
#define OMEGAT  UP(LOMET, UOMET)

#define IOTAD   UP(LIOTD, UIOTD)
#define UPSILD  UP(LUPSD, UUPSD)

#else

char *greek_accents[] = {
  /* UALPT */ "Ά",
  /* LALPT */ "ά",
  /* UEPST */ "Έ",
  /* LEPST */ "έ",
  /* UETAT */ "Ή",
  /* LETAT */ "ή",
  /* UIOTT */ "Ί",
  /* LIOTT */ "ί",
  /* UOMIT */ "Ό",
  /* LOMIT */ "ό",
  /* UUPST */ "Ύ",
  /* LUPST */ "ύ",
  /* UOMET */ "Ώ",
  /* LOMET */ "ώ",
  /* UIOTD */ "Ϊ",
  /* LIOTD */ "ϊ",
  /* UUPSD */ "Ϋ",
  /* LUPSD */ "ϋ"
};

#endif /* 0 */

#endif
