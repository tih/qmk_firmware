#pragma once
#include "quantum.h"

#define FOREACH_UNICODE(M) \
    M(UALP,  0x0391) /* Α */ \
    M(UBET,  0x0392) /* Β */ \
    M(UGAM,  0x0393) /* Γ */ \
    M(UDEL,  0x0394) /* Δ */ \
    M(UEPS,  0x0395) /* Ε */ \
    M(UZET,  0x0396) /* Ζ */ \
    M(UETA,  0x0397) /* Η */ \
    M(UTHE,  0x0398) /* Θ */ \
    M(UIOT,  0x0399) /* Ι */ \
    M(UKAP,  0x039A) /* Κ */ \
    M(ULAM,  0x039B) /* Λ */ \
    M(UMU,   0x039C) /* Μ */ \
    M(UNU,   0x039D) /* Ν */ \
    M(UXI,   0x039E) /* Ξ */ \
    M(UOMI,  0x039F) /* Ο */ \
    M(UPI,   0x03A0) /* Π */ \
    M(URHO,  0x03A1) /* Ρ */ \
    M(USIG,  0x03A3) /* Σ */ \
    M(UTAU,  0x03A4) /* Τ */ \
    M(UUPS,  0x03A5) /* Υ */ \
    M(UPHI,  0x03A6) /* Φ */ \
    M(UCHI,  0x03A7) /* Χ */ \
    M(UPSI,  0x03A8) /* Ψ */ \
    M(UOME,  0x03A9) /* Ω */ \
    M(UALPT, 0x0386) /* Ά */ \
    M(UEPST, 0x0388) /* Έ */ \
    M(UETAT, 0x0389) /* Ή */ \
    M(UIOTT, 0x038A) /* Ί */ \
    M(UOMIT, 0x038C) /* Ό */ \
    M(UUPST, 0x038E) /* Ύ */ \
    M(UOMET, 0x038F) /* Ώ */ \
    M(UIOTD, 0x03AA) /* Ϊ */ \
    M(UUPSD, 0x03AB) /* Ϋ */ \
    M(LALP,  0x03B1) /* α */ \
    M(LBET,  0x03B2) /* β */ \
    M(LGAM,  0x03B3) /* γ */ \
    M(LDEL,  0x03B4) /* δ */ \
    M(LEPS,  0x03B5) /* ε */ \
    M(LZET,  0x03B6) /* ζ */ \
    M(LETA,  0x03B7) /* η */ \
    M(LTHE,  0x03B8) /* θ */ \
    M(LIOT,  0x03B9) /* ι */ \
    M(LKAP,  0x03BA) /* κ */ \
    M(LLAM,  0x03BB) /* λ */ \
    M(LMU,   0x03BC) /* μ */ \
    M(LNU,   0x03BD) /* ν */ \
    M(LXI,   0x03BE) /* ξ */ \
    M(LOMI,  0x03BF) /* ο */ \
    M(LPI,   0x03C0) /* π */ \
    M(LRHO,  0x03C1) /* ρ */ \
    M(LFSIG, 0x03C2) /* ς */ \
    M(LSIG,  0x03C3) /* σ */ \
    M(LTAU,  0x03C4) /* τ */ \
    M(LUPS,  0x03C5) /* υ */ \
    M(LPHI,  0x03C6) /* φ */ \
    M(LCHI,  0x03C7) /* χ */ \
    M(LPSI,  0x03C8) /* ψ */ \
    M(LOME,  0x03C9) /* ω */ \
    M(LALPT, 0x03AC) /* ά */ \
    M(LEPST, 0x03AD) /* έ */ \
    M(LETAT, 0x03AE) /* ή */ \
    M(LIOTT, 0x03AF) /* ί */ \
    M(LOMIT, 0x03CC) /* ό */ \
    M(LUPST, 0x03CD) /* ύ */ \
    M(LOMET, 0x03CE) /* ώ */ \
    M(LIOTD, 0x03CA) /* ϊ */ \
    M(LUPSD, 0x03CB) /* ϋ */ \
    M(UAH,   0x0410) /* А */ \
    M(UBE,   0x0411) /* Б */ \
    M(UVE,   0x0412) /* В */ \
    M(UGHE,  0x0413) /* Г */ \
    M(UDE,   0x0414) /* Д */ \
    M(UIE,   0x0415) /* Е */ \
    M(UIO,   0x0401) /* Ё */ \
    M(UZHE,  0x0416) /* Ж */ \
    M(UZE,   0x0417) /* З */ \
    M(UIH,   0x0418) /* И */ \
    M(USIH,  0x0419) /* Й */ \
    M(UKA,   0x041A) /* К */ \
    M(UEL,   0x041B) /* Л */ \
    M(UEM,   0x041C) /* М */ \
    M(UEN,   0x041D) /* Н */ \
    M(UOH,   0x041E) /* О */ \
    M(UPE,   0x041F) /* П */ \
    M(UER,   0x0420) /* Р */ \
    M(UES,   0x0421) /* С */ \
    M(UTE,   0x0422) /* Т */ \
    M(UUU,   0x0423) /* У */ \
    M(UEF,   0x0424) /* Ф */ \
    M(UHA,   0x0425) /* Х */ \
    M(UTSE,  0x0426) /* Ц */ \
    M(UCHE,  0x0427) /* Ч */ \
    M(USHA,  0x0428) /* Ш */ \
    M(USCHA, 0x0429) /* Щ */ \
    M(UHARD, 0x042A) /* Ъ */ \
    M(UYERU, 0x042B) /* Ы */ \
    M(USOFT, 0x042C) /* Ь */ \
    M(UEH,   0x042D) /* Э */ \
    M(UYU,   0x042E) /* Ю */ \
    M(UYA,   0x042F) /* Я */ \
    M(LAH,   0x0430) /* а */ \
    M(LBE,   0x0431) /* б */ \
    M(LVE,   0x0432) /* в */ \
    M(LGHE,  0x0433) /* г */ \
    M(LDE,   0x0434) /* д */ \
    M(LIE,   0x0435) /* е */ \
    M(LIO,   0x0451) /* ё */ \
    M(LZHE,  0x0436) /* ж */ \
    M(LZE,   0x0437) /* з */ \
    M(LIH,   0x0438) /* и */ \
    M(LSIH,  0x0439) /* й */ \
    M(LKA,   0x043A) /* к */ \
    M(LEL,   0x043B) /* л */ \
    M(LEM,   0x043C) /* м */ \
    M(LEN,   0x043D) /* н */ \
    M(LOH,   0x043E) /* о */ \
    M(LPE,   0x043F) /* п */ \
    M(LER,   0x0440) /* р */ \
    M(LES,   0x0441) /* с */ \
    M(LTE,   0x0442) /* т */ \
    M(LUU,   0x0443) /* у */ \
    M(LEF,   0x0444) /* ф */ \
    M(LHA,   0x0445) /* х */ \
    M(LTSE,  0x0446) /* ц */ \
    M(LCHE,  0x0447) /* ч */ \
    M(LSHA,  0x0448) /* ш */ \
    M(LSCHA, 0x0449) /* щ */ \
    M(LHARD, 0x044A) /* ъ */ \
    M(LYERU, 0x044B) /* ы */ \
    M(LSOFT, 0x044C) /* ь */ \
    M(LEH,   0x044D) /* э */ \
    M(LYU,   0x044E) /* ю */ \
    M(LYA,   0x044F) /* я */

