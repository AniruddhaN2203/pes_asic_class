# pes_asic_class





# Contents
## RISCV - Day 1
  - [Programs written for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/DAY1)
  - [Running a simple C program](#running-a-simple-c-program)
  - [RISCV GCC Compile and Disassemble](#riscv-gcc-compile-and-disassemble)
  - [Spike Simulation and Debug](#spike-simulation-and-debug)
  - [C Program for highest and lowest signed and unsigned integers](#c-program-for-highest-and-lowest-signed-and-unsigned-integers)

## RISCV - Day 2
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
  - [Programs used for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/Iverilog%20DAY_2)
  - [Introduction to timing libs](#introduction-to-timing-libs)
  - [Hierarchical vs Flat Synthesis](#hierarchical-vs-flat-synthesis)
  - [Various Flop Coding Styles and Optimization](#various-flop-coding-styles-and-optimization)
  - [Interesting Optimizations](#interesting-optimizations)

## RTL design using Verilog with SKY130 Technology - Day 3
  - [Programs used for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/Iverilog%20DAY_3)
  - [Introduction to Optimizations](#introduction-to-optimizations)
  - [Combinational Logic Optimizations](#combinational-logic-optimizations)
  - [Sequential Logic Optimizations](#sequential-logic-optimizations)
  - [Sequential Optimizations for Unused Outputs](#sequential-optimizations-for-unused-outputs)

## RTL design using Verilog with SKY130 Technology - Day 4
  - [Programs used for the day](https://github.com/AniruddhaN2203/pes_asic_class/tree/main/Iverilog%20DAY_4)
  - [GLS Synthesis Simulation Mismatch and Blocking NonBlocking Statements](#gls-synthesis-simulation-mismatch-and-blocking-nonblocking-statements)

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

Now if we type the ```show``` command after the ```flatten``` command we see this:

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/234af1f7-f79e-4a61-b492-bc40d3bd5b38)

When we flatten we directly see whole structure of the circuit. This is not the case when we execute show with the previuos command. Previously the logic gates were shown as sub modules but here they are flattened out into the basic gates.

**Sub Module Level Synthesis**

- Here we will try to synthesize one of the sub modules of the complete design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/3eb3650f-9407-4c5e-beb2-36ea4cb90b2a)

- We invoke yosys with  the ```yosys``` command as usual.
- Then we use the ```read_verilog``` command to read the same multiple_modules.v file.
- ```synth -top sub_module1``` is used to synthesize the design of the first sub module(here the AND gate).

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/5dc097aa-27e2-401e-95ea-9907dda0d7ec)

- From the above statistics we can infer that only one AND gate exists.
- We then use the ```abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib``` command to link the library to the synthesis.
- Now typing the ```show``` command we can see the synthesized design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/4bf475e3-4fcf-4717-8639-0cb6854ad38d)

We shall now see, why the synthesizing of sub modules is important. If we need to synthesize a very big design that the tool is not able to synthesize all at once effeciently, we can synthesize the parts one by one, gather the netlist files and then combine them together to get the final result. This can also be useful when debugging for problems. When we also have multiple instances of the same module it is helpful.


## Various Flop Coding Styles and Optimization

**Why do we need Flops?**
- Flops are fundamental parts of digital circuits that help in preventing glitches and thereby endure smooth operation of the circuit.
- Glitches are basically temporary changes in a digital signal that are unwanted. They can lead to incorrect behaviour and malfunction of the circuit.
- Flops help prevent glitches by providing a control and synchronization for holding and propagating changes in signals in the circuit.

**Different Types of Flops**

For looking into flops further we access all our programs from the same directory as before

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/b4ce7aca-56de-4600-aa41-3c50156834e7)

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/7069fea4-aa62-4ee4-9cb6-9bada5581bdb)
- The above program is that of an Asynchrous D Flip Flop.
  - When there is positive edge on the async_reset the output value is set to 0 and this can happen whenever during the operation of the circuit.
  - There is another else condition that states that the output should be 'd' if there is a positive edge on clk and not on the asynchronous reset.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/2bdb83e6-fcd0-445c-acc7-222c534f8605)
- The above program is that of an Asynchrous D Flip Flop.
  - When there is positive edge on the async_set the output value is set to 1 and this can happen whenever during the operation of the circuit.
  - There is another else condition that states that the output should be 'd' if there is a positive edge on clk and not on the asynchronous set.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/f997665d-ff1a-4bc2-9792-367ab48ebc68)
- In this case the reset will not activate unless there is a positive edge of the clock. Here the reset is not mentioned in the sensitivity list and hence it does not hold authority to enter the always block on its own.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a74dd581-744c-404f-8e73-62534b4ce142)
- The above is an example of a case with both asynchronous and synchronous reset.
  - We always enter into the always block if there is a positive edge on the clock.
  - If there is also a postive edge on the async_reset, then this is an asynchronous reset operation.
  - If this is not the case and the always block is entered only on posedge of the clock, then the value of sync_reset will determine whether to reset the flop synchronously or not.
  - Otherwise the output just gets the value 'd'.
 
**Flop Synthesis Simulation**
First we will now see the waveform of the Asynchronous D Flip Flop using Iverilog and gtkwave.

To start this process we first type the command
```
iverilog dff_asyncres.v tb_dff_asyncres.v
```
Next we type ```./a.out```.

Now we get a vcd file that we must use to open the waveform with the command
```
gtkwave tb_dff_asyncres.vcd 
```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6a53fad3-3285-4741-9d54-59725b947a47)

Now if we set all the inputs and zoom in on a part for easier verification, we can see the following

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/44c5d03f-70b8-48a3-a550-e91f5e0d754c)

Here we can clearly notice that when the clock is postive and asynch_reset is high, it sets the output to 0 regardless of the value of 'd' at that moment

We perform the same Iverilog operations in the Asynchronous D Flip Flop with an asynchronous set value and obtain the following waveform

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/3c538c16-0f16-4dd2-885b-f7a00abe617c)

Here we can see that regardless of d becoming 0, as long as the async_set is 1 even the output is retained at 1.


Let us now look at the waveform of the Synchronous reset. We first type the command
```
iverilog dff_syncres.v tb_dff_syncres.v
```
Next we type ```./a.out```.

Now we get a vcd file that we must use to open the waveform with the command
```
gtkwave tb_dff_syncres.vcd
```
Looking at the waveform

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/21e6e9e6-cc6c-4b9d-aff8-11f1b77f820c)

We can see that although sync_reset goes high, the output remains the same until there is a posedge on the clock. At the posedge the condition as to whether sync_reset is high or not and hence the output notices a change.

**Synthesizing the Modules**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ce357e00-fe7a-4787-9867-4d8e237c0362)

