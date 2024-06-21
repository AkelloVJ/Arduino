// Define pins for sensors and relay
const int waterLevelPin = A0;
const int waterQualityPin = A1;
const int cathodeAnodePin = 2; // Assuming connected to digital pin 2

// Define relay control pins
const int relay1Pin = 3;
const int relay2Pin = 4;
const int relay3Pin = 5;
const int relay4Pin = 6;

// Define threshold values for sensors
const int waterLevelThreshold = 500; // Adjust as needed
const int waterQualityThreshold = 600; // Adjust as needed

void setup() {
  // Initialize relay control pins as outputs
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int waterLevel = analogRead(waterLevelPin);
  int waterQuality = analogRead(waterQualityPin);
  int electrolysisStatus = digitalRead(cathodeAnodePin);

  // Check conditions and control relay accordingly
  if (waterLevel < waterLevelThreshold) {
    digitalWrite(relay1Pin, HIGH); // Activate pump
  } else {
    digitalWrite(relay1Pin, LOW); // Deactivate pump
  }

  if (waterQuality < waterQualityThreshold) {
    digitalWrite(relay2Pin, HIGH); // Activate water quality control mechanism
  } else {
    digitalWrite(relay2Pin, LOW); // Deactivate water quality control mechanism
  }

  if (electrolysisStatus == HIGH) {
    digitalWrite(relay3Pin, HIGH); // Activate electrolysis process
  } else {
    digitalWrite(relay3Pin, LOW); // Deactivate electrolysis process
  }

  // Activate/deactivate other relay as needed based on other conditions

  // Debugging output
  Serial.print("Water Level: ");
  Serial.println(waterLevel);
  Serial.print("Water Quality: ");
  Serial.println(waterQuality);
  Serial.print("Electrolysis Status: ");
  Serial.println(electrolysisStatus);

  // Delay for stability
  delay(1000);
}