#define UC_KEYCODE(name, code)  name = UC(code),        // LALP = UC(0x03B1),

#define UCM_NAME(name, code)    UCM_ ## name,           // UCM_LALP,
#define UCM_ENTRY(name, code)   [UCM_ ## name] = code,  // [UCM_LALP] = 0x03B1,
#define UCM_KEYCODE(name, code) name = X(UCM_ ## name), // LALP = X(UCM_LALP)

#if defined(UNICODE_ENABLE)
enum unicode_keycodes {
    FOREACH_UNICODE(UC_KEYCODE)
};
#elif defined(UNICODEMAP_ENABLE)
enum unicode_names {
    FOREACH_UNICODE(UCM_NAME)
};

extern const uint32_t PROGMEM unicode_map[];

enum unicode_keycodes {
    FOREACH_UNICODE(UCM_KEYCODE)
};
#endif

#define ALPHA   XP(LALP, UALP)
#define BETA    XP(LBET, UBET)
#define GAMMA   XP(LGAM, UGAM)
#define DELTA   XP(LDEL, UDEL)
#define EPSILON XP(LEPS, UEPS)
#define ZETA    XP(LZET, UZET)
#define ETA     XP(LETA, UETA)
#define THETA   XP(LTHE, UTHE)
#define IOTA    XP(LIOT, UIOT)
#define KAPPA   XP(LKAP, UKAP)
#define LAMBDA  XP(LLAM, ULAM)
#define GKMU    XP(LMU,  UMU)
#define NU      XP(LNU,  UNU)
#define XI      XP(LXI,  UXI)
#define OMICRON XP(LOMI, UOMI)
#define PI      XP(LPI,  UPI)
#define RHO     XP(LRHO, URHO)
#define SIGMA   XP(LSIG, USIG)
#define FSIGMA  XP(LFSIG,USIG)
#define TAU     XP(LTAU, UTAU)
#define UPSILON XP(LUPS, UUPS)
#define PHI     XP(LPHI, UPHI)
#define CHI     XP(LCHI, UCHI)
#define PSI     XP(LPSI, UPSI)
#define OMEGA   XP(LOME, UOME)

