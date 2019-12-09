/******************************
* 
* CONTROL LED BLINK RATE WITH
* A POTENTIOMETER 
* 
* microcontrollers for artists
* fall 2019
* 
******************************/

//set pin numbers and initialize variables
int led = 12; 
int sensorValue = 0;
int potPin = A0;
bool ledState = false;
long int previousTime = 0;

// the setup routine runs once when you press reset:
void setup() { 
  //start up a serial connection              
  Serial.begin(9600);
  
  //set pin modes
  pinMode(led, OUTPUT); 
  pinMode(potPin, INPUT);
       
}

// the loop routine runs over and over again forever:
void loop() {
  
  //read voltage from our pot circuit
  //1 - 1023 directly controls blink time in milliseconds
  sensorValue = analogRead(potPin);

  //check time elapsed: is it greater than our sensor value aka blink rate?
  //if so toggle state of our LED circuit
  if(millis() - previousTime >= sensorValue){

    ledState = !ledState;
    previousTime = millis();
  }

  
  digitalWrite(led, ledState); 

  //small delay to play nice with Serial communication
  delay(50);
  
  Serial.println(sensorValue);
}
