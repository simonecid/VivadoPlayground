
set TopModule "hls_main"
set ClockPeriod "10.000000"
set ClockList {}
set multiClockList {}
set PortClockMap {}
set CombLogicFlag 1
set PipelineFlag 0
set DataflowTaskPipelineFlag  0
set TrivialPipelineFlag 0
set noPortSwitchingFlag 0
set FloatingPointFlag 0
set FftOrFirFlag 0
set NbRWValue 0
set intNbAccess 0
set NewDSPMapping 1
set HasDSPModule 1
set ResetLevelFlag 1
set ResetStyle "control"
set ResetSyncFlag 1
set ResetRegisterFlag 0
set ResetVariableFlag 0
set fsmEncStyle "onehot"
set maxFanout "0"
set RtlPrefix ""
set ExtraCCFlags ""
set ExtraCLdFlags ""
set SynCheckOptions ""
set PresynOptions ""
set PreprocOptions ""
set SchedOptions ""
set BindOptions ""
set RtlGenOptions ""
set RtlWriterOptions ""
set CbcGenFlag ""
set CasGenFlag ""
set CasMonitorFlag ""
set AutoSimOptions {}
set ExportMCPathFlag "0"
set SCTraceFileName "mytrace"
set SCTraceFileFormat "vcd"
set SCTraceOption "all"
set TargetInfo "xc7k160t:fbg484:-1"
set SourceFiles {sc {} c ../../HLS_Test.cpp}
set SourceFlags {sc {} C {} c {{ }}}
set DirectiveFile {/users/sb17498/VivadoPlayground/First_Test/First_Test/First_Test.directive}
set TBFiles {verilog ../../TB_Test.cpp bc ../../TB_Test.cpp sc ../../TB_Test.cpp vhdl ../../TB_Test.cpp c {} cas ../../TB_Test.cpp}
set SpecLanguage "C"
set TVInFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TVOutFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TBTops {verilog {} bc {} sc {} vhdl {} c {} cas {}}
set TBInstNames {verilog {} bc {} sc {} vhdl {} c {} cas {}}
set XDCFiles {}
set ExtraGlobalOptions {"area_timing" 1 "clock_gate" 1 "impl_flow" map "power_gate" 0}
set PlatformFiles {{DefaultPlatform {xilinx/kintex7/kintex7 xilinx/kintex7/kintex7_fpv6}}}
set DefaultPlatform "DefaultPlatform"
set TBTVFileNotFound ""
set AppFile "../vivado_hls.app"
set ApsFile "First_Test.aps"
set AvePath ""
set HPFPO "0"
