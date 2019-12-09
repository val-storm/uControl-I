/***********************************************************************
* 
* Basic touchRead example turns on built in LED on TEENSY LC
* 
* connect wires (electrodes) to pins 22 and 23
* delete specified lines to print touch info in serial monitor
* 
* 
***********************************************************************/

int a = 0;
int b = 0;
int lastPrint = 0;
const int touchThreshold = 1900;

void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
}

void loop() {

  //read capacitance value on two touch capable pins
  a = touchRead(23);
  b = touchRead(22);
  
  //if either of them are above threshold turn on LED
  if(a > touchThreshold || b > touchThreshold)
  {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  /* DELETE THIS LINE AND AT END TO PRINT CALIBRATION INFO
  if(millis() - lastPrint >= 500)
  {
    Serial.println("Touch Read Value Pin 23:");
    Serial.println(a);
    Serial.println("Touch Read Value Pin 22:");
    Serial.println(b);
    lastPrint = millis();
  }
  DELETE THIS LINE AND ONE ABOVE TO PRINT CALIBRATION INFO*/ 
  delay(5);
}
