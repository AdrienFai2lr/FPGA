; ModuleID = '/home/etudiants/master1/adrien.failler/FPGA/tp3/tp3/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%struct.pixelType = type { i32, i32, i32 }

; Function Attrs: noinline willreturn
define void @apatb_traitCoul_ir(%struct.pixelType* noalias nocapture nonnull readonly %pixIn, %struct.pixelType* noalias nocapture nonnull %pixOut, i8* noalias nocapture nonnull %resultats, i8* noalias nocapture nonnull %valid) local_unnamed_addr #0 {
entry:
  %pixIn_copy = alloca i96, align 512
  %pixOut_copy = alloca i96, align 512
  %resultats_copy = alloca i8, align 512
  %valid_copy = alloca i8, align 512
  call fastcc void @copy_in(%struct.pixelType* nonnull %pixIn, i96* nonnull align 512 %pixIn_copy, %struct.pixelType* nonnull %pixOut, i96* nonnull align 512 %pixOut_copy, i8* nonnull %resultats, i8* nonnull align 512 %resultats_copy, i8* nonnull %valid, i8* nonnull align 512 %valid_copy)
  call void @apatb_traitCoul_hw(i96* %pixIn_copy, i96* %pixOut_copy, i8* %resultats_copy, i8* %valid_copy)
  call void @copy_back(%struct.pixelType* %pixIn, i96* %pixIn_copy, %struct.pixelType* %pixOut, i96* %pixOut_copy, i8* %resultats, i8* %resultats_copy, i8* %valid, i8* %valid_copy)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_in(%struct.pixelType* noalias readonly, i96* noalias align 512, %struct.pixelType* noalias readonly, i96* noalias align 512, i8* noalias readonly, i8* noalias align 512, i8* noalias readonly, i8* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0struct.pixelType.9(i96* align 512 %1, %struct.pixelType* %0)
  call fastcc void @onebyonecpy_hls.p0struct.pixelType.9(i96* align 512 %3, %struct.pixelType* %2)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %5, i8* %4)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %7, i8* %6)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0i8(i8* noalias align 512 %dst, i8* noalias readonly %src) unnamed_addr #2 {
entry:
  %0 = icmp eq i8* %dst, null
  %1 = icmp eq i8* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %3 = load i8, i8* %src, align 1
  store i8 %3, i8* %dst, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_out(%struct.pixelType* noalias, i96* noalias readonly align 512, %struct.pixelType* noalias, i96* noalias readonly align 512, i8* noalias, i8* noalias readonly align 512, i8* noalias, i8* noalias readonly align 512) unnamed_addr #3 {
entry:
  call fastcc void @onebyonecpy_hls.p0struct.pixelType(%struct.pixelType* %0, i96* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0struct.pixelType(%struct.pixelType* %2, i96* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %4, i8* align 512 %5)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %6, i8* align 512 %7)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0struct.pixelType(%struct.pixelType* noalias %dst, i96* noalias readonly align 512 %src) unnamed_addr #2 {
entry:
  %0 = icmp eq %struct.pixelType* %dst, null
  %1 = icmp eq i96* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %dst.0 = getelementptr %struct.pixelType, %struct.pixelType* %dst, i64 0, i32 0
  %3 = load i96, i96* %src, align 512
  %.partselect2 = trunc i96 %3 to i32
  store i32 %.partselect2, i32* %dst.0, align 512
  %dst.1 = getelementptr %struct.pixelType, %struct.pixelType* %dst, i64 0, i32 1
  %4 = lshr i96 %3, 32
  %.partselect1 = trunc i96 %4 to i32
  store i32 %.partselect1, i32* %dst.1, align 4
  %dst.2 = getelementptr %struct.pixelType, %struct.pixelType* %dst, i64 0, i32 2
  %5 = lshr i96 %3, 64
  %.partselect = trunc i96 %5 to i32
  store i32 %.partselect, i32* %dst.2, align 8
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0struct.pixelType.9(i96* noalias align 512 %dst, %struct.pixelType* noalias readonly %src) unnamed_addr #2 {
entry:
  %0 = icmp eq i96* %dst, null
  %1 = icmp eq %struct.pixelType* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %src.0 = getelementptr %struct.pixelType, %struct.pixelType* %src, i64 0, i32 0
  %3 = load i32, i32* %src.0, align 4
  %4 = zext i32 %3 to i96
  %src.1 = getelementptr %struct.pixelType, %struct.pixelType* %src, i64 0, i32 1
  %5 = load i32, i32* %src.1, align 4
  %6 = zext i32 %5 to i96
  %7 = shl i96 %6, 32
  %.partset1 = or i96 %7, %4
  %src.2 = getelementptr %struct.pixelType, %struct.pixelType* %src, i64 0, i32 2
  %8 = load i32, i32* %src.2, align 4
  %9 = zext i32 %8 to i96
  %10 = shl i96 %9, 64
  %.partset = or i96 %.partset1, %10
  store i96 %.partset, i96* %dst, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

declare void @apatb_traitCoul_hw(i96*, i96*, i8*, i8*)

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_back(%struct.pixelType* noalias, i96* noalias readonly align 512, %struct.pixelType* noalias, i96* noalias readonly align 512, i8* noalias, i8* noalias readonly align 512, i8* noalias, i8* noalias readonly align 512) unnamed_addr #3 {
entry:
  call fastcc void @onebyonecpy_hls.p0struct.pixelType(%struct.pixelType* %2, i96* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %4, i8* align 512 %5)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %6, i8* align 512 %7)
  ret void
}

define void @traitCoul_hw_stub_wrapper(i96*, i96*, i8*, i8*) #4 {
entry:
  %4 = alloca %struct.pixelType
  %5 = alloca %struct.pixelType
  call void @copy_out(%struct.pixelType* %4, i96* %0, %struct.pixelType* %5, i96* %1, i8* null, i8* %2, i8* null, i8* %3)
  call void @traitCoul_hw_stub(%struct.pixelType* %4, %struct.pixelType* %5, i8* %2, i8* %3)
  call void @copy_in(%struct.pixelType* %4, i96* %0, %struct.pixelType* %5, i96* %1, i8* null, i8* %2, i8* null, i8* %3)
  ret void
}

declare void @traitCoul_hw_stub(%struct.pixelType*, %struct.pixelType*, i8*, i8*)

attributes #0 = { noinline willreturn "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyout" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
