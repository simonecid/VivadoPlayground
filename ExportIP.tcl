# modes:
#
# init: creates project, adds hls and test bench files to it, and create solution with FPGA conf and clock
# project_init: creates project, adds hls and test bench files to it
# solution_init: creates solution with FPGA conf and clock
# run_c_sim: builds and runs C simulation
# run_rtl_sim: builds and runs RTL simulation
# synth: synthetise the code
# setup: opens a project and a solution
#

# Defines the mode that will be run in the script
set mode synth
# Sets the project name we will work on
set project_name HLS_Delay
# Sets the solution name we will work on
set solution_name KU115
# Sets the HLS files we want to synthetise 
set hls_files [list HLS_Test.cpp]
# Sets the test bench files
set tb_files [list TB_Test.cpp]
# Sets the device we want to synthetise for
set part {xcku115-flvd1517-2-i}
# Sets the clock frequency (if MHz is appended to the number), or period (if only the number is used)
# 10 = 10 ns
# 40MHz = 25 ns -> set clock 40MHz
set clock 240MHz
# Sets the top-level function name that is going to be starting point for synthetisation
set top_function hls_delay

#removing reset
# config_rtl -reset none

# Collection of utility procedures
source CommonProcedures.tcl

initialise_project $project_name $hls_files $tb_files $top_function
initialise_solution $project_name $solution_name $part $clock
synthetise $project_name $solution_name

export_design -format ip_catalog -vendor "cern-cms" -version 1.0 -description delay