# Interfacing-sg90-servo-motor-with-stm32f407-DISC1

![image](https://user-images.githubusercontent.com/56625259/130080296-e2cd51da-600a-4584-85c7-ff7283a5eb2a.png)


![image](https://user-images.githubusercontent.com/56625259/130080344-4e280f41-d8cb-43d3-a9fe-013cfe64d3b6.png)

The servo motor is controlled by sending a PWM pulse through the orange wire, which is known as the control signal. The duty cycle of the PWM pulse determines the position of the servo motor. At 1 ms the servo motor is at a position of '0' degrees, at 1.5 ms duty cycle the servo motor moves to '90' degrees and so on upto 2ms. This principle is used in the bare metal code written for the stm32f407 Discovery Board.


The connection made here are as follows,
| sg90 | STM32F407 |
|---|---|
| VCC | 5V |
| Control Signal | PA5 |
| GND | GND |
