
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#ifndef MenuHandlerHeader
#define MenuHandlerHeader

#include <Arduino.h>
#include "LcdControl.h"
#include "TwtControl.h"

class MenuHandler
{
    public:
        MenuHandler(LcdControl &lcdControl, TwtControl &twtControl);

    private:
        LcdControl _lcdControl;
        TwtControl _twtControl;
};

#endif
