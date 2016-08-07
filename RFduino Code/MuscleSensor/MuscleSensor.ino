// reads analog input from the five inputs from your arduino board 
// and sends it out via serial

// variables for input pins and
int analogInput = A5;
int ledPin = 5;
  
// variable to store the value 
int value = 0;  
 
void setup()
{
  // declaration of pin modes
  //for(int i=0;i<6;i++)
    pinMode(analogInput, INPUT); 
    pinMode(ledPin, OUTPUT);   

  
  // begin sending over serial port
  Serial.begin(9600);
}

void loop()
{
  int timeCurrent = millis();
  // read the value on analog input
  //for(int i=0;i<6;i++)
    
   value = analogRead(analogInput);
 

  // print out value over the serial port
  //for(int i=0;i<6;i++)
  
   Serial.println(); //prefix
   Serial.print(value);
   Serial.print(",");
   Serial.println(timeCurrent);
   Serial.println("\n"); //end signal
 
  // wait for a bit to not overload the port
  delay(100);
  
}
  

