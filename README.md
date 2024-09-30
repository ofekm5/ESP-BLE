# ESP-BLE

## Overview

This project implements a BLE (Bluetooth Low Energy) client using an ESP32 microcontroller. The BLE client advertises its services and handles communication with connected central devices. The client offers three characteristics (PropertyOne, PropertyTwo, PropertyThree) that can be read from and written to by the central device.

## Features

- BLE client advertising a custom service with three characteristics (`fff1`, `fff2`, `fff3`).
- Central device can read and write to these characteristics.
- Serial output for monitoring the connection, disconnection, and changes in characteristic values.
- BLE client initialization and automatic advertising.

## Components

- **BLEClient Class**: Manages the BLE client, including initialization, advertising, and handling communication with the central device.
- **BLE Characteristics**: 
  - `PropertyOne` (100 bytes)
  - `PropertyTwo` (10 bytes)
  - `PropertyThree` (20 bytes)
- **Test Sketch**: Demonstrates how to initialize and run the BLE client, advertising its services and handling central connections.

## Prerequisites

1. **ESP32 Board**: Required to run the sketch.
2. **Arduino IDE**: Install and configure it for ESP32 development.
3. **ArduinoBLE Library**: Install the [ArduinoBLE library](https://www.arduino.cc/en/Reference/ArduinoBLE) through the Arduino Library Manager.

## Installation

1. **Clone or Download** this project.
2. Open the project in **Arduino IDE**.
3. Ensure you have the **ArduinoBLE** library installed.
4. Connect your **ESP32** to the computer.
5. Select the appropriate board and port in the Arduino IDE.
6. Upload the sketch to the ESP32.

## Usage

1. Once the sketch is uploaded, open the **Serial Monitor** in the Arduino IDE.
2. Set the baud rate to `115200`.
3. The ESP32 will start advertising its BLE service with three characteristics.
4. You can connect to the ESP32 using any BLE-enabled central device (e.g., a smartphone or another microcontroller).
5. The serial output will display when a central connects or disconnects, and log any changes to the characteristics.

## Code Structure

### BLEClient Class

- `Init()`: Initializes the BLE client and starts advertising the service.
- `Update()`: Monitors connections and handles communication with the central device.
- `FinishedSync()`: Indicates if the synchronization with the central device is complete.
- `getPropertyOne()`, `getPropertyTwo()`, `getPropertyThree()`: Retrieve the values of the corresponding characteristics.

### Sketch Functions

- `setup()`: Initializes the BLE client and starts the advertising process.
- `loop()`: Calls `Update()` to monitor and manage BLE communication.

## Serial Output Example

```
BLE advertising ...
Connected to central: XX:XX:XX:XX:XX:XX
PropertyOne: 12345
PropertyTwo: ABC
Disconnected from central: XX:XX:XX:XX:XX:XX
```

## Customization

- **Device Name**: You can modify the BLE device name in the `setupBLE()` function (`BLE.setDeviceName("MyBLE")`).
- **Characteristics UUIDs and Sizes**: The UUIDs and sizes of the characteristics can be customized in the `BLEClient` constructor.
- **Manufacturer Data**: The raw advertising data can be changed in the `setupBLE()` function.
