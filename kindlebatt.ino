/* 
-AMAZON KINDLE I2C BATTERY READER- 
*Version 1.0 (9.6.2015)
*Written By Uğur KIRÇIL.
*Currently only supports read cycle count and reading Soc (battery percentage)
*because i dont know how to convert capacity to mah or convert temp to C'
*If you want to try other registers , check this pdf
*http://www.ti.com/lit/ds/symlink/bq27210.pdf
*go to page 12. you can see list of i2c registers
*Address of bq27210 is 0x55. if you have different battery ,
*add " I2c.scan(); " to void setup() and change the address on every command
*/
#include <I2C.h> //i2cmaster lib is easy to use and supports smbus + i2c batts
int CYCT=0;
int CYCL=0;
int SOC=0;
void setup() {
I2c.begin(); //We should start i2c
Serial.begin(9600); //9600baud will be enough
Serial.println("AMAZON KINDLE I2C BATTERY READER");
Serial.println("Version 1.0");
Serial.println("Written By Ugur Kircil");
Serial.println("");
Serial.println("");
digitalWrite(13,HIGH); //LED will be high while scanning battery
I2c.scan(); // add // if you want to test i2c bus and scan batt
digitalWrite(13,LOW); //LOW the LED
}

void loop() {
I2c.read(0x0d, 0x2a ,8); //Read 0x2a address in 0x55 device 
int CYCT = I2c.receive(); 
Serial.print("Total Cycle Count : ");
Serial.print(CYCT); //print 0x2a address to serial terminal
Serial.print(" cycles");
Serial.println("");
I2c.read(0x0d, 0x28 ,8);
int CYCL = I2c.receive();
Serial.print("Cycle Count Since Learning Cycle : ");
Serial.print(CYCL);
Serial.print(" cycles");
Serial.println("");  
I2c.read(0x0d, 0x0B ,8);
int SOC = I2c.receive();
Serial.print("State Of Charge : %");
Serial.print(SOC);
Serial.println("");  

 delay(5000); //it will refresh in every 5sec
}
