
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef TwtControlHeader
#define TwtControlHeader

#include <Arduino.h>
#include <SparkFun_Qwiic_Twist_Arduino_Library.h>

class TwtControl
{
    public:
        TwtControl();
        int getFirmwareMajor();
        int getFirmwareMinor();
        void outFirmwareString();

    private:
        TWIST _twt;
        uint16_t _firmware;
};

#endif
