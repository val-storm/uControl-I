double prevBeat = 0;
double seqSpeed;
double toneLength = 0.9;
double tones[8] = { 554.365, 622.254, 739.989, 830.609, 932.328, 1108.73, 1244.51, 1396.91 };
int stepCount = 0;
double maxFreq;
int controlVal;

void setup() {

  Serial.begin(9600);
  seqSpeed = 100;

}

void loop() {

  //seqSpeed = map(analogRead(17), 0, 1023, 75, 2000);
  //controlVal = map(analogRead(18), 0, 1000, 0, 127);

  /*
  for(int i = 0; i < 8; i++){
    tones[i] = 500 + (i * analogRead(18));
  }
  */
  //usbMIDI.sendControlChange(1, controlVal, 1);
  
  if(millis() - prevBeat >= seqSpeed){
    noTone(9);
    tone(9, tones[stepCount], seqSpeed*toneLength);
    prevBeat = millis();
    //usbMIDI.sendNoteOn(stepCount, 127, 1);
    stepCount++;
    if(stepCount > 7)
        stepCount = 0;
   // Serial.println(analogRead(18));
  }
  delay(10);
  
}
