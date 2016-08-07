/*
TRANCIEVER
*/

#include <RFduinoGZLL.h>
#include <Time.h>
device_t role = DEVICE0;
int musclePin = 5;
// Define my custom packet of no more than 20 bytes.

      // 4 bytes?
int musclesensor;
  

void setup()
{
  // Set transmit power (-20, -16, -12, -8, -4, 0, +4)
  RFduinoGZLL.txPowerLevel = 0;
  // Set addresses
  RFduinoGZLL.hostBaseAddress = 0x0D0A0704;    // default host base address is 0x0D0A0704;
  RFduinoGZLL.deviceBaseAddress = 0x0E0B0805;  // default device base address is 0x0E0B0805; 
  // start GZLL stack
  RFduinoGZLL.begin(role);

 
}

void loop()
{
  musclesensor = analogRead(musclePin);
  //packet.sensor2 = 2222;
  

  RFduinoGZLL.sendToHost((char *)&musclesensor, sizeof(musclesensor)); 
  delay(100);
}
