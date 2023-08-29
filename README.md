# Harley-Davidson-CAN-Bus


Project about reverse engineering the canbus system on harley davidson bikes from 2014
  the bike that was used in this project was a 2017 Forty Eight


----------------Hardware tools used for this project was----------------
  Arduino Uno board from aliexpress.
  MCP2515 Can Bus Driver Module from aliexpress.
  Breadboard Wires.
  Deutsch 6-pin connector from aliexpress, 
  Harley Davidson uses the deutsch connector for the diag port.


----------------Software used in the project----------------
  Arduino IDE
  CanSniffer_Gui from Adam Varga "https://github.com/adamtheone/canDrive" 
  (Python and other dependencies are required to run the CanSniffer_Gui Check his documentation)
  Can_Sniffer_Arduino as source for the Arduino.



----------------Wiring----------------
```
  DeutschConnector Pin 1 -----> MCP2515/CanHigh
  DeutschConnector Pin 3 -----> MCP2515/CanLow
```

```
  MCP2515 INT -----> DigitalPin 2 Arudino
  MCP2515 SCK -----> DigitalPin 13 Arudino
  MCP2515 SI -----> DigitalPin 11 Arudino
  MCP2515 SO -----> DigitalPin 12 Arudino
  MCP2515 SCK -----> DigitalPin 10 Arudino
  MCP2515 GND -----> PowerPin GND Arudino
  MCP2515 VCC -----> PowerPin 5v Arudino
```
