Toll Barrier System Using Bluetooth (LPC2129)

Project Overview

The Toll Barrier System Using Bluetooth is an embedded systems project developed using the LPC2129 ARM7 microcontroller. The system controls a toll gate barrier using Bluetooth communication.

When a vehicle is detected through an external interrupt, the system prompts the user to send an OPEN or CLOSE command through a Bluetooth module (HC-05). Based on the received command, a servo motor controls the toll barrier position.

An LCD displays the vehicle detection status and barrier status, while Bluetooth communication provides command input and status messages.

Objectives

Automate toll barrier operation using an embedded controller.
Interface an HC-05 Bluetooth module with LPC2129 using UART0.
Control an SG90 servo motor using PWM.
Display system status using a 16x2 LCD.
Detect vehicle arrival using an external interrupt.
Hardware Requirements

LPC2129 ARM7 Development Board
SG90 Servo Motor
HC-05 Bluetooth Module
16x2 LCD Display
LED
Vehicle Detection Sensor / External Interrupt Input
Connecting Wires
Power Supply
Software Requirements

Embedded C
Keil µVision IDE
LPC2129 Microcontroller Header File (LPC21xx.h)
Serial Terminal Application
Bluetooth Terminal Application
Pin Configuration

Component	LPC2129 Pin / Peripheral
LCD Data Lines (D4–D7)	P1.23–P1.26
LCD RS	P1.27
LCD Enable	P1.28
HC-05 Bluetooth TX/RX	UART0 (P0.0, P0.1)
Servo Motor	PWM5 (P0.21)
Vehicle Detection	EINT0 (P0.16)
LED	P0.10
Working Principle

The LPC2129 microcontroller initializes the LCD, UART0, PWM and external interrupt.
The LCD displays the project title.
When a vehicle is detected, External Interrupt 0 (EINT0) is triggered.
The LCD displays VEHICLE DETECTED.
A message is transmitted to the Bluetooth terminal.
The user sends an OPEN or CLOSE command through the Bluetooth module.
The microcontroller receives and processes the command through UART0.
Based on the received command:
OPEN: The servo motor rotates to the programmed 90-degree position.
CLOSE: The servo motor returns to the programmed 0-degree position.
The LCD and Bluetooth terminal display the corresponding barrier status.
File Description

main_function.c Main program, project initialization and external interrupt handling. lcd_header.h LCD initialization, command, data and string display functions. bluetooth_header.h UART0 initialization, Bluetooth data transmission and reception. servo_motor.h PWM initialization and servo motor position control.

Bluetooth Commands

OPEN Opens the toll barrier (90°). CLOSE Closes the toll barrier (0°).

Communication and Control

UART0: Used for serial communication with the HC-05 Bluetooth module.
PWM5: Generates the PWM signal to control the SG90 servo motor.
EINT0: Detects vehicle arrival and initiates the toll barrier operation.
LCD: Displays vehicle detection and toll barrier status.
