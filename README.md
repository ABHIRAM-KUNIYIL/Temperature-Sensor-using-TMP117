# Temperature-Sensor-using-TMP117

# Multi-Sensor Lab Temperature Logger

A custom-built Arduino hardware solution for monitoring multi-point temperature data inside a laboratory environment. This system simultaneously tracks data from five high-precision TMP117 sensors and streams the live results directly to Microsoft Excel via the Data Streamer add-in.

##  Features

* **Multi-Sensor I2C Workaround:** Because TMP117 sensors often share the same hardware I2C address (`0x48`), this project utilizes the `SoftwareWire` library to create 5 distinct software I2C buses.
* **Shared Clock Architecture:** To save Arduino pins, all 5 sensors share a single Clock (SCL) line, utilizing separate Data (SDA) lines.
* **Live Excel Streaming:** Data is continuously piped over the Serial port as comma-separated values (CSV), pre-formatted for live plotting in Excel.
* **Smart LCD Display:** Features a paginated 16x2 I2C LCD that automatically cycles every 3 seconds to display the live readings of all 5 sensors without using `delay()`, ensuring the data stream remains uninterrupted.

##  Hardware Requirements

* 1x Arduino Uno (or compatible board)
* 5x TMP117 High-Precision Temperature Sensors
* 1x 1602A LCD Screen with I2C Backpack
* Breadboard and jumper wires

##  Wiring Guide

### Power Hub (Breadboard Rails)
* **3.3V Rail:** Connect Arduino 3.3V to the breadboard positive rail. Plug all 5 sensor VCC (Red) wires here.
* **GND Rail:** Connect Arduino GND to the breadboard negative rail. Plug all 5 sensor GND (Black) wires here.

### The 5 TMP117 Sensors
* **Shared Clock (SCL):** Connect all 5 sensor Yellow wires to the exact same horizontal row on the breadboard. Run a single jumper from this row to **Arduino Digital Pin 8**.
* **Data Lines (SDA - White Wires):** * Sensor 1 ➔ Arduino Digital Pin 7
  * Sensor 2 ➔ Arduino Digital Pin 6
  * Sensor 3 ➔ Arduino Digital Pin 5
  * Sensor 4 ➔ Arduino Digital Pin 4
  * Sensor 5 ➔ Arduino Digital Pin 3

### I2C LCD Screen
* **GND** ➔ Breadboard GND Rail
* **VCC** ➔ Arduino 5V Pin (Requires 5V, not 3.3V)
* **SDA** ➔ Arduino A4
* **SCL** ➔ Arduino A5

##  Installation and Usage

1. Install the required libraries in your Arduino IDE: `LiquidCrystal_I2C` and `SoftwareWire`.
2. Upload the `.ino` file to your Arduino.
3. Open Excel, enable the **Data Streamer** add-in, connect to the Arduino's COM port (Baud Rate: 9600), and click "Start Data".

##  How to Stream Live Data into Excel

This project is pre-configured to output data in a CSV format that natively perfectly pairs with Microsoft Excel's **Data Streamer** add-in.

### Step 1: Enable the Data Streamer Add-in
*(If you already have the "Data Streamer" tab in Excel, skip this step).*
1. Open Excel and go to **File** > **Options**.
2. Click on **Add-ins** on the left sidebar.
3. At the bottom, change the "Manage" dropdown to **COM Add-ins** and click **Go...**
4. Check the box next to **Microsoft Data Streamer for Excel** and click **OK**. You should now see a new "Data Streamer" tab at the top of Excel.

### Step 2: Connect and Stream
1. Ensure your Arduino is plugged into your computer via USB and the code is successfully uploaded.
2. Open a blank Excel workbook and go to the **Data Streamer** tab.
3. Click **Connect a Device** and select your Arduino's COM port (e.g., `COM3`, `COM4`).
4. Click **Start Data**.

Excel will automatically generate "Data In" and "Data Out" sheets. Your live temperature readings from all 5 sensors will immediately start populating the rows, ready to be highlighted and turned into a live-updating chart!
