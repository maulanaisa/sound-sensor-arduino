# sound-sensor-arduino
Short example using sound sensor.

This is an simple example how to use Ky-038 or something similar on arduino.

## Take_value.ino
This script shows sensor value reading. List of values then used to compare sensor reading to reference (calibrated sounds sensor).

Regression function then found using all pairs of values.

## Sound_sensor.ino

Simple example to display sound level value on LCD 16x2 display using arduino.

Raw values from sensor converted to display values using regression function created before.
