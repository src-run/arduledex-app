
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef LcdControlHeader
#define LcdControlHeader

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <string.h>

class LcdControl
{
    public:
        LcdControl(int pinForRx, int pinForTx, int sizeCols = 20, int sizeRows = 4);
        int getPinForRx();
        int getPinForTx();
        int getSizeCols();
        int getSizeRows();
        void clear();
        void printText(String text, bool newl = false);
        void printText(int text, bool newl = false);
        void printLine(String text);
        void printLine(int text);
        void setContrast(int level);
        void setBrightness(int level);
        void setPositionHome();
        void setColorR(int level);
        void setColorG(int level);
        void setColorB(int level);
        void setColor(int r, int g, int b);

    private:
        int _pinForRx;
        int _pinForTx;
        int _sizeCols;
        int _sizeRows;
        SoftwareSerial _lcd;
        void _writeDelay(long int ms = 10);
        void _setupScreen();
};

#endif
