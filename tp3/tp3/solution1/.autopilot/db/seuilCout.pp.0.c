# 1 "seuilCout.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 339 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/tools/Xilinx/Vitis_HLS/2023.2/common/technology/autopilot/etc/autopilot_ssdm_op.h" 1
# 266 "/tools/Xilinx/Vitis_HLS/2023.2/common/technology/autopilot/etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));
    void _ssdm_op_ReadReq() __attribute__ ((nothrow));
    void _ssdm_op_Read() __attribute__ ((nothrow));
    void _ssdm_op_WriteReq() __attribute__ ((nothrow));
    void _ssdm_op_Write() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbReadReq() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_CanReadReq() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbWriteReq() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_CanWriteReq() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_PrintNone() __attribute__ ((nothrow));
    void _ssdm_op_PrintInt() __attribute__ ((nothrow));
    void _ssdm_op_PrintDouble() __attribute__ ((nothrow));

    void _ssdm_op_Wait(int) __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_op_SpecStable() __attribute__ ((nothrow));
    void _ssdm_op_SpecStableContent() __attribute__ ((nothrow));

    void _ssdm_op_SpecBindPort() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipoDepth() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 2 "<built-in>" 2
# 1 "seuilCout.c" 2
# 1 "./seuilCout.h" 1
# 10 "./seuilCout.h"
typedef unsigned char detectType;
typedef unsigned char validType;
typedef int colorType;

typedef struct{
    colorType r;
    colorType g;
    colorType b;
}pixelType;

void seuilCout(pixelType *pixOut,pixelType pixIn);

__attribute__((sdx_kernel("detectCoul", 0))) void detectCoul(detectType *res, validType *valid, pixelType pixIn);
# 2 "seuilCout.c" 2

void seuilCout(pixelType *pixOut,pixelType pixIn){

    colorType valR,valG,valB;
    colorType resR,resG,resB;



    valB=pixIn.b;
    valG=pixIn.g;
    valR=pixIn.r;


    resR = (valR<valG || valR<valB)? 0 : valR;
    resG = (valG<valR || valG<valB)? 0 : valG;
    resB = (valB<valR || valB<valG)? 0 : valB;

    pixOut->b=resB;
    pixOut->g=resG;
    pixOut->r=resR;


}

__attribute__((sdx_kernel("detectCoul", 0))) void detectCoul(detectType *resultats, validType *valid, pixelType pixIn){
#line 16 "/home/etudiants/master1/adrien.failler/FPGA/tp3/tp3/solution1/csynth.tcl"
#pragma HLSDIRECTIVE TOP name=detectCoul
# 26 "seuilCout.c"

#line 7 "/home/etudiants/master1/adrien.failler/FPGA/tp3/tp3/solution1/directives.tcl"
#pragma HLSDIRECTIVE TOP name=detectCoul
# 26 "seuilCout.c"


    colorType valR = pixIn.r;
    colorType valG = pixIn.g;
    colorType valB = pixIn.b;

    static int cptPix = 0;
    static int cptR = 0;
    static int cptG = 0;
    static int cptB = 0;

    colorType resR = 0;
    colorType resG = 0;
    colorType resB = 0;


    *valid = 0;

    if (valR > valG && valR > valB) {
        resR = valR;
        cptR++;
    }
    else if (valG > valR && valG > valB) {
        resG = valG;
        cptG++;
    }
    else if (valB > valR && valB > valG) {
        resB = valB;
        cptB++;
    }
    else if (valR == valG && valR > valB) {

        resR = valR;
        resG = valG;
        cptR++;
        cptG++;
    }
    else if (valR == valB && valR > valG) {

        resR = valR;
        resB = valB;
        cptR++;
        cptB++;
    }
    else if (valG == valB && valG > valR) {

        resG = valG;
        resB = valB;
        cptG++;
        cptB++;
    }
    else if (valR == valG && valR == valB) {

        resR = valR;
        resG = valG;
        resB = valB;

        cptR++;
        cptG++;
        cptB++;
    }

    cptPix++;

    if (cptR > cptG && cptR > cptB) {
        *resultats = 2;
        *valid = 1;
    }
    else if (cptG > cptR && cptG > cptB) {
        *resultats = 1;
        *valid = 1;
    }
    else if (cptB > cptR && cptB > cptG) {
        *resultats = 0;
        *valid = 1;
    }
    else if (cptR == cptG && cptR > cptB) {
        *resultats = 2;
        *valid = 1;
    }
    else if (cptR == cptB && cptR > cptG) {
        *resultats = 2;
        *valid = 1;
    }
    else if (cptG == cptB && cptG > cptR) {
        *resultats = 1;
        *valid = 1;
    }
    else {

        *resultats = 0;
        *valid = 0;
    }

    if (cptPix == 268 * 400)
    {
        cptPix = 0;
        cptB = 0;
        cptG = 0;
        cptR = 0;
    }
}
