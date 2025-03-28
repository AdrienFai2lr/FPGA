/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC_pixelType l_struct_OC_pixelType;
typedef struct l_struct_OC__IO_FILE l_struct_OC__IO_FILE;

/* Structure contents */
struct l_struct_OC_pixelType {
  unsigned int field0;
  unsigned int field1;
  unsigned int field2;
};

struct l_struct_OC__IO_FILE {
  unsigned int field0;
   char *field1;
   char *field2;
   char *field3;
   char *field4;
   char *field5;
   char *field6;
   char *field7;
   char *field8;
   char *field9;
   char *field10;
   char *field11;
  l_struct_OC_pixelType *field12;
  l_struct_OC__IO_FILE *field13;
  unsigned int field14;
  unsigned int field15;
  unsigned long long field16;
  unsigned short field17;
  unsigned char field18;
   char field19[1];
   char *field20;
  unsigned long long field21;
  l_struct_OC_pixelType *field22;
  l_struct_OC_pixelType *field23;
  l_struct_OC__IO_FILE *field24;
   char *field25;
  unsigned long long field26;
  unsigned int field27;
   char field28[20];
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void traitCoul(l_struct_OC_pixelType *, l_struct_OC_pixelType *,  char *,  char *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str10[87] = "Pixel %d: Entr\xC3\xA9\x65[R:%d,G:%d,B:%d] -> Sortie[R:%d,G:%d,B:%d], D\xC3\xA9tection:%u, Valide:%u\n";
static  char aesl_internal__OC_str11[4] = "%i\n";
static  char aesl_internal_str2[6] = "ROUGE";
static  char aesl_internal_str3[5] = "VERT";
static  char aesl_internal__OC_str12[31] = "Couleur dominante d\xC3\xA9tect\xC3\xA9\x65: ";
static  char aesl_internal__OC_str16[12] = "AUTRE (%u)\n";
static  char aesl_internal__OC_str3[2] = "w";
static  char aesl_internal__OC_str2[63] = "/home/etudiants/master1/adrien.failler/FPGA/tp3/fichierRes.ppm";
static  char aesl_internal_str5[59] = "Aucune couleur dominante d\xC3\xA9tect\xC3\xA9\x65 (r\xC3\xA9sultat non valide)";
static  char aesl_internal_str[48] = "Erreur : Impossible d'ouvrir le fichier de test";
static  char aesl_internal_str1[53] = "Erreur : Impossible d'ouvrir le fichier de r\xC3\xA9sultat";
static  char aesl_internal__OC_str6[4] = "P3\n";
static  char aesl_internal__OC_str7[7] = "%d %d\n";
static  char aesl_internal__OC_str1[2] = "r";
static  char aesl_internal_str4[5] = "BLEU";
static  char aesl_internal__OC_str8[5] = "255\n";
static  char aesl_internal__OC_str9[3] = "%i";
static  char aesl_internal__OC_str[64] = "/home/etudiants/master1/adrien.failler/FPGA/tp3/fichierTest.ppm";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_r_count = 0;
  signed int llvm_cbe_r;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_g_count = 0;
  signed int llvm_cbe_g;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_b_count = 0;
  signed int llvm_cbe_b;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_pixIn_count = 0;
  l_struct_OC_pixelType llvm_cbe_pixIn;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_pixOut_count = 0;
  l_struct_OC_pixelType llvm_cbe_pixOut;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_resultats_count = 0;
   char llvm_cbe_resultats;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_valid_count = 0;
   char llvm_cbe_valid;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts1_count = 0;
  unsigned int llvm_cbe_puts1;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  signed int *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  signed int *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  signed int *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  signed int *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  signed int *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  signed int *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned int llvm_cbe_storemerge6;
  unsigned int llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned char llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned char llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned char llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned char llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts3_count = 0;
  unsigned int llvm_cbe_puts3;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts4_count = 0;
  unsigned int llvm_cbe_puts4;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts5_count = 0;
  unsigned int llvm_cbe_puts5;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned int llvm_cbe_tmp__43;
  unsigned int llvm_cbe_tmp__43__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call noalias %%struct._IO_FILE* @fopen(i8* getelementptr inbounds ([64 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__1 = (l_struct_OC__IO_FILE *)aesl_fopen(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call noalias %%struct._IO_FILE* @fopen(i8* getelementptr inbounds ([63 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str3, i64 0, i64 0)) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__2 = (l_struct_OC__IO_FILE *)aesl_fopen(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 63
#endif
])), ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
  if (((llvm_cbe_tmp__1) == (((l_struct_OC__IO_FILE *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__44;
  } else {
    goto llvm_cbe_tmp__45;
  }

llvm_cbe_tmp__44:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([48 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  llvm_cbe_tmp__43__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__46;

llvm_cbe_tmp__45:
  if (((llvm_cbe_tmp__2) == (((l_struct_OC__IO_FILE *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__47;
  } else {
    goto llvm_cbe_tmp__48;
  }

llvm_cbe_tmp__47:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts1 = call i32 @puts(i8* getelementptr inbounds ([53 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts1_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 53
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts1 = 0x%X",llvm_cbe_puts1);
}
  llvm_cbe_tmp__43__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__46;

llvm_cbe_tmp__48:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i64 @fwrite(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str6, i64 0, i64 0), i64 3, i64 1, %%struct._IO_FILE* %%2), !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  fwrite(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), 3ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",3ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i32 (%%struct._IO_FILE*, i8*, ...)* @fprintf(%%struct._IO_FILE* %%2, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 400, i32 268) nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_32_count);
  fprintf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__2, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), 400u, 268u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",400u);
printf("\nArgument  = 0x%X",268u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i64 @fwrite(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str8, i64 0, i64 0), i64 4, i64 1, %%struct._IO_FILE* %%2), !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_33_count);
  fwrite(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), 4ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",4ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 0, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__6 = (signed int *)(&llvm_cbe_pixIn.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 1, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__7 = (signed int *)(&llvm_cbe_pixIn.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 2, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__8 = (signed int *)(&llvm_cbe_pixIn.field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.pixelType* %%pixOut, i64 0, i32 0, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__9 = (signed int *)(&llvm_cbe_pixOut.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.pixelType* %%pixOut, i64 0, i32 1, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__10 = (signed int *)(&llvm_cbe_pixOut.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.pixelType* %%pixOut, i64 0, i32 2, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__11 = (signed int *)(&llvm_cbe_pixOut.field2);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i32 [ 0, %%8 ], [ %%42, %%18  for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned int )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i32 (%%struct._IO_FILE*, i8*, ...)* @__isoc99_fscanf(%%struct._IO_FILE* %%1, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str9, i64 0, i64 0), i32* %%r) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  __isoc99_fscanf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (signed int *)(&llvm_cbe_r));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = call i32 (%%struct._IO_FILE*, i8*, ...)* @__isoc99_fscanf(%%struct._IO_FILE* %%1, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str9, i64 0, i64 0), i32* %%g) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  __isoc99_fscanf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (signed int *)(&llvm_cbe_g));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i32 (%%struct._IO_FILE*, i8*, ...)* @__isoc99_fscanf(%%struct._IO_FILE* %%1, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str9, i64 0, i64 0), i32* %%b) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_47_count);
  __isoc99_fscanf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (signed int *)(&llvm_cbe_b));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%r, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__15 = (unsigned int )*(&llvm_cbe_r);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%22, i32* %%12, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_55_count);
  *llvm_cbe_tmp__6 = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%g, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__16 = (unsigned int )*(&llvm_cbe_g);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%23, i32* %%13, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
  *llvm_cbe_tmp__7 = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i32* %%b, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__17 = (unsigned int )*(&llvm_cbe_b);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%24, i32* %%14, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_71_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  call void @traitCoul(%%struct.pixelType* %%pixIn, %%struct.pixelType* %%pixOut, i8* %%resultats, i8* %%valid) nounwind, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_72_count);
  traitCoul((l_struct_OC_pixelType *)(&llvm_cbe_pixIn), (l_struct_OC_pixelType *)(&llvm_cbe_pixOut), ( char *)(&llvm_cbe_resultats), ( char *)(&llvm_cbe_valid));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%12, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__18 = (unsigned int )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i32* %%13, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__19 = (unsigned int )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%14, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__20 = (unsigned int )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i32* %%15, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__21 = (unsigned int )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%16, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__22 = (unsigned int )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i32* %%17, align 4, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__23 = (unsigned int )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%resultats, align 1, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__24 = (unsigned char )*(&llvm_cbe_resultats);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i8 %%31 to i32, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__24&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8* %%valid, align 1, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__26 = (unsigned char )*(&llvm_cbe_valid);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = zext i8 %%33 to i32, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__26&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([87 x i8]* @aesl_internal_.str10, i64 0, i64 0), i32 %%storemerge6, i32 %%25, i32 %%26, i32 %%27, i32 %%28, i32 %%29, i32 %%30, i32 %%32, i32 %%34) nounwind, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_95_count);
  printf(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 87
#endif
])), llvm_cbe_storemerge6, llvm_cbe_tmp__18, llvm_cbe_tmp__19, llvm_cbe_tmp__20, llvm_cbe_tmp__21, llvm_cbe_tmp__22, llvm_cbe_tmp__23, llvm_cbe_tmp__25, llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__18);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__19);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__20);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__21);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__22);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__23);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__25);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__27);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* %%15, align 4, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__29 = (unsigned int )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i32 (%%struct._IO_FILE*, i8*, ...)* @fprintf(%%struct._IO_FILE* %%2, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str11, i64 0, i64 0), i32 %%36) nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_97_count);
  fprintf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__2, ( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__29);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%16, align 4, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__31 = (unsigned int )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = call i32 (%%struct._IO_FILE*, i8*, ...)* @fprintf(%%struct._IO_FILE* %%2, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str11, i64 0, i64 0), i32 %%38) nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_99_count);
  fprintf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__2, ( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__31);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%17, align 4, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__33 = (unsigned int )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 (%%struct._IO_FILE*, i8*, ...)* @fprintf(%%struct._IO_FILE* %%2, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str11, i64 0, i64 0), i32 %%40) nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_101_count);
  fprintf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__2, ( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__33);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add nsw i32 %%storemerge6, 1, !dbg !13 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
  if (((llvm_cbe_tmp__35&4294967295U) == (107200u&4294967295U))) {
    goto llvm_cbe_tmp__50;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__35;   /* for PHI node */
    goto llvm_cbe_tmp__49;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = call i32 @fclose(%%struct._IO_FILE* %%1) nounwind, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  fclose((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = call i32 @fclose(%%struct._IO_FILE* %%2) nounwind, !dbg !12 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  fclose((l_struct_OC__IO_FILE *)llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i8* %%valid, align 1, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__38 = (unsigned char )*(&llvm_cbe_valid);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
  if (((llvm_cbe_tmp__38&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__51;
  } else {
    goto llvm_cbe_tmp__52;
  }

llvm_cbe_tmp__52:
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_.str12, i64 0, i64 0)) nounwind, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_119_count);
  printf(( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i8* %%resultats, align 1, !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__40 = (unsigned char )*(&llvm_cbe_resultats);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
  if (((llvm_cbe_tmp__40&255U) == (((unsigned char )2)&255U))) {
    goto llvm_cbe_tmp__53;
  } else {
    goto llvm_cbe_tmp__54;
  }

llvm_cbe_tmp__53:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  goto llvm_cbe_tmp__55;

llvm_cbe_tmp__54:
  if (((llvm_cbe_tmp__40&255U) == (((unsigned char )1)&255U))) {
    goto llvm_cbe_tmp__56;
  } else {
    goto llvm_cbe_tmp__57;
  }

llvm_cbe_tmp__56:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts3 = call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_str3, i64 0, i64 0)), !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts3_count);
  puts(( char *)((&aesl_internal_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts3 = 0x%X",llvm_cbe_puts3);
}
  goto llvm_cbe_tmp__58;

llvm_cbe_tmp__57:
  if (((llvm_cbe_tmp__40&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__59;
  } else {
    goto llvm_cbe_tmp__60;
  }

llvm_cbe_tmp__59:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts4 = call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_str4, i64 0, i64 0)), !dbg !14 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts4_count);
  puts(( char *)((&aesl_internal_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts4 = 0x%X",llvm_cbe_puts4);
}
  goto llvm_cbe_tmp__61;

llvm_cbe_tmp__60:
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = zext i8 %%50 to i32, !dbg !15 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__40&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([12 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%60) nounwind, !dbg !15 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_140_count);
  printf(( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__41);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
  goto llvm_cbe_tmp__61;

llvm_cbe_tmp__61:
  goto llvm_cbe_tmp__58;

llvm_cbe_tmp__58:
  goto llvm_cbe_tmp__55;

llvm_cbe_tmp__55:
  goto llvm_cbe_tmp__62;

llvm_cbe_tmp__51:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts5 = call i32 @puts(i8* getelementptr inbounds ([59 x i8]* @aesl_internal_str5, i64 0, i64 0)), !dbg !15 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts5_count);
  puts(( char *)((&aesl_internal_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 59
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts5 = 0x%X",llvm_cbe_puts5);
}
  goto llvm_cbe_tmp__62;

llvm_cbe_tmp__62:
  llvm_cbe_tmp__43__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__46;

llvm_cbe_tmp__46:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = phi i32 [ 0, %%66 ], [ 1, %%7 ], [ 1, %%4  for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__43 = (unsigned int )llvm_cbe_tmp__43__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__43);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",1u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_tmp__43;
}