- We open yosys using the command ```yosys```.
- Let us read the verilog file with
```
read_verilog dff_asyncres.v
```
- Now for the initial synthesis command we type
```
synth -top dff_asyncres
```
- Since we are using D Flip Flops, we are supposed to use a keyword here dfflibmap.
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
This is end message it must display.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/c81c2158-3b1a-4b04-9e90-95cc332b05dd)

Now we link the library file to the design as usual with 
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Now typing ```show``` should display the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/b2a8f2c7-57b7-4449-8f22-6646b9e48c83)

The flop was written with an active high reset but the model is an active low here, so hence the inverter to convert it into the desired design.

To synthesize the design for a set Flip Flop we follow the same steps above for the file
```
dff_async_set.v
```
We get the following design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/e68ed82f-f660-45f3-b9de-42ebef78bf00)

Here also an inverter is added to make the existing active low model, active high according to our needs

I---------------------------------------------------------------------------------------------------------------------------------------I

Now we synthesize the D Flip Flop with Synchronous reset.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/68999183-714d-4443-951a-9c92eff40b59)

We use the same commands as mentioned above to read the verilog and synthesize the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/729533b9-0d5e-4edc-9640-fd1be061c437)

We use dfflibmap as this is Flip Flop.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d29b0e63-7ba0-4c7d-b5af-7ed507ed1a85)

This is what should display after the execution of the dfflibmap command and then we should link the library file as usual.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/70e5f636-f5b8-4f31-82a2-bc0c04e958a6)

The results are displayed and then we use ```show``` to display the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/f5463f03-8b72-4aed-a6ed-effbbde56d58)

