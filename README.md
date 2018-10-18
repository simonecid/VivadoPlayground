# VivadoPlayground
Testing area with useful stuff for VivadoHLS

## Running the test
By running
```bash
vivado_hls -f CommonWorkflows.tcl
```
the vivado project can be created and run.
The main handle to decide which workflow will be run is the variable ```mode``` in the ```CommonWorkflows.tcl``` script.
These modes have been implemented:
 * ```init```: creates project, adds hls and test bench files to it, and creates a solution with FPGA conf and clock
 * ```project_init```: creates project, adds hls and test bench files to it
 * ```solution_init```: creates solution with FPGA conf and clock
 * ```build_c_sim```: builds and runs C simulation
 
## Some basic concepts and relative examples in the repository

### Project
A **project** is a collection of files and solutions.
A project is created (or opened, if already existing) by running ```open_project <project_name>```.
In this repo the project name is ```First_Test```.

### Solutions
Vivado HLS allows the user to synthesise the same code on a variety of device and with a variety of optimisations. A **solution** enables to target a specific device with a specific frequency and optimisation for the code in the project. By having multiple solutions different optimisation and devices can be targeted while keeping the same code, in order to test which settings works best for the project.
A solution can be added to a project (or opened, if already existing) by running ```open_solution <solution_name>```.
```set_part <part_name>``` and ```create_clock -period <clock>``` enable to set the target FPGA and the clock frequency. Clock frequency can be specified as a number to give the period in ns (e.g. ```create_clock -period 10``` would set it to 10 ns), or as a frequency (e.g. ```create_clock -period 10MHz``` sets it to 10 MHz).

### Files in a HLS project
In HLS you have two type of files: the HLS C files, and the test bench files.

#### HLS C files
These are the actual files that will be synthesised to FPGA FW.
You add those files to an opened project by running ```add_files <file1> <file2> ...```. 
**Please note that including .h files is discouraged.**
HLS requires an explicit declaration of what your top-level function is going to be, you provide it by running ```set_top <function_name>```.
In this repository ```HLS_Test.cpp``` is our test HLS file, and ```hls_main()``` is our top-level function.

#### Test bench files
These are the files used to test your HLS code by compiling the C code and running it. 
The file ```TB_Test.cpp``` is the file that is compiled into the C++ simulation. It contains the ```main()``` and links to the HLS code in ```HLT_Test.cpp``` through the header ```HLT_Test.h```.
Test bench files are added to the project using ```add_files -tb <file1> <file2> ...```.

## Code simulation
You can have 2 different types of simulation: C simulation, and HDL simulation.
In the C simulation you basically compile your code under GCC and you run your test on it.
HDL simulation takes the synthesised code and puts in a emulator that runs it.
### Running C simulation
To run the test bench, you run ```csim_design```. The command compiles in gcc/g++ the code and runs it. 
By running ```csim_design -setup```, it is possible to compile without running.
