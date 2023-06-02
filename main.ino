#define triggerPin 5
#define echoPin 4
#define relayPin 6

float time = 0;
float distance = 0;

void setup() {
  Serial.begin(9600);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);

  delay(2000);
}

void loop() {
  measure_distance();

  if (distance < 5) {
    digitalWrite(relayPin, LOW); // Turn on the relay
  } else {
    digitalWrite(relayPin, HIGH); // Turn off the relay
  }

  delay(500);
}

void measure_distance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  time = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the time measured
  distance = time * 0.0343 / 2;
}
