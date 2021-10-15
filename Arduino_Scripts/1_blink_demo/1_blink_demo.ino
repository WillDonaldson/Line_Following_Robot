#define LED_pin 13                  // assign pin LED is connected to

void setup(){                       // setup() is a block of code that runs once at the start of the program
  pinMode(LED_pin, OUTPUT);         // set pin to the output mode
}

void loop(){                        // loop() is a block of code that repeats itself until power is turned off
  digitalWrite(LED_pin, HIGH);      // turn LED on
  delay(100);                       // delay for 0.1 seconds while the LED is ON
  digitalWrite(LED_pin, LOW);       // turn LED off
  delay(100);                       // delay for 0.1 seconds while the LED is OFF
}
