# 🌱 Soil Moisture Logger with GPS Timestamp and EEPROM Storage

A standalone Arduino-based system to monitor soil moisture and store sensor readings with GPS timestamps. Designed for areas without internet — no Wi-Fi or cloud needed.

## 📦 Features

- Reads data from **3 Soil Moisture Sensors**
- Fetches **Real-Time GPS Date and Time** using a **NEO-6M GPS module**
- Activates **irrigation logic** based on readings
- Stores:
  - **Date and Time before sensor read**
  - **Soil Sensor Value**
  - **Time after sensor read**
- Saves data into **Arduino's Internal EEPROM**
- Allows EEPROM data read via serial command
- Provides **local alerts** via buzzer and LEDs

## 🔧 Hardware Required

* Soil moisture sensors
* Arduino Uno / Nano
* Neo - 6M GPS Module
* Drip irrigation pump (12V)
* Relay module
* LEDs and buzzer for status indication
* Manual push-button control
* Feeder Pipe
* Battery

## 🛠️ Connections

| Component         | Arduino Pin |
|------------------|--------------|
| Soil Sensor 1     | A0          |
| Soil Sensor 2     | A1          |
| Soil Sensor 3     | A2          |
| GPS TX            | Pin 4 (RX)  |
| GPS RX            | Pin 5 (TX)  |
| Buzzer            | Pin 8       |
| LED (Operation)   | Pin 9       |
| LED (Idle)        | Pin 10      |
| Push Button       | Pin 7       |
 
## ⚙️ How It Works
   - System starts with a manual switch.
   - Three soil sensors are activated one at a time for 30 seconds each.
   - If any sensor reading drops below 150, the drip irrigation pump turns on.
   - If a reading drops below 100, the system skips the next sensors and waters directly.
   - A **buzzer** alerts the user to **turn off the system**.
   - Each reading is saved to **EEPROM**:
      - Date and Time (before reading)
      - Mapped Soil Value (0–255)
      - Time (after reading)
   - No Wi-Fi or cloud required — all data processed locally on Arduino's EEPROM.


## 📂 EEPROM Data Format (Per Entry - 10 Bytes)

| Byte Index | Data                 |
|------------|----------------------|
| 0          | Day                  |
| 1          | Month                |
| 2          | Year (last 2 digits) |
| 3          | Hour (before read)   |
| 4          | Minute (before read) |
| 5          | Second (before read) |
| 6          | Mapped Soil Value    |


## 🧪 Reading EEPROM Data

To read saved data:
1. Open Serial Monitor **at 9600 baud**
2. Type `readeeprom` and press enter
3. The EEPROM contents will be printed in raw format

## 🧑‍💻 Author

Designed and tested by Pournima Choulwar.
Feel free to fork or modify this project. Pull requests welcome!
