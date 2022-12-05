CN_arduino_miniProject

# 0. Discription
### Arduino Send Messages from Android to LCD with MIT App Inventor

In this project, we will learn how to build an android app that will enable us to send messages to Arduino via Bluetooth to be displayed on a 16×2 LCD. 
This android app will be created with MIT App Inventor. The transmission of the message will be through the HC-06 Bluetooth module.



## 1. Send Messages to Arduino using Android App Project Overview
We will create an Arduino IoT app through HC-06 and MIT App Inventor to display messages on a 16×2 LCD. The android app features a text box which allows the user to type a message to be sent to Arduino. The ‘Send Message’ button will be used to send the message to Arduino via Bluetooth. The message will then be displayed on a 16×2 LCD connected with Arduino.

To enable Bluetooth connectivity, there is a button saying ‘Connect Bluetooth’ that opens a List picker which opens up Bluetooth devices currently paired with the android phone. You can select HC-06 Bluetooth module from the list. Another label saying Bluetooth is Connected or disconnected is also shown on the screen.


![MIT-APP-Inventor-Display-messages-Overview](https://user-images.githubusercontent.com/79437477/187805756-03593213-10b0-470e-9312-48c167c6091a.jpg)


## 2. Liquid Crystal Display Introduction

### Types
They come in two types serial and parallel LCDs. Serial type uses serial communication, such as the UART module, to interface with Arduino. They are easier to interface with Arduino than parallel LCDs. But they are expensive. In contrast, parallel LCDs, for example, Hitachi HD44780, are exceptionally used and interfacing with Arduino is done using digital I/O pins of Arduino. For instance, Hitachi HD44780 type 16×2 LCD can be interfaced with Arduino using 4-8 data lines and few control pins of the display. In this tutorial, we will be using 16×2 parallel LCD only. Because it is the most popular choice among the Arduino community and embedded application developers.

### 16×2 LCD Introduction
There are two types pins on the whole 16×2 LCD module. Some pins are used to send to 16×2 LCD and some are command pins. In other words, every pin has a role in controlling a single pixel on the display.
16 x 2 LCD has sixteen columns and two rows. That means, it can display sixteen characters per row and it has two such rows. Similarly, 20×4 LCD has four rows and 20 columns. That means, it can display 20 characters per row.

### Pinout Diagram
The diagram shows the pin configuration of 16×2 display. It has sixteen pins.

![16X2-LCD-Pinout-diagram-Pic-Microcontroller-tutorial](https://user-images.githubusercontent.com/79437477/187806235-3fef2c6b-ff5c-4166-9e7f-fd2f0136e204.png)

* D0 – D7: Pin number 7-14 are data bus lines that are used to send data from Arduino which you want to display on LCD. With these 8 data lines, data can be transferred either in an 8-bit format or in a 4-bit format. In a 4-bit format, only upper four bits (D4-D7) are used to send data from Arduino to LCD. The full byte is transmitted in two successive transmissions. A 4-bit format is used to save GPIO pins of Arduino. Because fewer GPIO pins of Arduino will be required to transfer data.
Contrast Select (VEE): It will help to control the contrast of PIXELS according to the 16X2 LCD light.
* RS: This pin is known as a register select pin. It helps to toggle the command/data register.
* R/W: The signal on this pin will decide whether it is going to read from LCD or write on it.
* EN: Enable pin will help to transfer the instruction from the data pins and another command pin to the LCD. It act as permission to internal registers.
* VSS: It’s a ground pin for common grounds.
* VCC: The power pin will use for voltage input to the 16X2 LCD.

In Arduino, we don’t need to worry about controlling these data lines and control registers. Because Arduino provides rich library resources. LCD library comes with Arduino IDE by default when we install it.


## 3. Interfacing 16×2 LCD and HC-05 module with Arduino board
We are using the following connections for 16×2 LCD and Arduino as described below. Refer to the schematic diagram to have a clearer idea of the connections.
Follow the connections to connect HC-05 module with Arduino:

* Bluetooth Tx with Arduino UNO Rx (D0)
* Bluetooth Rx with Arduino UNO Tx (D1)
* Bluetooth VCC with Arduino UNO +5V
* Bluetooth GND with Arduino UNO GND
The schematic diagram below shows the connection between 16×2 LCD, HC-06 and Arduino UNO.

![Arduino-with-16x2-LCD-and-HC-05](https://user-images.githubusercontent.com/79437477/187806430-e1e65c5e-b095-4ec6-8e33-8b2b97e64281.jpg)





