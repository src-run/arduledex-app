
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "main.h"

void setupQuiicTwistWire() {
  if (quiicTwist.begin(Wire) == false) {
    Serial.println("Sparkfun Quiic Twist device does not appear to be connected; please check wiring. Freezing...");
    while (1);
  }
}

void printQuiicTwistInfo() {
  int version = quiicTwist.getVersion();

  Serial.print("Quiic Twist firmware version: ");
  Serial.print(version & 0xFF);
  Serial.print(".");
  Serial.println(version >> 8);

  if (version < 0x0201)
  {
    Serial.println("Quiic Twist firmware does not support limit function; upgrade firmware to version >= 1.2. Freezing...");
    while (1);
  }
}

void setupQuiicTwistConf() {
  quiicTwist.setLimit(24);
}

void setup() {
  // initialize serial @ 9600 bps
  Serial.begin(9600);

  // initialize wire1
  Wire.begin();

  // setup quiic twist device and display information
  setupQuiicTwistWire();
  printQuiicTwistInfo();
  setupQuiicTwistConf();

  // Set wire frequency
  Wire.setClock(400000);
}

void loop() {
  // put your main code here, to run repeatedly:
}