- As we can see the D Flop on the right has no set or reset pin.
- We also have an inverted input A_N.
- Expression of the equation before the Flop is (sync_reset)'.d.

## Interesting Optimizations

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/f8e2f4ae-5998-4df8-821d-8421c40f157e)

- The first program that we will be working with is a program that takes a 3 bit input and gives a 4 bit output.
- If we do the math for an example lets say 3 * 2 = 6.
- 3 in binary is 011(3 bits)
- 6 in binary is 0110(4 bits)
- As we can see a zero is appended to the previous binary number.
- Let us look at what design it synthesizes.

- We start yosys with ```yosys```.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/409fbfa7-c1e0-48b4-bb29-41ce5e85989d)

- We use the same commands as before to read the file mult_2.v and then we synthesize it with the command ```synth -top mul2```.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/17d0ddf8-a95e-4fac-a470-04373aec8ea1)

- As we can see from the above results no hardware is generated

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/130f3928-4af5-4d7b-9a19-fc307013fd7d)

The linking command also doesn't work as there is nothing to link the cells to.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/2d84b508-d998-420c-9c06-92205c73215a)

Here in the design we can see that a 0 is appended to 'a'. This is seen below [2:0 - 3:1] and we get the desired output.

To get the netlist file we type
```
write_verilog -noattr mul2_net.v
```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/9e98814d-d5d6-4763-8053-6ebf72613137)

As we can see, a 0 is appended to 'a'.

I----------------------------------------------------------------------------------------------------------------I

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/2dfb8e52-5103-4f3e-9838-d7d7874ff046)

- The second program that we will be working on is the above.
- Here a is a 3 bit input and y is a 6 bit output.
- The relationship between a and y is that "a*9 = y".
- This we can spilt as "(a*8) + (a*1) = y".
- a*8 will give is a000.
- In the place of these 3 zeroes we get 'a' on adddition.
- Thus the output is aa.

  ![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d97fc1ec-25eb-48de-a36d-6e6ada69ce61)

- We read the file and synthesize as usual.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ed1430ac-46e8-4377-9093-7e6334f4e9a7)

- We can see that no hardware is synthesizzed and hence the abc command rejects the linking of cells
- We type ```show``` to display the figure.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/daf97bd5-2537-40ee-8bcc-7498f93a3871)

- 2*2:0 - 5:0 is exactly the same as displaying 'aa'. Hence the output is verified.
- We look at the netlist file below
```
write_verilog -noattr mult8_net.v
```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/8e0d6e78-47dc-4c91-8f7d-215be177c18f)

As we can see y is a concatenation of 'aa'.

# RTL design using Verilog with SKY130 Technology - Day 3
## Introduction to Optimizations

**Constant Propagation and Boolean Logic Optimization**
- Constant propagation occurs when a value that is a 0 or 1 propagates down the path of a circuit to give us an effecient version of the existing circuit through which it is propogating.
- Boolean logic optimization is done by synthesis tools to get a very optimized logic that can be implemented effeciently and easily. For example the equation "assign y = a?(b?c:(c?a:0)):(!c)" reduces to something as simple as "y = a&c".
- Constant propogation occurs in sequential logic circuits also; but only if the immediate output of the logic circuit is a constant value. Then it can be optimized.

## Combinational Logic Optimizations
Now let us look at some programs here. First we perform the following steps as usual and get into the required directory

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d67f51d4-8e3d-4838-9472-1c9dc5efe2ed)

**Our first program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/1cc8a24f-b3f7-48f1-811d-b2f57a15de2a)

- The above programs is a 2:1 MUX.
- When 'a = 1' 'y = b'; when 'a = 0' ' y = 0'.
- The equation is as follows: y = a.b + a'.0 = ab.

Now we synthesize this design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/50c02d6c-7578-4c91-bdf5-54d48666d61c)
- We invoke yosys with the ```yosys``` command.
- we import the cells from the library file using
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Then we read the file using the command ```read_verilog opt_check.v```.
- Next we synthesize the design using ```synth - top opt_check```.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/20693ed6-4a6d-4c9b-8e2a-ec92f27bfafe)

