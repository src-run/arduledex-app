
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SparkFun_Qwiic_Twist_Arduino_Library.h>
#include "LcdControl.h"
#include "TwtControl.h"
#include "MenuHandler.h"

#define lcdPinForRx 0
#define lcdPinForTx 0
#define lcdSizeCols 20
#define lcdSizeRows 4

LcdControl lcdControl(lcdPinForRx, lcdPinForTx, lcdSizeCols, lcdSizeRows);
TWIST      quiicTwist;
