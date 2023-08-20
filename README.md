# pes_asic_class





# Contents
## Day 1
  - [Programs written for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/DAY1)
  - [Running a simple C program](#Running-a-Simple-C-program)
  - [RISCV GCC Compile and Disassemble](RISCV-GCC-Compile-and-Disassemble)
  - [Spike Simulation and Debug](Spike-Simulation-and-Debug)
  - [C Program for highest and lowest signed and unsigned integers](C-Program-for-highest-and-lowest-signed-and-unsigned-integers)

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