- The following should be displayed on execution.
- Now we need to type a command to do the constant propagation process. This removes all unused cells and optimizes the design.
```
opt_clean -purge
```
- To link the library files to the design we type
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/c9ede176-be34-4cd6-8bf2-86290246d3b5)

- This shows the following results and then we can type ```show``` to display the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d9e446f8-3c7a-4629-afc5-1076dd941df9)
- The above design complies with the equation of the AND gate that we obtained


I--------------------------------------------------------------------------------------------------------------------I

**The second program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/4864ee17-50e3-4f0c-832d-1bdbd969feb4)

- The above programs is a 2:1 MUX.
- When 'a = 1' 'y = 1'; when 'a = 0' ' y = b'.
- The equation is as follows: y = a + a'.b = a + b.
- **This is the Absorption Law.**

Let us synthesize this design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a444b389-c362-41ce-bc3e-664292e838db)
- First we read the verilog file: ```read_verilog opt_check2.v```.
- Then we synthesize the design: ```synth -top opt_check2```

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6abc75d6-6c91-4651-83e0-350055566da7)

- The above figure confirms that there is an OR gate cell that is generated.
- Next we type ```opt_clean -purge``` for constant propagation and removing unused cells. This optimizes the design.
- To link the library files to the design we type
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Then we type ```show```.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a63f07a0-7b18-46b4-9c7a-0048325eef00)
- The above design complies with the equation and an OR gate is generated.

I--------------------------------------------------------------------------------------------------------------------I

**The third program is as follows:**

![Screenshot from 2023-09-01 00-54-53](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/70bc7ef0-d475-4ac9-8475-a716ba09319c)

- The above program has two 2:1 MUX, the output of the first one is connected as one of the inputs of the second MUX.
- When 'a = 1', 'c?b:0' is chosen.
  - When 'c = 1', 'b' is chosen, else 0 is chosen.
- When 'a = 0', 0 is chosen.
- Final equation is simplified to: y = a'.0 + a.(c'.0 + c.b) = a.b.c

Let us synthesize this design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/57488a84-92bc-4f26-b9b1-b9b9e74903b9)
- Use the same commands as mentioned above.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/b91a609c-31c4-499e-a201-e53ad93bef03)
- The above results should be displayed.
- Then we use the command ```opt_clean -purge``` to initiate constant propagation.
- We link the library file to the design.
- Then we type ```show``` to display.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/addb062a-fc3c-40c2-a057-90216307af07)
- The above design complies with the equation and a 3 input AND gate is generated.

I--------------------------------------------------------------------------------------------------------------------I

**The fourth program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/1b12cfd8-7490-4b4b-944c-b65bcd28c56f)

The working for the above program is done by me in the below picture.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d51905e1-0d1b-491b-a7cc-718bc7ca5349)working

- As we can see the final equation is independent of 'b' and is only dependent on 'a' and 'c'.
- The final expression for y2 is that of an XNOR gate.

Let us synthesize this design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/f9d084ba-a3a6-4421-9777-98161dafe320)
- Use the same commands mentioned above as for the previous programs.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d07d2daa-2185-4da4-9922-dd15e9d439d2)
- The above results should be displayed.
- Then we use the command ```opt_clean -purge``` to initiate constant propagation.
- We link the library file to the design.
- Then we type ```show``` to display.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/484b9d9d-b44d-4466-8483-d96874f32512)
- As we can see the above figure complies with the fact that the final equation is independent of 'b' and has generated an XNOR gate with 'a' and 'c' as the inputs.

I-------------------------------------------------------------------------------------------------------------------I
 
**The fifth program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/89ea24d6-8bdf-49b6-91b7-08eaf58500cc)

- Here we can derive the equation as follows and check it later by synthesizing the design.
- n1 = a.1
- n2 = n1 ^ 0
- n3 = b^d
- y = c + b.a

Let us synthesize this design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/e8237e96-e2b5-4f94-9fe9-d251533ad542)
- First we imported the required cells from the library file.
- We use the command
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Use the same commands mentioned above for reading the verliog file and synthesizing the design as done in the previous programs.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/88a358ec-09c8-43cb-9ca5-e08a926f24f1)
- The above results should be displayed.
- Now since there are multiple modules we first use the command ```flatten``` before using the command ```opt_clean -purge``` for constant propagation. This will remove the hierarchies and when we display the final design it will display as a gate level synthesis.
- We link the library file to the design.
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Then we type ```show multiple_module_opt``` to display the required synthesis, since there are other sub modules in the file as well.

  ![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/7ac6e40e-c028-40fd-ae58-7cf44d81ea74)
