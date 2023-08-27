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
  - [Load Add and Store Instructions](#load-add-and-store-instructions)
  - [ABI Names](#abi-names)
  - [Sum of Numbers From 1 to n using ASM](#sum-of-numbers-from-1-to-n-using-asm)

## RTL design using Verilog with SKY130 Technology - Day 1
  - [Programs used for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/Iverilog_DAY_1)
  - [Iverilog Based Simulation Flow](#iverilog-based-simulation-flow)
  - [Labs Using Iverilog and gtkwave](#labs-using-iverilog-and-gtkwave)
  - [Introduction to Yosys and Logic Synthesis](#introduction-to-yosys-and-logic-synthesis)

## RTL design using Verilog with SKY130 Technology - Day 2
  - [Programs used for the day]()
  - [Introduction to timing libs](#introduction-to-timing-libs)
  - [Hierarchical vs Flat Synthesis](#hierarchical-vs-flat-synthesis)

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

## Sum of Numbers from 1 to n using ASM
We write two programs here, one in C and one in assembly. We process the main part of the program in ASM and display the result through the C program

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/8a90acaf-6545-486d-9232-14fdfb09c312)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6caf6a5d-6d1d-4f9b-b53b-f62aaf8472f5)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/e52d0f6e-ebd5-483f-b4ce-0ad47c7b9514)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/56ddc858-81c1-4421-8900-a09394835113)


# RTL design using Verilog with SKY130 Technology - Day 1
## Iverilog Based Simulation Flow

- First we must have a design code and a test bench and feed both of them to the Iverilog simulator. The simulator is going to look for changes in the input and then accordingly dump the changes in the output. The output of the simulator is going to be a VCD file(value change dump).
- For viewing the VCD file we will use another tool called gtkwave to view the output waveforms, where we can verify the functionality of the design.

## Labs Using Iverilog and gtkwave
**Introduction to Labs**

- First we go into the root users and create a new directory in home called as vsd. In vsd we make a new directory called as VLSI that we will be using for the future lab sessions.
- Next we git clone the link that contains all the programs need to do the labs by using the following command(Must be done in the VLSI folder)
```
git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git
```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d0967659-c2f6-4c54-93c4-d7d3d6dbaec5)

**Introduction to Iverilog and gtkwave**
- Going into the vsd folder and into the VLSI directory we type ```cd sky130RTLDesignAndSynthesisWorkshop/```. This is the directory we will be working with.
- The first program we will be testing will be a 2:1 mux.
- To do this we first have to get into the directory with the file of the design and test bench of the 2:1 MUX.
- ```cd verilog_files/```
- To run the program we can do so by using Iverilog and typing the command:
```
iverilog good_mux.v tb_good_mux.v
```
- As we can see an a.out file is created. We need to run that using ```./a.out```.
- This will make a .vcd file that we can analyze in gtkwave by using the command:
```
gtkwave tb_good_mux.vcd
```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/32c1903a-9c27-4190-9012-a36dd59cd33c)

- In the gtkwave window, we need to click the file name which will display the list of inputs and outputs.
- We can obtain the waveform by dragging and dropping the inputs and outputs in the signals window and clicking zoom fit to see them properly.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a0683603-b2d8-41cd-a97c-3aa281c8e7f5)

The following are the programs we just executed and analyzed the waveform of:

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/36b68412-18bb-4ad0-9281-f08b23f43c72)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d8f5d603-a0a7-422e-a9ee-504c65df3cb2)


## Introduction to Yosys and Logic Synthesis
**Introduction to Yosys**
- Synthesizer is the tool used for converting RTL to netlist and yosys is the synthesizer
- We have a design and a .lib file. Applying both the files to yosys we get a netlist file.
- To verify the synthesis output, we use the netlist file and the testbench file and feed them both to iverilog and we get the vcd file.
- We load the same in gtkwave. The output observed should be same as that observed during RTL simulation.

**Introduction to Logic Synthesis**
- RTL to gate level translation is what we define as synthesis
- The RTL file and the front end library file is put through the process of synthesis to get a netlist.
- The .lib file is a collection of logical modules. It includes the basic logic gates like AND,OR,NOT etc. It also contains different versions of the gate, for example: slow, medium and fast versions of the AND gate.
- Some cells should be fast in order to meet the performance rates and we need some slow cells to meet the "hold" condition.
- If we use too many fast cells, then the circuit may become bad in terms of power and area. There may also be hold time violations
- If we use too many slow cells, the circuit may become sluggish and may not meet the required criteria.

**Lab Using yosys and Sky130 PDKs**
- First of all as usual we go into the directory with the files that we need to work with

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/bf12626d-312e-4697-9b47-2eab9a966d17)

- Now for ease of execution of the programs, we move the ```lib``` folder into the ```my_lib``` folder using the command
```
mv lib my_lib/
```
![Screenshot from 2023-08-26 12-40-39](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/1d1f09c3-c33d-437d-a5a5-788c10915e1e)

- Next we type ```yosys``` to invoke the Yosys tool from the ```verilog_files``` folder.
- Then we use the command
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
along with the appropriate path to the above library file.

