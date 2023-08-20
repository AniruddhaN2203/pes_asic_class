# pes_asic_class





# Contents
## Day 1
  - [Programs written for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/DAY1)
  - [Running a simple C program](#running-a-simple-c-program)
  - [RISCV GCC Compile and Disassemble](#riscv-gcc-compile-and-disassemble)
  - [Spike Simulation and Debug](#spike-simulation-and-debug)
  - [C Program for highest and lowest signed and unsigned integers](#c-program-for-highest-and-lowest-signed-and-unsigned-integers)

## Day 2
  - [Programs written for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/DAY2)
  - [Application Binary Interface](#application-binary-interface)
  - [Memory Allocation for Double Words](#memory-allocation-for-double-words)
  - [Load, Add and Store Instructions](#load,-add-and-store-instructions)
  - [ABI Names](#abi-names)

# Day 1
- First we look at the introduction to the RISC-V ISA(Instructiion Set Architecture). Supposing we need to execute a C program on a particular hardware. First the C-program is converted into Assembly Code( here for RISC-V processor). Then the assembly code is converted into binary. An RTL implements this code for the particular layout of the RISC-V processor and the output is visible.
- An application running on a system is usually written with the help of a high level language such as C,C++,Python etc. The code of these applications are compiled with the help of compilers running on a system software(OS). The compiler converts the high level code into assembly intructions for the particular processor. The assembler then converts the instructions into binary which is fed into the layout of the chip that processes every pattern of bits and the program is hence run.
## Running a Simple C program
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/4e4d64ae-27cd-4df6-86a4-939135d090c3)
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d60bafa4-30c6-40de-addc-77a7f0ded8ad)

```
DISCLAIMER: ani2203 and aniruddhan are both my own pcs. ani2203 is my second VM and aniruddhan is my third VM.
I made aniruddhan because I hadn't allocated enough RAM for the second pc.
```

## RISCV GCC Compile and Disassemble
Running with the GCC compiler we can compile the program by using the command 
```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-objdump -d sum1ton.o | less
```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/e5841a7a-391c-4580-88a0-d7773f8c7c80)

Typing "main" and then "n", we navigate the the main function of the code and we see the number of steps taken to run the code in assembly.
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ddcd09de-4cb2-43cd-a091-b2cf15f25289)

(101AC - 10184)/4 = A. "A" in decimal is 10, therefore 10 lines on assembly code.

## Spike Simulation and Debug
First we look at a command similar to ```./a.out``` for the riscv compiler. This command is used to show the output which is displayed when the riscv compiler is used. The command is as follows
```spike pk (filename).o```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/aa44b1a7-a039-43c3-bb76-8031a6d19a4c)

Attached below is the main function disassembled:
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/919f6200-cc0a-4971-bae0-84f131ce5ee2)

Now to open the spike debugger we type the following command : ```spike -d pk (filename).o```. If we want the program to run partially till a particular intruction of choice then we can use the following command in the debugger.

```
until pc 0 (line number: eg 100b0)
```

To find the contents of a variable we use the command : ```reg 0 (variable name)```. Hitting the enter key will execute the next line of assembly

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/c8b73195-1f90-4f91-9205-0ad74698d9eb)

## C Program for highest and lowest signed and unsigned integers
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/8c607ae3-1a3f-4840-a053-eccad4bd2188)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/cbe13532-6a4f-4555-a0e1-738a9cb9c1fe)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/9bfef03b-a424-4919-baa3-4bbb4514a12f)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6e3b6e40-05bb-454e-b2b0-fecc34be32b4)


# Day 2
## Application Binary Interface
When an application needs to use the harware resources of a system it is working on, it uses these resources with the help of system calls. These system calls are performed through an interface called the Application Binary Interface(ABI). It is also called the System Call Interface.

## Memory Allocation for Double Words
The length of a register in the RISC-V architecture is 64 bits. There are two different ways to load data into these registers:
  - Loading data directly into the registers
  - Loading data into memory and then into the registers(More effecient and resourceful method).

The memory of the RISC-V processor addresses the data in bytes and follows the little endian storage format. This means that the least significant byte is stored at m[0].

## Load, Add and Store Instructions
**Load Instruction**

The instruction is:
```
ld  x10, 16(x15)
```

Where ld is "load doubleword", x10 is the destination register and x15 is the source register with an offset of 16.

The instruction set is stored an executed as follows:

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/80f9901b-4682-4f87-a765-5a20075d8584)

- A combination of funct3 and opcode stores the ld command which is 3 and 7 bits respectively.
- Destination register x10 is stored as 5 bits in rd.
- Source register x15 is stored as 5 bits in rs1.
- Offset 16 is stored as 12 bits in immediate.

**Add Instruction**

The instruction is:
```
add  x10, x16,x10
```

Where add is add command, the leftmost x10 is the destination register and the rightmost x10 is the source register to which the contents of x16 are added.

The instruction set is stored an executed as follows:

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/c7d1b97f-cc25-407d-b614-0331d29a7382)

- A combination of funct3, funct7 and opcode stores the add command which are 7, 3 and 7 bits respectively.
- The leftmost destination register x10 is stored as 5 bits in rd.
- The rightmost x10 and x16 are the source registers stored as 5 bits in rs1 and rs2.

**Store Instruction**

Used the store data in the memory from the register.

The instruction is:
```
sd  x10, 8(x16)
```

Where sd is store doubleword command, x10 is the data register and x16 is the source register with an offset of 8.

The instruction set is stored an executed as follows:

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/64df0d44-fc1b-4514-97d6-336a3500178d)

- A combination of funct3 and opcode stores the sd command which is 3 and 7 bits respectively.
- The offest 8 is stored as immediate where the first 5 bits are stores in immediate[4:0] and the rest of the zeroes are stored in immediate[11:5]
- The data register x10 is stored in rs2 as 5 bits and source register x16 in rs1 as 5 bits

## ABI Names
These are the names a user uses to access the registers of the RISC-V CPU core.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ec154293-cd7f-4454-9e19-09ff081d992f)
