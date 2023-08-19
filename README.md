# pes_asic_class





# Contents
# Day 1
- First we look at the introduction to the RISC-V ISA(Instructiion Set Architecture). Supposing we need to execute a C program on a particular hardware. First the C-program is converted into Assembly Code( here for RISC-V processor). Then the assembly code is converted into binary. An RTL implements this code for the particular layout of the RISC-V processor and the output is visible.
- An application running on a system is usually written with the help of a high level language such as C,C++,Python etc. The code of these applications are compiled with the help of compilers running on a system software(OS). The compiler converts the high level code into assembly intructions for the particular processor. The assembler then converts the instructions into binary which is fed into the layout of the chip that processes every pattern of bits and the program is hence run.
## Running a Simple C program
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/4e4d64ae-27cd-4df6-86a4-939135d090c3)
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d60bafa4-30c6-40de-addc-77a7f0ded8ad)

```
DISCLAIMER: ani2203 and aniruddhan are both my own pcs. ani2203 is my
second VM and aniruddhan is my third VM. I made aniruddhan because i hadnt allocated enough RAM for the second pc.
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

# Day 2