- Here the final output 'y' is independent of 'd'.
- As required 2 inputs 'a' and 'b' have been put through the AND operation and the result of that has been put through the OR operation with 'c'.

I-------------------------------------------------------------------------------------------------------------------I

**The sixth program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ccd5ca73-6c1d-4581-a8f9-2e24e670947e)

- We derive the equation of the above design.
- n1 = a.0 = 0
- n2 = b.c
- n3 = b.c.d
- y = b.c.d.0 = 0

Let us synthesize this design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/18cdc6fd-efa3-4987-bd9b-335a3174cdb5)

- First we imported the required cells from the library file.
- We use the command
```
read_liberty -lib ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Use the same commands mentioned above for reading the verliog file and synthesizing the design as done in the previous programs.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/fa372740-a075-439e-a22f-fb1289b371f7)

- We use the ```flatten``` command to get rid of hierarchies and display at gate level. Then we use the ```opt_clean -purge``` for constant propagation.
- We then link the library file to the design using the command
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Then we type ```show multiple_module_opt2``` to display the select module.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a60111d3-a029-4b18-a01a-9794736357a2)
- Here the final output 'y' is mapped to 0, which is what we derived in the above eqations.
- 'y' is independent of all other inputs.

## Sequential Logic Optimizations

**The program that we will be looking at first is this:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/3ba2abc0-d20f-438e-b281-8cb3836e86ea)
- The working of the program obove is as follows.
- It is a D Flip Flop with a reset and D = 1 always.
- If Reset is active the output is always 0.
- If Reset is not active, then only on positive edge of the clock the output is D = 1.

Let us now look at the waveform simulation.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/5c53f6c9-3b1f-46b8-8ddf-fb59b2c53fd1)
- First we use the iverilog command to read both the design and the test bench code
```
iverilog dff_const1.v tb_dff_const1.v
```
- Now we type ```./a.out```. The vcd file is generated. We can open this on gtkwave using the command
```
gtkwave tb_dff_const1.vcd
```

The waveform is as follows:

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/5273df65-9157-4c94-b5d1-86989b88a406)
- As we can see as long as Reset is 1, the output 'q' is 0.
- When Reset is 0 and even the clock being 0, the output does not change yet.
- Only when the clock is 1, the output 'q' is also 1.

Now we synthesize the design using yosys.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/8aaf441e-d53e-4f8c-ac70-e1681a102c23)
- We import the cells and read the verilog file as usual using ```read_verilog dff_const1.v```.
- Then we type ```synth -top dff_const1``` for synthesizing the design.
- The output should be as follows

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/649baa74-938d-44a4-a2ea-c71f2e7dd654)
- We use the command
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
since we are using a flop here.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d4de6ef2-7c8d-4c68-8714-710904bd896a)
- The following should be the result and the we link the library file to the design using the command
```
abc -liberty ../my_lib//lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
- Then we type ```show``` to view the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6a2e962f-9be3-4a2a-9849-9a5619862a94)
- The DFF is visible on the right with a Reset, clk and D pins.
- Reset is expected to be active low, but since we have given an active high Reset, there is an inverter that is used by the tool to do the job.

I---------------------------------------------------------------------------------------------------------------------I

**The second program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/48c202e9-33a4-4a18-9daa-c070ba67b4fb)
- It is also a D Flip Flop with a reset(it acts like a set since it is set to 1) and D = 1 always.
- If Reset is active the output is always 1
- If reset is not active, then even on postitive edge of clock the output remains 1.
- Hence in any case whatsoever the output is always 1.

Let us look at the waveform simulation.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/72c2286d-f7bf-409c-aa9f-b5f5dbf4218c)
- Follow the same steps as the first program.
- Use the command
```
gtkwave tb_dff_const2.vcd
```
to check the waveform diagram.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/98b7f7a2-6b52-4111-af3b-63cb22a0492c)
- As we can see, the output 'q' remains equal to 1, no matter what state the Reset or clock is at.

