This project automates the watering of 7–8 terrace plants during peak summer heat using:

* Soil moisture sensors
* Arduino Uno
* Drip irrigation pump (12V)
* Relay module
* LEDs and buzzer for status indication
* Manual push-button control
* Feeder Pipe
* Battery

⚙️ How It Works
   - System starts with a manual switch.
   - Three soil sensors are activated one at a time for 30 seconds each.
   - If any sensor reading drops below 150, the drip irrigation pump turns on.
   - If a reading drops below 100, the system skips the next sensors and waters directly.
   - A buzzer alerts to switch off the system.
   - No Wi-Fi or cloud — all data processed locally on Arduino's EEPROM.
