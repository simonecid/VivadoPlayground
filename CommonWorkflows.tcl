# modes:
#
# init: creates project, adds hls and test bench files to it, and create solution with FPGA conf and clock
# project_init: creates project, adds hls and test bench files to it
# solution_init: creates solution with FPGA conf and clock
# build_c_sim: builds and runs C simulation
#

set mode init
set project_name First_Test
set solution_name First_Test
set hls_files [list HLS_Test.cpp]
set tb_files [list TB_Test.cpp]
set part {xc7k160tfbg484-1}
set clock 10
set top_function hls_main

source CommonProcedures.tcl

switch $mode {
    init {
      initialise_project $project_name $hls_files $tb_files $top_function
      initialise_solution $project_name $solution_name $part $clock
    }
    project_init {
      initialise_project $project_name $hls_files $tb_files $top_function
    }
    solution_init {
      initialise_solution $project_name $solution_name $part $clock
    }
    build_c_sim {
      build_c_simulation $project_name $solution_name
    }
    default {
        puts "Mode $mode is invalid."
    }
}

