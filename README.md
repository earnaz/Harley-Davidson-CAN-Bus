# Harley-Davidson-CAN-Bus

Reverse engineering the canbus system used in Harley Davidson bikes.
Bike used in this project XL1200X Sportster Forty Eight 2017

## Hardware used
 ```
  Arduino Uno board from aliexpress.
  MCP2515 Can Bus Driver Module from aliexpress.
  Breadboard Wires.
  Deutsch 6-pin connector from aliexpress, 
  Harley Davidson uses the deutsch connector for the diag port.
  ```


## Software used
 ```
  Arduino IDE
  CanSniffer_Gui from Adam Varga "https://github.com/adamtheone/canDrive" 
  (Python and other dependencies are required to run the CanSniffer_Gui Check his documentation)
  CanSniffer Arduino as source for the Arduino.
```


## Wiring
```
  DeutschConnector Pin 1 -----> MCP2515/CanHigh
  DeutschConnector Pin 3 -----> MCP2515/CanLow
```
```
  MCP2515 INT -----> DigitalPin 2 Arudino
  MCP2515 SCK -----> DigitalPin 13 Arudino
  MCP2515 SI  -----> DigitalPin 11 Arudino
  MCP2515 SO  -----> DigitalPin 12 Arudino
  MCP2515 SCK -----> DigitalPin 10 Arudino
  MCP2515 GND -----> PowerPin GND Arudino
  MCP2515 VCC -----> PowerPin 5v Arudino
```
## Setup
```
Install CAN library by Sandeep Mistry in arduino IDE
Delete files in the CAN/SRC folder
Replace the files with my CAN files
Upload CanSniffer.ino to your arduino
Run Serial Monitor to see if it worked
Make sure to use 9600 baudrate in the serial monitor
Check Device Manager in windows and make sure your bitrate for your comport is set to 9600
My files are modified for 8mhz chrystal make sure your MCP2515 has the same or change it.
```

## Decoded Packets

| ID | Name             | Length | Data    |
| -: | :--------------- | ------ | :------ |
| 550 | Lowbeam(LOOP)   | 6    | 00 00 02 00 00 00 |
| 550 | Highbeam 1-byte  | 6    | 08 00 02 00 00 00 |
| 550 | Clutch Pressed 1-byte  | 6    | 01 00 02 00 00 00 |
| 550 | Menu/Scroll     | 8    | 04 06 00 00 00 B4 00 FF |
| 544 | Throttle 1-byte  | 8    | C8 C2 00 00 00 00 00 00 |
| 542 | Jiffystand up   | 8    | 00 A0 00 00 00 00 00 00 |
| 542 | Jiffystand down | 8    | 30 A0 00 00 00 00 00 00 |
| 7E1 | ABS             | ?    | ** ** ** ** ** ** ** ** |
| 7E9 | ABS 2           | ?    | ** ** ** ** ** ** ** ** |
| 7E2 | BCM             | ?    | ** ** ** ** ** ** ** ** |
| 7EA | BCM 2           | ?    | ** ** ** ** ** ** ** ** |
| 7EA | ECU             | ?    | ** ** ** ** ** ** ** ** |
| 7EA | ECU 2           | ?    | ** ** ** ** ** ** ** ** |



![image](https://github.com/sofresh007/Harley-Davidson-CAN-Bus/assets/76256425/9332c610-d193-4497-af33-7e514bb32e6f)


