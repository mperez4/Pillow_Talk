# Pillow Talk

About Pillow Talk. Edwina to update this part

## Hardware Requirements

This example uses the Arduino Nano ESP32 but should work on any ESP32 hardware. It also uses a MAX9814 microphone.

### wiring

Wiring to the ESP32:
| MAX9814 Pin | ESP32 Pin | Description |
|-------------|-----|--------------|
| AR | GND or Floating | AGC release control, can be left floating or connected to GND.
| OUT | GPIO11 (ADC4) | Analog audio output from the MAX9814.
|GAIN | GND or VDD | Adjust the gain: GND for 40dB, VDD for 60dB, floating for 50dB.
|VDD | 3.3V | Power the MAX9814 from the 3.3V pin of the ESP32.
| GND |GND | Ground to ESP32 GND.

## Setting up Firebase

coming soon
