
/*
 * This file is part of the `src-run/arduledex-app` project.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

#include "MenuHandler.h"

MenuHandler::MenuHandler(LcdControl &lcdControl, TwtControl &twtControl):
    _lcdControl(lcdControl),
    _twtControl(twtControl)
{
}
