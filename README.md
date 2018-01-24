# ECE3SAT_PhaseB_OBC prototype

This repository contains software code used for OBC prototype at the end of the year.
Our objective is to set up the CAN communication layout, begin software architecture and behaviour implementation.

This code has been wrote for STM32 Nucleo L432KC.

## Prerequisites

You need to have an installed and configured [MbedCLI](https://os.mbed.com/docs/v5.7/tools/arm-mbed-cli.html).


## Installation

Use `mbed new .` to create a MBed project with all configurations and dependencies in this repository.

You can now use mbed command to compile these files to get the binary to flash your microcontroller
in <project_dir>/BUILD/<target_name>/<compiler_name>/ :  `mbed compile`

In our case, we used `mbed compile -m NUCLEO_L432KC -t GCC_ARM` to deal with NUCLEO_L432KC with a GCC_ARM compiler
(see [MbedCLI configuration](https://os.mbed.com/docs/v5.7/tools/configuring-mbed-cli.html) page to know which parameters you should use)
