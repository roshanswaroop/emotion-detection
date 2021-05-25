/* LED array test code
 *
 * Reads (x,y) co-ordinates from the Serial Monitor and toggles the state of
 * the LED at that co-ordinate. The co-ordinates are specified as "x y", e.g.
 * "1 2", followed by a newline. Invalid co-ordinates are rejected.
 *
 * You need to fill in all the places marked TODO.
 *
 * == Setting up the Serial Monitor ==
 * The Serial Monitor must be configured (bottom-right corner of the screen) as:
 *   - Newline (for the line ending)
 *   - Baud rate 115200
 *
 * ENGR 40M
 * July 2018
 */

// Arrays of pin numbers. Fill these in with the pins to which you connected
// your anode (+) wires and cathode (-) wires.
const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};

void setup() {
  // TODO: configure all anode (+) and cathode (-) wires to outputs
  // TODO: turn "off" all the LEDs
  // Hint: You did the same thing in everylight.ino.
  for (byte i = 0; i < 8; i++) {
    pinMode(ANODE_PINS[i], OUTPUT);
    digitalWrite(ANODE_PINS[i], HIGH);
    pinMode(CATHODE_PINS[i], OUTPUT);
    digitalWrite(CATHODE_PINS[i], HIGH);
  }
  // Initialize serial communication
  // (to be read by Serial Monitor on your computer)
  Serial.begin(115200);
  Serial.setTimeout(100);
}

/* Function: display
 * -----------------
 * Runs through one multiplexing cycle of the LEDs, controlling which LEDs are
 * on.
 *
 * During this function, LEDs that should be on will be turned on momentarily,
 * one row at a time. When this function returns, all the LEDs will be off
 * again, so it needs to be called continuously for LEDs to be on.
 */
void display(byte pattern[8][8]) {
  for (byte anode = 0; anode < 8; ++anode) {
    digitalWrite(ANODE_PINS[anode], LOW);
    for (byte cathode = 0; cathode < 8; ++cathode) {
      if (pattern[anode][cathode] == 1) {
        digitalWrite(CATHODE_PINS[cathode], LOW);
      }
      else {
        digitalWrite(CATHODE_PINS[cathode], HIGH);
      }
    }
    delayMicroseconds(100000);
    digitalWrite(ANODE_PINS[anode], HIGH);
  }
}

void loop() {
  // You shouldn't need to edit this function during lab 3a.

  // use 'static' so that it retains its value between successive calls of loop()
  static byte ledOn[8][8];

  byte x = 0;
  byte y = 0;
  static char message[60];
  String emotion = ""; 

  if (Serial.available()) {
    // Parse the values from the serial string
//    x = Serial.parseInt();
//    y = Serial.parseInt();
      emotion = Serial.readString();
      Serial.print(emotion);
      if (emotion == "angry") {
        ledOn[0][0] = 1;
        ledOn[0][1] = 1;
        ledOn[0][2] = 1;
        ledOn[0][3] = 1;
      }

    // Toggle the LED state
    //ledOn[x][y] = !ledOn[x][y];
  }

  // This function gets called every loop
  display(ledOn);
}