#define ALPHAT XP(LALPT, UALPT)
#define EPSILT XP(LEPST, UEPST)
#define ETAT   XP(LETAT, UETAT)
#define IOTAT  XP(LIOTT, UIOTT)
#define OMICRT XP(LOMIT, UOMIT)
#define UPSILT XP(LUPST, UUPST)
#define OMEGAT XP(LOMET, UOMET)
#define IOTAD  XP(LIOTD, UIOTD)
#define UPSILD XP(LUPSD, UUPSD)

#define AH   XP(LAH,   UAH)
#define BE   XP(LBE,   UBE)
#define VE   XP(LVE,   UVE)
#define GHE  XP(LGHE,  UGHE)
#define DE   XP(LDE,   UDE)
#define IE   XP(LIE,   UIE)
#define IO   XP(LIO,   UIO)
#define ZHE  XP(LZHE,  UZHE)
#define ZE   XP(LZE,   UZE)
#define IH   XP(LIH,   UIH)
#define SIH  XP(LSIH,  USIH)
#define KA   XP(LKA,   UKA)
#define EL   XP(LEL,   UEL)
#define EM   XP(LEM,   UEM)
#define EN   XP(LEN,   UEN)
#define OH   XP(LOH,   UOH)
#define PE   XP(LPE,   UPE)
#define ER   XP(LER,   UER)
#define ES   XP(LES,   UES)
#define TE   XP(LTE,   UTE)
#define UU   XP(LUU,   UUU)
#define EF   XP(LEF,   UEF)
#define HA   XP(LHA,   UHA)
#define TSE  XP(LTSE,  UTSE)
#define CHE  XP(LCHE,  UCHE)
#define SHA  XP(LSHA,  USHA)
#define SCHA XP(LSCHA, USCHA)
#define HARD XP(LHARD, UHARD)
#define YERU XP(LYERU, UYERU)
#define SOFT XP(LSOFT, USOFT)
#define EH   XP(LEH,   UEH)
#define YU   XP(LYU,   UYU)
#define YA   XP(LYA,   UYA)
