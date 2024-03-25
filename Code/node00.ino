#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

#define BUTTON_PIN 5 // Button pin

RF24 radio(7, 8);                 // nRF24L01 (CE,CSN)
RF24Network network(radio);       // Include the radio in the network
const uint16_t this_node = 00;    // Address of main node
const uint16_t node01 = 01;       // Address of a transmitter
const uint16_t node02 = 02;       // Address of another transmitter

// Initialize the I2C LCD with its address
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27, 16 characters per line, 2 lines

int score = 0;                    // Variable to store the score
bool buttonState = false;         // Variable to store button state
bool lastButtonState = false;     // Variable to store last button state
unsigned long lastDebounceTime = 0; // Variable to store last debounce time
unsigned long debounceDelay = 50; // Debounce delay in milliseconds

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Initialize button pin
  // Initialize the LCD
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  // (channel, node address)
  radio.setDataRate(RF24_2MBPS);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score: ");
  lcd.print(score); // Print score on the LCD
}

void loop() {
  // Read the button state with debounce
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        // Button is pressed
        score = 0; // Increment score
        // Print score to the LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Score: ");
        lcd.print(score); // Print score on the LCD
      }
    }
  }
  lastButtonState = reading;
  //===== Receiving =====//
  // Update the network queue
  network.update();
  // Check for new messages on the queue
  while (network.available()) {
    RF24NetworkHeader header;
    unsigned long incomingData;
    // Read in the message
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data 
    // Increment score every time a new message is received
    score++;
    // Print the score
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Score: ");
    lcd.print(score);
    delay(1000); // Delay for visibility
  }
}
