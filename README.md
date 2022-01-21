# RISC-V RV32I[MAC] emulator with ELF support

`rv32emu` is an instruction set architecture (ISA) emulator implementing the 32 bit RISC-V processor model.

This repository is intended to replace [sysprog21/rv32emu](https://github.com/sysprog21/rv32emu), which is used in [Computer Architecture course](http://wiki.csie.ncku.edu.tw/arch/schedule). At the moment, the suffix `-next` is used to distinguish between the two repositories.

## Build and Verify

`rv32emu` relies on some 3rd party packages to be fully usable and to provide you full
access to all of its features. You need to have a working [SDL2 library](https://www.libsdl.org/)
on your target system.
* macOS: `brew install sdl2`
* Ubuntu Linux / Debian: `sudo apt install libsdl2-dev`

Build the emulator.
```shell
make
```

Run sample RV32I[MA] programs:
```shell
make check
```

Run [Doom](https://en.wikipedia.org/wiki/Doom_(1993_video_game)), the classical video game, via `rv32emu`:
```shell
make demo
```

The build script will then download data file for Doom automatically. SDL2 based window
should appear when Doom is loaded and executed.

## riscv-arch-test

The RISC-V Architectural Tests, [riscv-arch-test](https://github.com/riscv-non-isa/riscv-arch-test) the basic set of tests that can ensure the riscv model's behaviour that matches RISC-V specifications while implementing specific software.(not a **substitute for rigorous design verification**)

There have **reference signatures** that is generated by the formal RISCV model [RISC-V SAIL](https://github.com/riscv/sail-riscv) and the test files *.elf. The .elf files contain several testing instructions, data, and **signature**.The **test signature** is the specific data location that need to be written during the test. Once the test is executed, the **test signatures** will be written by testing model(rv32emu-next) and it will be compared to **reference signature**.The test will pass if both signatures exactly match.

[riscv-arch-test](https://github.com/riscv-non-isa/riscv-arch-test) is integrated with submodule, and the setup was done.Once the submodule `riscv-arch-test` is pulled, run all the available riscv-arch-test via command:
```shell
make arch-test
```

* To run the tests for specific extension, set the environmental variable `RISCV_DEVICE` to one of `I`,`M`,`C`,`Zifencei`,`privilege`.
```shell
make arch-test RISCV_DEVICE=I
```
* To run a specific test case,set both `RISCV_DEVICE` and `RISCV_TEST`.For example:
```shell
make arch-test RISCV_DEVICE=M RISCV_TEST=div-01
```
The details in setup enviroment variables is in [RISC-V Architectural Testing Framework](https://github.com/riscv-non-isa/riscv-arch-test/blob/master/doc/README.adoc) **5.1 Setup environment variables**.

Detail in riscv-arch-test:
* [riscv-arch-test repository](https://github.com/riscv-non-isa/riscv-arch-test)
* [RISC-V Architectural Testing Framework](https://github.com/riscv-non-isa/riscv-arch-test/blob/master/doc/README.adoc)
* [RISC-V Architecture Test Format Specification](https://github.com/riscv-non-isa/riscv-arch-test/blob/master/spec/TestFormatSpec.adoc)

## Customization

`rv32emu` is configurable, and you can modify `Makefile` to fit your expectations:
* `ENABLE_RV32M`: Standard Extension for Integer Multiplication and Division
* `ENABLE_RV32A`: Standard Extension for Atomic Instructions
* `ENABLE_RV32C`: Standard Extension for Compressed Instructions (RV32C.F excluded)
* `Zicsr`: Control and Status Register (CSR)
* `Zifencei`: Instruction-Fetch Fence

Add `-D` to enable and `-U` to disable the specific ISA extensions.

## Reference

* [libriscv: RISC-V userspace emulator library](https://github.com/fwsGonzo/libriscv)

## License
`rv32emu` is released under the MIT License.
Use of this source code is governed by a MIT license that can be found in the LICENSE file.
