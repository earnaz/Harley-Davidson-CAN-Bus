# Harley-Davidson-CAN-Bus

#Reverse engineering the canbus system used in Harley Davidson bikes.
Bike used in this project is 2017 FORTY EIGHT

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
----------------Installation----------------
```
Install CAN library by Sandeep Mistry in arduino IDE
Delete files in the CAN/SRC folder
Replace the files with my CAN files
Upload CanSniffer.ino to your arduino
Run Serial Monitor to see if it worked
Make sure to use 9600 baudrate in the serial monitor
Check Device Manager in windows and make sure your bitrate for your comport is set to 9600
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
Jiffystand Down (30 A0 00 00 00 00 00 00)
Jiffystand UP (00 A0 00 00 00 00 00 00) 
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
530 (TurnSignals + Brakelight + FootBreak)
5C0
570 (Rightside handlebar)
521
543
```

![image](https://github.com/sofresh007/Harley-Davidson-CAN-Bus/assets/76256425/9332c610-d193-4497-af33-7e514bb32e6f)

