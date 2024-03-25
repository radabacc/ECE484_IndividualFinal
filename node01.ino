#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

#define buttonPin 5 // Button pin

RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of this node
const uint16_t node00 = 00;      // Address of base node

bool buttonState = false; // Variable to store button state
bool lastButtonState = false; // Variable to store last button state
unsigned long lastDebounceTime = 0; // Variable to store last debounce time
unsigned long debounceDelay = 50; // Debounce delay in milliseconds

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); // Initialize button pin
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
  // Read the button state with debounce
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        // Button is pressed
        send_message();
      }
    }
  }
  lastButtonState = reading;
}

void send_message() {
  RF24NetworkHeader header(node00); // Set the header to the address of the base node
  unsigned long message = 123; // Dummy message, the base node increments the score when any message sends
  bool ok = network.write(header, &message, sizeof(message)); // Send the message over the network
  if (ok) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Message send failed");
  }
}
