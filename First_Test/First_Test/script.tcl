############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project First_Test
add_files First_Test.cpp
open_solution "First_Test"
set_part {xc7k160tfbg484-1}
create_clock -period 10 -name default
#source "./First_Test/First_Test/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