Now we synthesize the design using yosys

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/ab8a42f1-c349-4e28-90d7-f56777ccda89)
- We use the same commands as above to read and synthesize the design.
- Since we have already used the command,
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
we don't have to call it again.

![Screenshot from 2023-09-02 00-20-26](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6507195c-60df-4386-9b58-d94003cecfea)
- The following result is displayed.
- The linking of libraries doesn't work here as no cells are generated.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/b076d899-879d-4a75-857c-73a05a8345e0)
- The output is a constant 1. Hence we don't have any flip flops or other cells here in the design.

I---------------------------------------------------------------------------------------------------------------------I

**The third program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/20ba307e-b12c-4df6-a02d-350289260d16)
- This program has two Flops.
- The output of one flop is connected to other and the both have to sane Reset and clock signal.

Let us look at the waveform simulation.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/1a78647b-7826-4aef-8fc2-e1bcbb865bb8)
- We run the same Iverliog commands as before to read the files and generate the a.out file.
- Running the vcd file in gtkwave we obtain the following waveform.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/f3193573-8f23-499f-92d8-0f170216234c)
- 'q' is low only for one cycle of its entire duration because of the T(clock to q) delay.
- 'q1' activates to a high value after a slight delay when to clock has a positive edge.
- During this delay 'q' remains 0 and hence, for one clock cycle it stays in the same state until the next positive edge of the clock.

Now we synthesize the design using yosys

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/eb14a510-4d4a-4538-8e4e-7e73db93e57a)
- We import the cells to be used from the library file.
- We use the usual commands to read the verilog file and synthesize the design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/fea1e918-6771-4e9c-83f2-c72b20b0c35e)
- These are the results displayed. As we can see two Flops are generated.
- Then we use the command
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
since we are dealing with flops.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/08026675-8713-450d-9dcd-62e4bff5940c)
- These are the results displayed. Then we link the library file to the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/fb36b78a-68ff-4596-a76a-2f1068556323)
- We type ```show``` to view the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/e8180209-547b-4c12-a783-75bc4040a017)
- As we can see there are two flops. Output of the first in connected the second one and both have the same clock and reset.

I---------------------------------------------------------------------------------------------------------------------I

**The fourth program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/b0b84a7d-aeb9-42e0-8082-0dcd1f9b7f43)
- This program has two flops.
- The output of the first flop is connected to the input signal of the second flop. They both have a similar clock and a Reset signal

Let us look at the waveform simulation.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/3072f863-b166-45fc-aa4f-495fc385955e)
- We run the same Iverliog commands as before to read the files and generate the a.out file.
- Running the vcd file in gtkwave we obtain the following waveform.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/741ead01-5b9f-4f18-9dc4-675b18e40c9d)
- As we can see the output 'q' is always 1.
- If Reset is high, then both 'q' and 'q1' are set to 1
- When Reset is low, 'q1' is set to a high value. Since even during the T(clock to q) delay 'q1' was 1, 'q' remains at 1.
- Hence 'q' is 1 during the whole cycle.

Now we synthesize the design using yosys

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/c33ad07d-f960-423c-9e21-563db1275dc6)
- We import the cells to be used from the library file.
- We use the usual commands to read the verilog file and synthesize the design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/96495896-2f0e-4288-9103-244b5dfdf7ae)
- These are the results displayed. As we can see no cells are generated.
- Then we use the command
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
since we are dealing with flops.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/0d6fe6e5-dd3c-4872-96a6-6c85e3f83a26)
- These are the results displayed.
- Linking the library file to the design doesn't work becuase no cells are generated
- We then type ```show``` to display the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/25ee8e98-7d72-43a1-85bf-f287cfa05cf5)
- As we can see both 'q' and 'q1' have a constant value of 1 throughout the execution cycle.

I---------------------------------------------------------------------------------------------------------------------I

**The fifth program is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/0bc0a3e5-856c-4b20-938b-0d5b7b4b1928)
- This program has two flops.
- The output of the first flop is connected to the input signal of the second flop. They both have a similar clock and a Reset signal.