- Then we use the command
```
synth -top good_mux
```
to synthesize the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/0eddc264-c8bf-49e7-9803-43b25d9937c5)

- To generate the netlist we now use the command
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
along with the appropriate file path. The logic of good_mux will be realised with the standard cells available in the library file mentioned above. That is the logic of the above command ```abc -liberty```.

- The execution of this command also gives us some important information shown below

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/741c1630-6ce3-4704-abdf-d1e91ed07abf)

- Next we type the command ```show``` to display the synthesized design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/f5efa573-fe12-4432-8957-5bc5298e904d)

- To check the netlist file we use the command:
```
write_verilog good_mux_netlist.v
```
- Any meaningful name can be given to the netlist file.
- Now we type ```!gedit good_mux_netlist.v``` to view the file.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/967281cd-fd51-4a21-bb43-347983761b02)

- To view a neater version of the above program we type the command
```
write_verilog -noaatr good_mux_netlist.v
```

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/8ca12ba3-cb83-4adc-8a44-4ac77d2916d5)

```This version of the program has been attached in the source files.```

- i0 and i1 are our primary inputs, sel is our select line and y is our output.

# RTL design using Verilog with SKY130 Technology - Day 2
## Introduction to Timing Libs

First let us see what is inside the .lib file. We can open it in the following way

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/37d5d45b-8d14-4d45-95e1-1ea630bcd1b7)

Now let us look at what it has to offer.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/3d17ecc4-ed65-44bc-98e4-499e5e8819a4)

- In the first line we can see the name sky130, which means this is the 130nm library
- "tt" means typical. There can be slow, fast and typical libraries
- 025C is the temperature.
- 1v8 is the voltage.
- When we look into a library the phrase PVT should be taken into account.
  - P is process.
  - V is voltage.
  - T is temperature.
- The main reason we look into these three parameters is because the circuit has to work under variations across all of them.
- Line 12 tells us that the technology used is the CMOS technology
- From lines 15 to 20 we can see the units used for each of the parameters, for example time is defined in nano seconds(ns).

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6c482461-23e3-46d9-adcf-f2b2b6e30315)

- A keyword that is used pretty often in the library file is the "cell" keyword.
- There a quite a lot of logic gates defined and also variations of the same type of logic gates.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/9f8106f8-d29c-4d1b-b829-60ca8ee16140)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ac9651e8-5b51-419c-856d-31e8eac45d8a)

- For the above defined cell we can see the corresponding verilog file

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/45eed033-acae-4cda-91c9-53f56a4daed9) ![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/c0129cfe-82f8-4d29-b078-5ea4f5b9d2ec) ![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/e1e8cd23-575c-413d-a8fd-df1d74917591)

- Here the 0,2,4 indicates how wide the transistors are that are used in the following AND gates. Wider the transisistors, more the area and power consumed but also lesser the delay.

## Hierarchical vs Flat Synthesis
The first file that we are going to use to analyze is

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ac8480a1-a566-4791-9f95-56cb18264996)

There are two submodules, one is an AND gate and the other is an OR gate. Let us how they are interconnected

- Let us consider 3 inputs a, b and c.
- Eq 1 -> A&B = Y1
- Eq 2 -> Y1 | C = Y
- Y is the final output.

Let us now synthesize this design. For this we open yosys using the command ```yosys```.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/5f8ae27b-4244-45b6-bf50-b142d46a545a)

- Now we type the command
```
synth -top multiple_modules
```
to synthesize the design.

- On successful synthesizing the following should display

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a24ddcb9-ed4e-49f2-9158-2ba32be872d6)

- We then type the command
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
to link the design to the respective library file.

The following should display on linking

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/49e6c458-1457-4ace-b476-78709b4c6911)

To display the synthesized design we type ```show multiple_modules```. The following figure is displayed.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/fbe9fab3-4cc4-4ab7-ac18-806a215b64b6)

The above design is known as a **Hierarchical Design**. This is because in the usual designs synthesized we expect to see logic gates with connections but here we see the modules which were instantiated as logic gates. The modules themselves act like logic gates by deifinition but it is not displayed so.

Now we can take a look at the netlist file by using the following commands
```
write_verilog -noattr multiple_modules_hier.v
```
This will give us the netlist file in a more readable format. We can now open this file and check its contents

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ba7c9864-4880-4bff-bbe8-14a0e77b00cf)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/c9a3136c-86a3-40f7-aa46-122eb4141c47)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/fe741d57-2cc3-4e8d-8b31-6fd0ecd84029)

The [program](https://github.com/AniruddhaN2203/pes_asic_class/blob/main/Iverilog%20DAY_2/multiple_modules_hier.v) opened from the above command has and AND gate and an OR gate, which have two inpits each respectively.

If we use the command
```
flatten
```
the hierarchies won't be preserved and we will get an even more concise program

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a5405e45-a44b-426c-adff-453cf18eb5ec)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/1f371c9c-21b5-4940-909e-3471bb2b950f)

We get direct instantiations of the AND gate and the OR gate.
