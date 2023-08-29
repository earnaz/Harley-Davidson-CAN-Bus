# Harley-Davidson-CAN-Bus


Project about reverse engineering the canbus system on harley davidson bikes from 2014
  the bike that was used in this project was a 2017 Forty Eight


----------------Hardware used----------------
 ```
  Arduino Uno board from aliexpress.
  MCP2515 Can Bus Driver Module from aliexpress.
  Breadboard Wires.
  Deutsch 6-pin connector from aliexpress, 
  Harley Davidson uses the deutsch connector for the diag port.
  ```


----------------Software used----------------
 ```
  Arduino IDE
  CanSniffer_Gui from Adam Varga "https://github.com/adamtheone/canDrive" 
  (Python and other dependencies are required to run the CanSniffer_Gui Check his documentation)
  Can_Sniffer_Arduino as source for the Arduino.
```


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

----------------Packet Ids/ PIDS----------------
```
0x550 - All buttons on left side handlebar + clutch
Horn     (02 00 02 00 00 00)
Lowbeam  (00 00 02 00 00 00) / this packet is looping while not using anything on left handle bar.
HighBeam (08 00 02 00 00 00)
Menu     (04 06 00 00 00 B4 00 FF)
Clutch   (01 00 02 00 00 00)

```
```
0x570 - All buttons on Right side handlebar + front brake
```
```
0x544 - RPM MAYBE
```
```
0x542 - Jiffy Stand
```
```
0x541 - RPM MAYBE
```
```
0x530 - Break Light, Turn Signals etc...
```
All Packets
```
547
50A
546
500
502
503
505
501
540
531
548
5C1
542 (kickstand)
544 (rpm maybe)
520
550 (Leftside Handlebar)
541 (rpm maybe)
532
530 (blinkers)
5C0
570 (Rightside handlebar)
521
543
```


