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

/* Structure contents */
struct l_struct_OC_pixelType {
  unsigned int field0;
  unsigned int field1;
  unsigned int field2;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void seuilCout(l_struct_OC_pixelType *llvm_cbe_pixOut, l_struct_OC_pixelType llvm_cbe_pixIn);
void detectCoul( char *llvm_cbe_res, l_struct_OC_pixelType llvm_cbe_pixIn);


/* Global Variable Definitions and Initialization */
static unsigned int aesl_internal_detectCoul_OC_cptB;
static unsigned int aesl_internal_detectCoul_OC_cptG;
static unsigned int aesl_internal_detectCoul_OC_cptPix;
static  char aesl_internal__OC_str[9] = "%d %d %d";
static unsigned int aesl_internal_detectCoul_OC_cptR;


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

void seuilCout(l_struct_OC_pixelType *llvm_cbe_pixOut, l_struct_OC_pixelType llvm_cbe_pixIn) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  signed int *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  signed int *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond1_count = 0;
  bool llvm_cbe_or_2e_cond1;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond2_count = 0;
  bool llvm_cbe_or_2e_cond2;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  signed int *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  signed int *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  signed int *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @seuilCout\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 2, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_6_count);
  llvm_cbe_tmp__1 = (signed int *)(&llvm_cbe_pixIn.field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 8, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__2 = (unsigned int )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 1, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_pixIn.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__4 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 0, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__5 = (signed int *)(&llvm_cbe_pixIn.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 8, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__6 = (unsigned int )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%7, %%8, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((signed int )llvm_cbe_tmp__6) < ((signed int )llvm_cbe_tmp__4)) | (((signed int )llvm_cbe_tmp__6) < ((signed int )llvm_cbe_tmp__2)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = select i1 %%or.cond, i32 0, i32 %%6, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__7 = (unsigned int )((llvm_cbe_or_2e_cond) ? ((unsigned int )0u) : ((unsigned int )llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond1 = or i1 %%10, %%11, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_or_2e_cond1_count);
  llvm_cbe_or_2e_cond1 = (bool )(((((signed int )llvm_cbe_tmp__4) < ((signed int )llvm_cbe_tmp__6)) | (((signed int )llvm_cbe_tmp__4) < ((signed int )llvm_cbe_tmp__2)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond1 = 0x%X\n", llvm_cbe_or_2e_cond1);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = select i1 %%or.cond1, i32 0, i32 %%4, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__8 = (unsigned int )((llvm_cbe_or_2e_cond1) ? ((unsigned int )0u) : ((unsigned int )llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond2 = or i1 %%13, %%14, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_or_2e_cond2_count);
  llvm_cbe_or_2e_cond2 = (bool )(((((signed int )llvm_cbe_tmp__2) < ((signed int )llvm_cbe_tmp__6)) | (((signed int )llvm_cbe_tmp__2) < ((signed int )llvm_cbe_tmp__4)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond2 = 0x%X\n", llvm_cbe_or_2e_cond2);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = select i1 %%or.cond2, i32 0, i32 %%2, !dbg !5 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__9 = (unsigned int )((llvm_cbe_or_2e_cond2) ? ((unsigned int )0u) : ((unsigned int )llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.pixelType* %%pixOut, i64 0, i32 2, !dbg !4 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__10 = (signed int *)(&llvm_cbe_pixOut->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%15, i32* %%16, align 4, !dbg !4 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_49_count);
  *llvm_cbe_tmp__10 = llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.pixelType* %%pixOut, i64 0, i32 1, !dbg !4 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__11 = (signed int *)(&llvm_cbe_pixOut->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%12, i32* %%17, align 4, !dbg !4 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_51_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.pixelType* %%pixOut, i64 0, i32 0, !dbg !4 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__12 = (signed int *)(&llvm_cbe_pixOut->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%9, i32* %%18, align 4, !dbg !4 for 0x%llxth hint within @seuilCout  --> \n", ++aesl_llvm_cbe_53_count);
  *llvm_cbe_tmp__12 = llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @seuilCout}\n");
  return;
}


void detectCoul( char *llvm_cbe_res, l_struct_OC_pixelType llvm_cbe_pixIn) {
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  signed int *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  signed int *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  signed int *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_notlhs_count = 0;
  static  unsigned long long aesl_llvm_cbe_notrhs_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_2e_not_count = 0;
  bool llvm_cbe_or_2e_cond_2e_not;
  static  unsigned long long aesl_llvm_cbe_phitmp_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond6_count = 0;
  bool llvm_cbe_or_2e_cond6;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_notlhs21_count = 0;
  static  unsigned long long aesl_llvm_cbe_notrhs22_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond7_2e_not_count = 0;
  bool llvm_cbe_or_2e_cond7_2e_not;
  static  unsigned long long aesl_llvm_cbe_phitmp1_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond8_count = 0;
  bool llvm_cbe_or_2e_cond8;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_notlhs23_count = 0;
  static  unsigned long long aesl_llvm_cbe_notrhs24_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond9_2e_not_count = 0;
  bool llvm_cbe_or_2e_cond9_2e_not;
  static  unsigned long long aesl_llvm_cbe_phitmp2_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond10_count = 0;
  bool llvm_cbe_or_2e_cond10;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond12_count = 0;
  bool llvm_cbe_or_2e_cond12;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond14_count = 0;
  bool llvm_cbe_or_2e_cond14;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond16_count = 0;
  bool llvm_cbe_or_2e_cond16;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond18_count = 0;
  bool llvm_cbe_or_2e_cond18;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond20_count = 0;
  bool llvm_cbe_or_2e_cond20;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  bool llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_phitmp3_count = 0;
  unsigned char llvm_cbe_phitmp3;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge27_count = 0;
  unsigned char llvm_cbe_storemerge27;
  unsigned char llvm_cbe_storemerge27__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @detectCoul\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 2, !dbg !5 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__13 = (signed int *)(&llvm_cbe_pixIn.field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 8, !dbg !5 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 1, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__15 = (signed int *)(&llvm_cbe_pixIn.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__16 = (unsigned int )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.pixelType* %%pixIn, i64 0, i32 0, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__17 = (signed int *)(&llvm_cbe_pixIn.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 8, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__18 = (unsigned int )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond.not = and i1 %%notrhs, %%notlhs, !dbg !5 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond_2e_not_count);
  llvm_cbe_or_2e_cond_2e_not = (bool )(((((signed int )llvm_cbe_tmp__18) >= ((signed int )llvm_cbe_tmp__14)) & (((signed int )llvm_cbe_tmp__18) >= ((signed int )llvm_cbe_tmp__16)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond.not = 0x%X\n", llvm_cbe_or_2e_cond_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond6 = and i1 %%or.cond.not, %%phitmp, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond6_count);
  llvm_cbe_or_2e_cond6 = (bool )((llvm_cbe_or_2e_cond_2e_not & ((llvm_cbe_tmp__18&4294967295U) != (0u&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond6 = 0x%X\n", llvm_cbe_or_2e_cond6);
  if (llvm_cbe_or_2e_cond6) {
    goto llvm_cbe_tmp__35;
  } else {
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* @aesl_internal_detectCoul.cptR, align 4, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__19 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptR);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%8, 1, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_tmp__19&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%9, i32* @aesl_internal_detectCoul.cptR, align 4, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_90_count);
  *(&aesl_internal_detectCoul_OC_cptR) = llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
  goto llvm_cbe__2e_critedge;

llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond7.not = and i1 %%notrhs22, %%notlhs21, !dbg !5 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond7_2e_not_count);
  llvm_cbe_or_2e_cond7_2e_not = (bool )(((((signed int )llvm_cbe_tmp__16) >= ((signed int )llvm_cbe_tmp__14)) & (((signed int )llvm_cbe_tmp__16) >= ((signed int )llvm_cbe_tmp__18)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond7.not = 0x%X\n", llvm_cbe_or_2e_cond7_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond8 = and i1 %%or.cond7.not, %%phitmp1, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond8_count);
  llvm_cbe_or_2e_cond8 = (bool )((llvm_cbe_or_2e_cond7_2e_not & ((llvm_cbe_tmp__16&4294967295U) != (0u&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond8 = 0x%X\n", llvm_cbe_or_2e_cond8);
  if (llvm_cbe_or_2e_cond8) {
    goto llvm_cbe_tmp__36;
  } else {
    goto llvm_cbe__2e_critedge4;
  }

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i32* @aesl_internal_detectCoul.cptG, align 4, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__21 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptG);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%11, 1, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_tmp__21&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%12, i32* @aesl_internal_detectCoul.cptG, align 4, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_96_count);
  *(&aesl_internal_detectCoul_OC_cptG) = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
  goto llvm_cbe__2e_critedge4;

llvm_cbe__2e_critedge4:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond9.not = and i1 %%notrhs24, %%notlhs23, !dbg !6 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond9_2e_not_count);
  llvm_cbe_or_2e_cond9_2e_not = (bool )(((((signed int )llvm_cbe_tmp__14) >= ((signed int )llvm_cbe_tmp__16)) & (((signed int )llvm_cbe_tmp__14) >= ((signed int )llvm_cbe_tmp__18)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond9.not = 0x%X\n", llvm_cbe_or_2e_cond9_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond10 = and i1 %%or.cond9.not, %%phitmp2, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond10_count);
  llvm_cbe_or_2e_cond10 = (bool )((llvm_cbe_or_2e_cond9_2e_not & ((llvm_cbe_tmp__14&4294967295U) != (0u&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond10 = 0x%X\n", llvm_cbe_or_2e_cond10);
  if (llvm_cbe_or_2e_cond10) {
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe__2e_critedge5;
  }

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* @aesl_internal_detectCoul.cptB, align 4, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__23 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptB);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%14, 1, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__23&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%15, i32* @aesl_internal_detectCoul.cptB, align 4, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_102_count);
  *(&aesl_internal_detectCoul_OC_cptB) = llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
  goto llvm_cbe__2e_critedge5;

llvm_cbe__2e_critedge5:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* @aesl_internal_detectCoul.cptR, align 4, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__25 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptR);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* @aesl_internal_detectCoul.cptG, align 4, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__26 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptG);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* @aesl_internal_detectCoul.cptB, align 4, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__27 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptB);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond12 = and i1 %%18, %%20, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond12_count);
  llvm_cbe_or_2e_cond12 = (bool )((((llvm_cbe_tmp__25&4294967295U) == (llvm_cbe_tmp__26&4294967295U)) & ((llvm_cbe_tmp__26&4294967295U) == (llvm_cbe_tmp__27&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond12 = 0x%X\n", llvm_cbe_or_2e_cond12);
  if (llvm_cbe_or_2e_cond12) {
    llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe_tmp__38;
  } else {
    goto llvm_cbe_tmp__39;
  }

llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond14 = and i1 %%18, %%22, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond14_count);
  llvm_cbe_or_2e_cond14 = (bool )((((llvm_cbe_tmp__25&4294967295U) == (llvm_cbe_tmp__26&4294967295U)) & (((signed int )llvm_cbe_tmp__25) > ((signed int )llvm_cbe_tmp__27)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond14 = 0x%X\n", llvm_cbe_or_2e_cond14);
  if (llvm_cbe_or_2e_cond14) {
    llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned char )((unsigned char )2);   /* for PHI node */
    goto llvm_cbe_tmp__38;
  } else {
    goto llvm_cbe_tmp__40;
  }

llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond16 = and i1 %%24, %%25, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond16_count);
  llvm_cbe_or_2e_cond16 = (bool )((((llvm_cbe_tmp__25&4294967295U) == (llvm_cbe_tmp__27&4294967295U)) & (((signed int )llvm_cbe_tmp__25) > ((signed int )llvm_cbe_tmp__26)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond16 = 0x%X\n", llvm_cbe_or_2e_cond16);
  if (llvm_cbe_or_2e_cond16) {
    llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned char )((unsigned char )2);   /* for PHI node */
    goto llvm_cbe_tmp__38;
  } else {
    goto llvm_cbe_tmp__41;
  }

llvm_cbe_tmp__41:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond18 = and i1 %%20, %%27, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond18_count);
  llvm_cbe_or_2e_cond18 = (bool )((((llvm_cbe_tmp__26&4294967295U) == (llvm_cbe_tmp__27&4294967295U)) & (((signed int )llvm_cbe_tmp__26) > ((signed int )llvm_cbe_tmp__25)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond18 = 0x%X\n", llvm_cbe_or_2e_cond18);
  if (llvm_cbe_or_2e_cond18) {
    llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned char )((unsigned char )1);   /* for PHI node */
    goto llvm_cbe_tmp__38;
  } else {
    goto llvm_cbe_tmp__42;
  }

llvm_cbe_tmp__42:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond20 = and i1 %%25, %%22, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_or_2e_cond20_count);
  llvm_cbe_or_2e_cond20 = (bool )(((((signed int )llvm_cbe_tmp__25) > ((signed int )llvm_cbe_tmp__26)) & (((signed int )llvm_cbe_tmp__25) > ((signed int )llvm_cbe_tmp__27)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond20 = 0x%X\n", llvm_cbe_or_2e_cond20);
  if (llvm_cbe_or_2e_cond20) {
    llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned char )((unsigned char )2);   /* for PHI node */
    goto llvm_cbe_tmp__38;
  } else {
    goto llvm_cbe_tmp__43;
  }

llvm_cbe_tmp__43:
if (AESL_DEBUG_TRACE)
printf("\n  %%. = and i1 %%27, %%30, !dbg !7 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (bool )(((((signed int )llvm_cbe_tmp__26) > ((signed int )llvm_cbe_tmp__25)) & (((signed int )llvm_cbe_tmp__26) > ((signed int )llvm_cbe_tmp__27)))&1);
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp3 = zext i1 %%. to i for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_phitmp3_count);
  llvm_cbe_phitmp3 = (unsigned char )((unsigned char )(bool )llvm_cbe__2e_&1U);
if (AESL_DEBUG_TRACE)
printf("\nphitmp3 = 0x%X\n", llvm_cbe_phitmp3);
  llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned char )llvm_cbe_phitmp3;   /* for PHI node */
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__38:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge27 = phi i8 [ 0, %%.critedge5 ], [ 2, %%21 ], [ 2, %%23 ], [ 1, %%26 ], [ %%phitmp3, %%29 ], [ 2, %%28  for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_storemerge27_count);
  llvm_cbe_storemerge27 = (unsigned char )llvm_cbe_storemerge27__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge27 = 0x%X",llvm_cbe_storemerge27);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",((unsigned char )2));
printf("\n = 0x%X",((unsigned char )2));
printf("\n = 0x%X",((unsigned char )1));
printf("\nphitmp3 = 0x%X",llvm_cbe_phitmp3);
printf("\n = 0x%X",((unsigned char )2));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%storemerge27, i8* %%res, align 1, !dbg !4 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_120_count);
  *llvm_cbe_res = llvm_cbe_storemerge27;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge27 = 0x%X\n", llvm_cbe_storemerge27);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i32* @aesl_internal_detectCoul.cptPix, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__28 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptPix);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%32, 1, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_tmp__28&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%33, i32* @aesl_internal_detectCoul.cptPix, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_123_count);
  *(&aesl_internal_detectCoul_OC_cptPix) = llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* @aesl_internal_detectCoul.cptR, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__30 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptR);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* @aesl_internal_detectCoul.cptG, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__31 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptG);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* @aesl_internal_detectCoul.cptB, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__32 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptB);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%34, i32 %%35, i32 %%36) nounwind, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_127_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), llvm_cbe_tmp__30, llvm_cbe_tmp__31, llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__30);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__31);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__32);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* @aesl_internal_detectCoul.cptPix, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__34 = (unsigned int )*(&aesl_internal_detectCoul_OC_cptPix);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
  if (((llvm_cbe_tmp__34&4294967295U) == (107200u&4294967295U))) {
    goto llvm_cbe_tmp__44;
  } else {
    goto llvm_cbe_tmp__45;
  }

llvm_cbe_tmp__44:
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @aesl_internal_detectCoul.cptPix, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_131_count);
  *(&aesl_internal_detectCoul_OC_cptPix) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @aesl_internal_detectCoul.cptB, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_132_count);
  *(&aesl_internal_detectCoul_OC_cptB) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @aesl_internal_detectCoul.cptG, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_133_count);
  *(&aesl_internal_detectCoul_OC_cptG) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* @aesl_internal_detectCoul.cptR, align 4, !dbg !8 for 0x%llxth hint within @detectCoul  --> \n", ++aesl_llvm_cbe_134_count);
  *(&aesl_internal_detectCoul_OC_cptR) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  goto llvm_cbe_tmp__45;

llvm_cbe_tmp__45:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @detectCoul}\n");
  return;
}

