#include <CAN.h>

// RealDash CAN frame headers
const byte RD_FRAME_HEADER[] = {0x44, 0x33, 0x22, 0x11};

//------------------------------------------------------------------------------
// Settings
#define CAN_SPEED (500E3) // Adjust this to your CAN network speed
#define SERIAL_BAUD_RATE 250000 // Adjust this to your serial communication speed

//------------------------------------------------------------------------------
// Inits, globals
typedef struct {
  long id;
  byte rtr;
  byte ide;
  byte dlc;
  byte dataArray[8]; // Adjust the size to match your CAN messages
} packet_t;

//------------------------------------------------------------------------------
// Printing a packet to serial
void printHex(long num) {
  if (num < 0x10) {
    Serial.print("0");
  }
  Serial.print(num, HEX);
}

void printPacket(packet_t *packet) {
  // packet format (hex string): [ID],[RTR],[IDE],[DATABYTES 0..8B]\n
  // example: 014A,00,00,1A002B003C004D\n
  printHex(packet->id);
  Serial.print(",");
  Serial.print(packet->rtr, HEX);
  Serial.print(",");
  Serial.print(packet->ide, HEX);
  Serial.print(",");
  Serial.print(packet->dlc, DEC);
  Serial.print(",");

  for (int i = 0; i < packet->dlc; i++) {
    Serial.print(packet->dataArray[i], HEX);
    Serial.print(",");
  }

  Serial.println();
}

//------------------------------------------------------------------------------
// Forward a CAN packet as RealDash CAN '44' frame
void forwardAsRD44Frame(packet_t *packet) {
  // RealDash '44' frame format:
  // 4 bytes - 0x44,0x33,0x22,0x11
  // 4 bytes - CAN frame id number (32bit little endian value)
  // 8 bytes - CAN frame payload (data)

  Serial.write(RD_FRAME_HEADER, 4);
  Serial.write((byte *)&packet->id, 4);
  Serial.write(packet->dataArray, 8);
}

//------------------------------------------------------------------------------
// CAN RX, TX
void onCANReceive(int packetSize) {
  // received a CAN packet
  packet_t rxPacket;
  rxPacket.id = CAN.packetId();
  rxPacket.rtr = CAN.packetRtr() ? 1 : 0;
  rxPacket.ide = CAN.packetExtended() ? 1 : 0;
  rxPacket.dlc = CAN.packetDlc();
  byte i = 0;
  while (CAN.available()) {
    rxPacket.dataArray[i++] = CAN.read();
    if (i >= (sizeof(rxPacket.dataArray) / (sizeof(rxPacket.dataArray[0])))) {
      break;
    }
  }

  // Forward the received packet as RealDash '44' frame
  forwardAsRD44Frame(&rxPacket);
}

//------------------------------------------------------------------------------
// Setup
void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (!CAN.begin(CAN_SPEED)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
  // register the receive callback
  CAN.onReceive(onCANReceive);
  Serial.println("CAN RX TX Started");
}

//------------------------------------------------------------------------------
// Main
void loop() {
  // Handle any other tasks if needed
}
