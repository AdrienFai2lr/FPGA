set moduleName traitCoul
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type function
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {traitCoul}
set C_modelType { void 0 }
set C_modelArgList {
	{ pixIn int 96 regular {pointer 0}  }
	{ pixOut int 96 regular {pointer 1}  }
	{ resultats int 8 regular {pointer 1}  }
	{ valid int 8 regular {pointer 1}  }
}
set hasAXIMCache 0
set AXIMCacheInstList { }
set C_modelArgMapList {[ 
	{ "Name" : "pixIn", "interface" : "wire", "bitwidth" : 96, "direction" : "READONLY"} , 
 	{ "Name" : "pixOut", "interface" : "wire", "bitwidth" : 96, "direction" : "WRITEONLY"} , 
 	{ "Name" : "resultats", "interface" : "wire", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "valid", "interface" : "wire", "bitwidth" : 8, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 13
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ pixIn sc_in sc_lv 96 signal 0 } 
	{ pixOut sc_out sc_lv 96 signal 1 } 
	{ pixOut_ap_vld sc_out sc_logic 1 outvld 1 } 
	{ resultats sc_out sc_lv 8 signal 2 } 
	{ resultats_ap_vld sc_out sc_logic 1 outvld 2 } 
	{ valid sc_out sc_lv 8 signal 3 } 
	{ valid_ap_vld sc_out sc_logic 1 outvld 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "pixIn", "direction": "in", "datatype": "sc_lv", "bitwidth":96, "type": "signal", "bundle":{"name": "pixIn", "role": "default" }} , 
 	{ "name": "pixOut", "direction": "out", "datatype": "sc_lv", "bitwidth":96, "type": "signal", "bundle":{"name": "pixOut", "role": "default" }} , 
 	{ "name": "pixOut_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "pixOut", "role": "ap_vld" }} , 
 	{ "name": "resultats", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "resultats", "role": "default" }} , 
 	{ "name": "resultats_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "resultats", "role": "ap_vld" }} , 
 	{ "name": "valid", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "valid", "role": "default" }} , 
 	{ "name": "valid_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "valid", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "traitCoul",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "pixIn", "Type" : "None", "Direction" : "I"},
			{"Name" : "pixOut", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "resultats", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "valid", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "cptR", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_detectCoul_fu_81", "Port" : "cptR"}]},
			{"Name" : "cptG", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_detectCoul_fu_81", "Port" : "cptG"}]},
			{"Name" : "cptB", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_detectCoul_fu_81", "Port" : "cptB"}]},
			{"Name" : "cptPix", "Type" : "OVld", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_detectCoul_fu_81", "Port" : "cptPix"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_detectCoul_fu_81", "Parent" : "0",
		"CDFG" : "detectCoul",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "pixIn_val", "Type" : "None", "Direction" : "I"},
			{"Name" : "cptR", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "cptG", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "cptB", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "cptPix", "Type" : "OVld", "Direction" : "IO"}]}]}


set ArgLastReadFirstWriteLatency {
	traitCoul {
		pixIn {Type I LastRead 0 FirstWrite -1}
		pixOut {Type O LastRead -1 FirstWrite 1}
		resultats {Type O LastRead -1 FirstWrite 1}
		valid {Type O LastRead -1 FirstWrite 1}
		cptR {Type IO LastRead -1 FirstWrite -1}
		cptG {Type IO LastRead -1 FirstWrite -1}
		cptB {Type IO LastRead -1 FirstWrite -1}
		cptPix {Type IO LastRead -1 FirstWrite -1}}
	detectCoul {
		pixIn_val {Type I LastRead 0 FirstWrite -1}
		cptR {Type IO LastRead -1 FirstWrite -1}
		cptG {Type IO LastRead -1 FirstWrite -1}
		cptB {Type IO LastRead -1 FirstWrite -1}
		cptPix {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "1", "Max" : "1"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	pixIn { ap_none {  { pixIn in_data 0 96 } } }
	pixOut { ap_vld {  { pixOut out_data 1 96 }  { pixOut_ap_vld out_vld 1 1 } } }
	resultats { ap_vld {  { resultats out_data 1 8 }  { resultats_ap_vld out_vld 1 1 } } }
	valid { ap_vld {  { valid out_data 1 8 }  { valid_ap_vld out_vld 1 1 } } }
}

set maxi_interface_dict [dict create]

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
