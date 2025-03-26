set SynModuleInfo {
  {SRCNAME exo1 MODELNAME exo1 RTLNAME exo1 IS_TOP 1
    SUBMODULES {
      {MODELNAME exo1_mul_32s_32s_32_5_1 RTLNAME exo1_mul_32s_32s_32_5_1 BINDTYPE op TYPE mul IMPL dsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME exo1_icmp_32s_32s_1_2_1 RTLNAME exo1_icmp_32s_32s_1_2_1 BINDTYPE op TYPE icmp IMPL auto}
      {MODELNAME exo1_icmp_32s_32s_1_2_1_sub RTLNAME exo1_icmp_32s_32s_1_2_1_sub BINDTYPE op TYPE icmp IMPL auto LATENCY 1}
      {MODELNAME exo1_sub_32ns_32ns_32_2_1 RTLNAME exo1_sub_32ns_32ns_32_2_1 BINDTYPE op TYPE sub IMPL fabric LATENCY 1}
    }
  }
}
