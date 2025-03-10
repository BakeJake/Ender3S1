/**
 * ToolBar for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * version: 1.3.1
 * Date: 2022/08/05
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "../../../inc/MarlinConfigPre.h"

#include "dwinui.h"
#include "menus.h"

#define TBHeight 28
#define TBOffset 20
#define TBYPos (STATUS_Y - (TBHeight + 5))
#define B_YPos (TBYPos + 5)
#define B_XPos 24
#define TBMaxCaptionWidth 18

typedef struct {
  uint8_t icon = 0;
  FSTR_P caption = nullptr;
  void (*onClick)() = nullptr;
} TBItem_t;
extern TBItem_t TBItem;
extern TBItem_t TBItemA[];

class ToolBarClass : public MenuClass {
public:
  void onScroll(bool dir) override;
  void draw() override;
  void (*onExit)() = nullptr;
  uint8_t OptCount();
};
extern ToolBarClass ToolBar;

void onDrawTBItem(MenuItemClass* menuitem, int8_t line);
void UpdateTBSetupItem(MenuItemClass* menuitem, uint8_t val);
void DrawTBSetupItem(bool focused, uint8_t line);
void Draw_ToolBar(bool force = false);
void TBGetItem(uint8_t item);