Let us look at the waveform simulation.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a22e187e-145d-4f41-be8b-73b9a43a9ae8)
- We run the same Iverliog commands as before to read the files and generate the a.out file.
- Running the vcd file in gtkwave we obtain the following waveform.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/b6096cb9-13e2-4aa6-8298-0fe19b9fbc15)
- When Reset is high, we can see that both 'q1' and 'q' are low.
- When Reset is low,'q1' goes to 1 on the positive edge of the clock.
- Due to t(clock to q), 'q1' essentially remains at 0 during the positive edge of the clock.
- Hence 'q' remains 0 for that cyle and goes to value 1, one cycle late compared to 'q1'.

Now we synthesize the design using yosys

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/07b3cbd2-4426-425a-b0b6-96e00f51771d)
- We import the cells to be used from the library file.
- We use the usual commands to read the verilog file and synthesize the design

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/22c7bed5-d0d4-4bfa-8a91-bbb24ee0e136)
- These are the results displayed. As we can see, we have two Flops being generated during synthesis.
- Then we use the command
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/bfcf27e2-427c-4ee9-971a-7c596f15c91f)
- These are the displayed results.
- We then link the library file to the synthesized design.
- We then type ```show``` to display the results.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/64f1e86e-5e3a-48d7-ac1f-181f9347d1ba)
- As we can see there are two flops. Output of the first in connected the second one and both have the same clock and reset.
- Inverter is seen as the synthesis expects an active low Reset. We give an active high reset. This is converted by the tool to active low with inverters

## Sequential Optimizations for Unused Outputs

**The first program we will be looking at is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/daf00bb9-aef9-45dc-a86c-176e61b5e09a)
- This program represents a 3-bit up counter
- The output gives priority to only one of the 3 bits.
- The other two bits are essentially unused.

Now let us synthesize the design on yosys

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/da0c9745-036f-447e-a2b5-c27ad22dfb93)
- We import the cells from the library file and read the verilog file of the required command.
- Now we synthesize the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/150c554d-e184-466b-a383-dd5549122ea4)
- These are the results displayed. Only one Flop is synthesized.
- Then we use the command
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
since we are dealing with flops.
- Now we link the library file to the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6dae064f-2e74-4cf8-bf9d-dc5e384bd49a)
- These are the displayed results.
- Now we type ```show``` to display the results.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/30537cc7-1316-4c5e-aec2-ade85a11039a)
- We can see that there is only one Flop according to the report.
- The 'Q' pin is connected to the bit 0, which is the count. That 'Q' pin is connected to 'q' which is our output.
- It is also going to an inverter which is coming back as an input to the Flop. This is like a toggle state since 0th bit of count always toggles.
- The two unused bits are completely optimized, since they are not connected directly to any primary output.

**The second program we will be looking at is as follows:**

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/72b0e0fe-9d10-40d4-92a4-3c838b2e5fe4)
- This program is a modified version of the previous program.
- In this all thre bits are mapped with an expectation to get 3 synthesized flops.

Now let us synthesize the design on yosys.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/a62f3c61-0d23-434c-98ac-a8ac8285b57a)
- We import the cells from the library file and read the verilog file of the required command.
- Now we synthesize the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/73948679-7c9e-490c-ab19-7018beb5832c)
- These are the results displayed. As we can see 3 Flops are synthesized.
- Then we use the command
```
dfflibmap -liberty ../my_lib/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
```
since we are dealing with flops.
- Now we link the library file to the design.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/d49c5c1e-95bf-43dd-9054-e9d177f574f1)
- These are the displayed results.
- Now we type ```show``` to display the results.

![image](https://github.com/AniruddhaN2203/pes_asic_class/assets/142299140/6029e9e7-eefb-49aa-afe2-66a89aca6a70)
- As we can see there are three Flops.
- Each Flop has a bit connected to to it.
- Each bit is coming to the adder logic present in the middle of the design.
- The NOR gate from which the output 'q' comes out has connections from all three bits at A, B and C(inverted).
- The desired output required is q = count[2].count[1]'.count[0]'

# RTL design using Verilog with SKY130 Technology - Day 4
## GLS Synthesis Simulation Mismatch and Blocking NonBlocking Statements
