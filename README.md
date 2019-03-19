# Simple kernel 

<a href="https://github.com/AnyKeyShik/SimpleKernel/blob/master/LICENSE">
<img src ="https://img.shields.io/github/license/AnyKeyShik/SimpleKernel.svg" />
</a>
<a href="https://github.com/AnyKeyShik/SimpleKernel/stargazers">
<img src ="https://img.shields.io/github/stars/AnyKeyShik/SimpleKernel.svg" />
</a>
<a href="https://github.com/AnyKeyShik/SimpleKernel/network">
<img src ="https://img.shields.io/github/forks/AnyKeyShik/SimpleKernel.svg" />
</a>

This is my first attempt to write something great (again :D)

I want to learn how does OS work and this is main reason why I've started this project.

At this moment system is working in 32-bit protected mode only

When I started I adhered to the following principles:
---
* I don't want to write my own bootloader
* In start I support legacy only (like BIOS, non-gaming[3-buttons] mouse, 128-keybaord, etc)
* (maybe smth else)

# Getting started

#### Requirements

To compile and run this project, you will need:
* the NASM assembler
* the GNU linker
* a Linux x64 operating system

#### Running the code

Simply use the following commands in a terminal:
```
git clone https://github.com/AnyKeyShik/SimpleKernel.git
cd SimpleKernel
make run
```

Features
===
| Module                            | Progress      |
|-----------------------------------|---------------|
| Boot                              | **DONE**      |
| Interrupt handling                | `TODO`        |
| Keyboard support                  | `TODO`        |
| POSIX support                     | `TODO`        |
| Simple analog `libc`              | `TODO`        |
| Memory management                 | `TODO`        |
| Filesystem                        | `TODO`        |
| Basic shell                       | `TODO`        |
| Users                             | `TODO`        |
| Simple text edtiro                | `TODO`        |
| Multiple processes and scheduling | `TODO`        |
| Networking                        | `TODO`        |

### Maybe in future:
* Bash interpreter
* GUI

# Running:
You can running this project with `qemu`. For this you can just run `make run`

# Runtime erros:
* 0 - Mulitboot error
* 1 - CPUID error
* 2 - Long Mode error

### This is new version from scratch. At this moment it's very stupid :)
