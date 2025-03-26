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
typedef struct l_struct_OC__IO_FILE l_struct_OC__IO_FILE;
typedef struct l_struct_OC__IO_marker l_struct_OC__IO_marker;
typedef struct l_struct_OC__IO_codecvt l_struct_OC__IO_codecvt;
typedef struct l_struct_OC__IO_wide_data l_struct_OC__IO_wide_data;

/* Structure contents */
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
  l_struct_OC__IO_marker *field12;
  l_struct_OC__IO_FILE *field13;
  unsigned int field14;
  unsigned int field15;
  unsigned long long field16;
  unsigned short field17;
  unsigned char field18;
   char field19[1];
   char *field20;
  unsigned long long field21;
  l_struct_OC__IO_codecvt *field22;
  l_struct_OC__IO_wide_data *field23;
  l_struct_OC__IO_FILE *field24;
   char *field25;
  unsigned long long field26;
  unsigned int field27;
   char field28[20];
};

struct l_struct_OC__IO_marker {
};

struct l_struct_OC__IO_codecvt {
};

struct l_struct_OC__IO_wide_data {
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void apatb_exo1_sw(signed int *, signed int , signed int , signed int , signed int );


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str7[45] = "PASS: The output matches the golden output!\n";
static  char aesl_internal_str[31] = "Comparing against output data ";
static  char aesl_internal__OC_str2[4] = "%i\n";
static  char aesl_internal__OC_str1[2] = "w";
static  char aesl_internal__OC_str5[45] = "*******************************************\n";
static  char aesl_internal__OC_str6[47] = "FAIL: Output DOES NOT match the golden output\n";
static  char aesl_internal__OC_str4[29] = "diff -w out.dat out.gold.dat";
static  char aesl_internal__OC_str[8] = "out.dat";


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
  static  unsigned long long aesl_llvm_cbe_output_count = 0;
  signed int llvm_cbe_output;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  l_struct_OC__IO_FILE *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call noalias %%struct._IO_FILE* @fopen(i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_6_count);
  llvm_cbe_tmp__1 = (l_struct_OC__IO_FILE *)aesl_fopen(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
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
printf("\n  call void @apatb_exo1_sw(i32* %%output, i32 23, i32 50, i32 13, i32 9) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_14_count);
  apatb_exo1_sw((signed int *)(&llvm_cbe_output), 23u, 50u, 13u, 9u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",23u);
printf("\nArgument  = 0x%X",50u);
printf("\nArgument  = 0x%X",13u);
printf("\nArgument  = 0x%X",9u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%output, align 4, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__2 = (unsigned int )*(&llvm_cbe_output);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 (%%struct._IO_FILE*, i8*, ...)* @fprintf(%%struct._IO_FILE* %%1, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 %%2) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_22_count);
  fprintf((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i32 @fclose(%%struct._IO_FILE* %%1) nounwind, !dbg !9 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_23_count);
  fclose((l_struct_OC__IO_FILE *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 (...)* @system(i8* getelementptr inbounds ([29 x i8]* @aesl_internal_.str4, i64 0, i64 0)) nounwind, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__5 = (unsigned int )system(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 29
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__5);
}
  if (((llvm_cbe_tmp__5&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__18;
  } else {
    goto llvm_cbe_tmp__19;
  }

llvm_cbe_tmp__19:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load %%struct._IO_FILE** @stdout, align 8, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__6 = (l_struct_OC__IO_FILE *)*(&stdout);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str5, i64 0, i64 0), i64 44, i64 1, %%struct._IO_FILE* %%8), !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_28_count);
  fwrite(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",44ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load %%struct._IO_FILE** @stdout, align 8, !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__8 = (l_struct_OC__IO_FILE *)*(&stdout);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i64 @fwrite(i8* getelementptr inbounds ([47 x i8]* @aesl_internal_.str6, i64 0, i64 0), i64 46, i64 1, %%struct._IO_FILE* %%10), !dbg !10 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  fwrite(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 47
#endif
])), 46ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",46ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load %%struct._IO_FILE** @stdout, align 8, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__10 = (l_struct_OC__IO_FILE *)*(&stdout);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str5, i64 0, i64 0), i64 44, i64 1, %%struct._IO_FILE* %%12), !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_32_count);
  fwrite(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",44ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__11);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__20;

llvm_cbe_tmp__18:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load %%struct._IO_FILE** @stdout, align 8, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__12 = (l_struct_OC__IO_FILE *)*(&stdout);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str5, i64 0, i64 0), i64 44, i64 1, %%struct._IO_FILE* %%15), !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  fwrite(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",44ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load %%struct._IO_FILE** @stdout, align 8, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__14 = (l_struct_OC__IO_FILE *)*(&stdout);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str7, i64 0, i64 0), i64 44, i64 1, %%struct._IO_FILE* %%17), !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_37_count);
  fwrite(( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",44ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load %%struct._IO_FILE** @stdout, align 8, !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__16 = (l_struct_OC__IO_FILE *)*(&stdout);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str5, i64 0, i64 0), i64 44, i64 1, %%struct._IO_FILE* %%19), !dbg !11 for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_39_count);
  fwrite(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__IO_FILE *)llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%llX",44ull);
printf("\nArgument  = 0x%llX",1ull);
printf("\nReturn  = 0x%llX",llvm_cbe_tmp__17);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__20;

llvm_cbe_tmp__20:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 1, %%7 ], [ 0, %%14  for 0x%llxth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge;
}

