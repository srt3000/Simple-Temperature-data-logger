#include <SPI.h>
#include <SD.h>

File myFile;
float temp;
int tempPin = A0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  sd_init();

}

void loop() 
{
  sd_write();

}
void sd_init()
{
//    while (!Serial) 
//    {
//    ; // wait for serial port to connect. Needed for native USB port only
//    }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
}
void sd_write()
{
    myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  
  if (myFile) 
  {  
    tempread();
    myFile.println(temp);
    // close the file:
    myFile.close();
    Serial.println("done.");
  } 
}
void tempread()
{
     temp = analogRead(tempPin);  // read analog volt from sensor and save to variable temp
        temp = temp * 0.48828125;    // convert the analog volt to its temperature equivalent
        Serial.print("TEMPERATURE = ");
        Serial.print(temp); // display temperature value
        Serial.print("*C");
        Serial.println();
        delay(1000); // update sensor reading each one second    
        Serial.print("Writing to test.txt...");
}
