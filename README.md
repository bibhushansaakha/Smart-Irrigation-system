# Smart Irrigation System

### Overview

This repository contains the code and report for the "Smart Irrigation System" project developed by students at Kathmandu University, Department of Computer Science and Engineering. The system is designed to optimize water usage for various applications using an Arduino UNO R3, soil moisture sensor, temperature sensor, and other components.

### Watch Demo:
[![Smart Irrigation System](https://img.youtube.com/vi/KS1PBUdtupY/0.jpg)](https://www.youtube.com/watch?v=KS1PBUdtupY)

### Table of Contents
1. [Introduction](#introduction)
2. [Application Area](#application-area)
3. [Technology and Tools](#technology-and-tools)
4. [Connection with the ICs](#connection-with-the-ics)
5. [Data Flow](#data-flow)
6. [Working Mechanism of Sensors](#working-mechanism-of-sensors)
7. [Estimated Cost Analysis](#estimated-cost-analysis)
8. [Result and Analysis](#result-and-analysis)
9. [Conclusion](#conclusion)
10. [References](#references)

### Introduction

Modern gardening and agriculture involve the artificial application of water to ensure successful production, a practice that is vital and has evolved over nearly 5,000 years. Traditional irrigation methods, such as flood irrigation widely used in Nepal, result in significant water loss. This project addresses the need for efficient irrigation systems that optimize water usage by developing a Smart Irrigation System using an Arduino UNO R3, soil moisture sensor, and other components.

### Application Area

The Smart Irrigation System has diverse applications:
- **Agriculture**: Automates irrigation based on soil moisture levels, reducing water wastage and supporting sustainable practices.
- **Home Gardens and Lawns**: Enhances water conservation and efficiency, making home gardening more sustainable.
- **Sports Fields**: Maintains the quality and safety of various sports fields by ensuring meticulous water management.

### Technology and Tools

- **Arduino UNO R3**: The primary microcontroller.
- **Sensors**: Soil moisture sensor, temperature sensor, potentiometer (simulating humidity), and rain switch.
- **LCD Screen**: For real-time display of system status and sensor readings.
- **LEDs and Buzzer**: For visual and auditory alerts.
- **DC Motor**: Simulating a water pump.
- **Tinkercad**: Used for designing and simulating the circuit.
- **Programming Languages**: C/C++ for writing and uploading sketches to the Arduino.

### Connection with the ICs

- **Analog Inputs**:
  - A1: Soil moisture sensor
  - A2: Temperature sensor (TMP36)
  - A3: Potentiometer (simulating humidity)
- **Digital Inputs**:
  - Pin 2: Rain switch
- **Digital Outputs**:
  - Pin 4: DC motor (water pump)
  - Pin 8: Buzzer
  - Pin 12: Green LED
  - Pin 13: Red LED

Detailed connections are outlined in the report.

### Data Flow

The system processes sensor data to make informed decisions about irrigation:
- **Sensor Data Collection**: Soil moisture sensor, temperature sensor, potentiometer, and rain switch.
- **Data Processing**: Reading sensor values, converting and mapping them, and printing values to the serial monitor and LCD display.

### Working Mechanism of Sensors

- **Soil Moisture Sensor**: Measures the volumetric content of water in the soil.
- **Temperature Sensor (TMP36)**: Measures ambient temperature.
- **Potentiometer**: Simulates humidity levels.
- **Rain Switch**: Detects the presence of rain.

### Estimated Cost Analysis

| Equipments          | Quantity | Cost per Unit | Total Cost |
|---------------------|----------|---------------|------------|
| Arduino UNO R3      | 1        | Rs 1500       | Rs 1500    |
| Soil Moisture Sensor| 1        | Rs 250        | Rs 250     |
| Temperature Sensor  | 1        | Rs 250        | Rs 250     |
| Potentiometer       | 1        | Rs 80         | Rs 80      |
| Switch              | 1        | Rs 60         | Rs 60      |
| LCD Screen          | 1        | Rs 1500       | Rs 1500    |
| LEDs                | 2        | Rs 20         | Rs 40      |
| Buzzer              | 1        | Rs 125        | Rs 125     |
| DC Motor            | 1        | Rs 500        | Rs 500     |
| Breadboard & wires  | 1        | Rs 400        | Rs 400     |
| **Total**           | **11**   |               | **Rs 4705**|


### Result and Analysis

The Smart Irrigation System was successfully simulated using Tinkercad, demonstrating its potential effectiveness in real-world applications. Key outcomes included accurate detection of soil moisture levels, effective control of the water pump, and reliable environmental monitoring.

### Conclusion

The Smart Irrigation System offers an efficient and automated solution for managing water usage in various applications. It ensures optimal watering based on real-time data, conserving resources and promoting healthier plant growth. Future enhancements could include remote monitoring capabilities and scalability options for larger setups.

### References

- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [Adafruit LiquidCrystal Library](https://github.com/adafruit/Adafruit_LiquidCrystal)
- [ThingSpeak](https://thingspeak.com/)
- [Tinkercad](https://www.tinkercad.com/)

---
