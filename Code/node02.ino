#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

// Define pin for ultrasonic sensor
const int trigPin = 5; // Trig pin of ultrasonic sensor
const int echoPin = 4; // Echo pin of ultrasonic sensor

RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 02;   // Address of this node
const uint16_t node00 = 00;      // Address of the base node

void setup() {
  Serial.begin(9600);
  // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}

// Check if a distance under 5cm is detected
void loop() {
  if (readDistance() < 5) {
    send_message();
    delay(500);
  }
}

// Function to send a message to the base node
void send_message() {
  RF24NetworkHeader header2(node00); // Set the header to the address of the base node
  unsigned long message = 123; // Dummy messafe, the base node increments the score when any message is sent
  bool ok = network.write(header2, &message, sizeof(message)); // Send the message over the network
  if (ok) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Message send failed");
  }
}

// Function to read the distance in cm
float readDistance() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse from the echo pin
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Convert the duration to distance (cm)
  float distance = duration * 0.034 / 2;
  Serial.println(distance);
  return distance;
}
