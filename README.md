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
 
## Some definitions and commands

### Project
A project is a collection of files and solutions.
A project is created (or opened, if already existing) by running ```open_project <project_name>```.
In HLS you have two type of files: the HLS C files, and the test bench files.

### HLS C files
These are the actual files that will be synthesised to FPGA FW.
You add those files to an opened project by running ```add_files <file1> <file2> ...```. Please note that including .h files is discouraged.
HLS requires an explicit declaration of what your top-level function is going to be, you provide it by running ```set_top <function_name>```.
In this repository ```HLS_Test.cpp``` is our test HLS file, and ```hls_main()``` is our top-level function.

### Test bench files
These are the files used to test your HLS code by first simulating it. 
You can have 2 different types of simulation: C simulation, and HDL simulation.
In the C simulation you basically compile your code under GCC and you run your test on it.
HDL simulation takes the synthesised code and puts in a emulator that runs it.
At the moment, I have run a C simulation of the code.
