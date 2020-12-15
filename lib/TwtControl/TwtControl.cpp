
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "TwtControl.h"

TwtControl::TwtControl():
    _firmware(0)
{
    if (this->_twt.begin(Wire) == false) {
        Serial.println("Sparkfun Quiic Twist device does not appear to be connected; please check wiring. Freezing...");
        while (1);
    }

    this->_firmware = this->_twt.getVersion();
    this->outFirmwareString();
}

int TwtControl::getFirmwareMajor()
{
    return this->_firmware & 0xFF;
}

int TwtControl::getFirmwareMinor()
{
    return this->_firmware >> 8;
}

void TwtControl::outFirmwareString()
{
    Serial.print("Quiic Twist firmware version: ");
    Serial.print(this->getFirmwareMajor());
    Serial.print(".");
    Serial.println(this->getFirmwareMinor());

    if (this->_firmware < 0x0201)
    {
        Serial.println("Quiic Twist firmware does not support limit function; upgrade firmware to version >= 1.2. Freezing...");
        while (1);
    }

    this->_twt.setLimit(24);
}
