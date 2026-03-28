# Temperature-Sensor-using-TMP117

# Multi-Sensor Lab Temperature Logger

A custom-built Arduino hardware solution for monitoring multi-point temperature data inside a laboratory environment. [cite_start]This system simultaneously tracks data from five high-precision TMP117 sensors and streams the live results directly to Microsoft Excel via the Data Streamer add-in[cite: 45, 140, 200].

## 🚀 Features

* [cite_start]**Multi-Sensor I2C Workaround:** Because TMP117 sensors often share the same hardware I2C address (`0x48`), this project utilizes the `SoftwareWire` library to create 5 distinct software I2C buses[cite: 37, 62].
* [cite_start]**Shared Clock Architecture:** To save Arduino pins, all 5 sensors share a single Clock (SCL) line, utilizing separate Data (SDA) lines[cite: 38, 144, 145].
* [cite_start]**Live Excel Streaming:** Data is continuously piped over the Serial port as comma-separated values (CSV), pre-formatted for live plotting in Excel [cite: 84, 177, 201-206].
* [cite_start]**Smart LCD Display:** Features a paginated 16x2 I2C LCD that automatically cycles every 3 seconds to display the live readings of all 5 sensors without using `delay()`, ensuring the data stream remains uninterrupted [cite: 207-217].

## 🛠️ Hardware Requirements

* [cite_start]1x Arduino Uno (or compatible board) [cite: 4, 137]
* [cite_start]5x TMP117 High-Precision Temperature Sensors [cite: 140]
* [cite_start]1x 1602A LCD Screen with I2C Backpack [cite: 135]
* [cite_start]Breadboard and jumper wires [cite: 3]

## 🔌 Wiring Guide

### Power Hub (Breadboard Rails)
* **3.3V Rail:** Connect Arduino 3.3V to the breadboard positive rail. [cite_start]Plug all 5 sensor VCC (Red) wires here[cite: 133, 141].
* **GND Rail:** Connect Arduino GND to the breadboard negative rail. [cite_start]Plug all 5 sensor GND (Black) wires here[cite: 134, 142].

### The 5 TMP117 Sensors
* **Shared Clock (SCL):** Connect all 5 sensor Yellow wires to the exact same horizontal row on the breadboard. [cite_start]Run a single jumper from this row to **Arduino Digital Pin 8** [cite: 143-145].
* [cite_start]**Data Lines (SDA - White Wires):** * Sensor 1 ➔ Arduino Digital Pin 7 [cite: 147]
  * [cite_start]Sensor 2 ➔ Arduino Digital Pin 6 [cite: 148]
  * [cite_start]Sensor 3 ➔ Arduino Digital Pin 5 [cite: 149]
  * [cite_start]Sensor 4 ➔ Arduino Digital Pin 4 [cite: 150]
  * [cite_start]Sensor 5 ➔ Arduino Digital Pin 3 [cite: 151]

### I2C LCD Screen
* [cite_start]**GND** ➔ Breadboard GND Rail [cite: 136]
* [cite_start]**VCC** ➔ Arduino 5V Pin (Requires 5V, not 3.3V) [cite: 137]
* [cite_start]**SDA** ➔ Arduino A4 [cite: 138]
* [cite_start]**SCL** ➔ Arduino A5 [cite: 139]

## 💻 Installation and Usage

1. [cite_start]Install the required libraries in your Arduino IDE: `LiquidCrystal_I2C` and `SoftwareWire`[cite: 154, 155].
2. Upload the `.ino` file to your Arduino.
3. [cite_start]Open Excel, enable the **Data Streamer** add-in, connect to the Arduino's COM port (Baud Rate: 9600), and click "Start Data"[cite: 45, 46].
