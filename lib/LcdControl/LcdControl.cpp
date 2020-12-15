
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "LcdControl.h"

LcdControl::LcdControl(int pinForRx, int pinForTx, int sizeCols, int sizeRows):
    _pinForRx(pinForRx),
    _pinForTx(pinForTx),
    _sizeCols(sizeCols),
    _sizeRows(sizeRows),
    _lcd(SoftwareSerial((uint8_t) this->getPinForRx(), (uint8_t) this->getPinForTx()))
{
    this->_setupScreen();
}

int LcdControl::getPinForRx()
{
    return this->_pinForRx;
}

int LcdControl::getPinForTx()
{
    return this->_pinForTx;
}

int LcdControl::getSizeCols()
{
    return this->_sizeCols;
}

int LcdControl::getSizeRows()
{
    return this->_sizeRows;
}

void LcdControl::_writeDelay(long int ms)
{
    delay(ms);
}

void LcdControl::_setupScreen()
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0xD1);
    this->_lcd.write(this->getSizeCols());
    this->_lcd.write(this->getSizeRows());
    this->_writeDelay();
}

void LcdControl::clear()
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0x58);
    this->_writeDelay();
}

void LcdControl::printText(String text, bool newl)
{
    if (newl) {
        this->_lcd.println(text);
    } else {
        this->_lcd.print(text);
    }
}

void LcdControl::printText(int text, bool newl)
{
    this->printText((String) text, newl);
}

void LcdControl::printLine(String text)
{
    this->printText(text, true);
}

void LcdControl::printLine(int text)
{
    this->printLine((String) text);
}

void LcdControl::setContrast(int level)
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0x50);
    this->_lcd.write(level);
    this->_writeDelay();
}

void LcdControl::setBrightness(int level)
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0x99);
    this->_lcd.write(level);
    this->_writeDelay();
}

void LcdControl::setPositionHome()
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0x48);
    this->_writeDelay();
}

void LcdControl::setColorR(int level)
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0xD0);
    this->_lcd.write(level); 
    this->_lcd.write((uint8_t)0);
    this->_lcd.write(255 - level);
    this->_writeDelay();
}

void LcdControl::setColorG(int level)
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0xD0);
    this->_lcd.write(255 - level);
    this->_lcd.write(level);
    this->_lcd.write((uint8_t)0);
    this->_writeDelay();
}

void LcdControl::setColorB(int level)
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0xD0);
    this->_lcd.write((uint8_t)0);
    this->_lcd.write(255 - level);
    this->_lcd.write(level);
    this->_writeDelay();
}

void LcdControl::setColor(int r, int g, int b)
{
    this->_lcd.write(0xFE);
    this->_lcd.write(0xD0);
    this->_lcd.write(r);
    this->_lcd.write(b);
    this->_lcd.write(g);
    this->_lcd.print("idk");
    this->_lcd.println("idk");
    this->_writeDelay();
}
