const int microphonePin = A8;

const int threshold = 500; // Adjust this value as needed

void setup(){
  Serial.begin(9600); // Open Serial communication at baud rate 9600 bps
  Serial.println("Setup");  
}

void loop() {
  // Read the sound level from the microphone
  int soundLevel = analogRead(microphonePin);
   Serial.print(soundLevel);
   Serial.print(" ");

  // Check if the sound level exceeds the threshold
  if (soundLevel > threshold) {
    Serial.println("talking");
  } else {
    Serial.println("not talking");
  }

  delay(100);
}