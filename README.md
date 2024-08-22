# Disclaimer
This is a simulation only example that aids students who do not have the actual kit to start experimenting

# UART_TivaC_Transmit_Receive
A demonstration of the transmission and receiving of data using UART utilizing TivaC-Series microcontrollers

![image](https://github.com/user-attachments/assets/ad0e44ea-653b-4699-9151-5dfe16aaf046)


## Purpose
Getting Familiar with tm4cgh6pm microcontroller, UART protocol, Interrupts and Polling

## Environment
The development environment being used is Keil µVision. This integrated development environment (IDE) combines project management, source code editing, program debugging, and complete simulation in one powerful environment. It is designed to expedite the development process of embedded applications by providing a robust IDE and a comprehensive debugger
<p align="center">
  <img src="https://github.com/user-attachments/assets/3567ea35-6608-4618-9161-8caf3608cf2b" />
</p>

## User Guide 
1- Install [keiluVision](https://www.keil.com/download/) <br />

2- Download *TivaWare* from [TI's official website](https://www.ti.com/tool/SW-TM4C) (Note: needed for getting *tm4cgh6pm* library) <br />

3- Install the packages necessary from package installer (most importantly texas instruments TivaC Series) <br />


![Picture1](https://github.com/user-attachments/assets/f0e9420b-c3f2-4860-b362-fab1168d3bad)

![Picture2](https://github.com/user-attachments/assets/1792fd55-2a78-4b49-95d9-6b5c0ce9be85)

4- Install [CMSIS-framework-for-TM4-Devices](https://github.com/dannyf00/CMSIS-framework-for-TM4-devices)

5- Create a new project in keiluVision

![image](https://github.com/user-attachments/assets/d0480a98-7d8e-44ba-8a14-b8516d695dca)

6- Choose TivaC device

![image](https://github.com/user-attachments/assets/5582392d-42ff-41a7-8668-97ec53a3d7e5)

7- The task is to create an interrupt handler that handles received characters and transform them to upper case if they are lower or send the successive character otherwise.
*Override the UART handler function with your logic* (UART0 is the chosen UART interface from the device)

<img width="452" alt="image" src="https://github.com/user-attachments/assets/f9302d95-75c9-428b-ab21-2ce7df85ada1">

Note: Interrupt handler routine seems to not work in simulator and to install Serillis Virtual Port, you have to connect kit for the pc to detect hardware and install drivers which is implausible if you lack one.

8- Configure Runtime Environment and check Startup checkbox
![Picture3](https://github.com/user-attachments/assets/73d9e68e-68b2-4b29-9a0e-b8bef4496dc8)

9- Use serial terminal to input data

![image](https://github.com/user-attachments/assets/c4a404ee-53b6-44f1-b26b-4cee17fcf28f)






