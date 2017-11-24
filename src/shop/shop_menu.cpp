#include "shop/shop_menu.hpp"

#include "gui/menu_item.hpp"
#include "gui/menu_manager.hpp"
#include "supertux/player_status.hpp"
#include "supertux/savegame.hpp"
#include "worldmap/level.hpp"
#include "worldmap/worldmap.hpp"
#include "shop/shop.hpp"

const int beholderPrice = 1;
const int hadoukenPrice = 1;
const int shoryukenPrice = 1;
const int flipPrice = 1;

ShopMenu::ShopMenu()
{
  add_label(_("Shop"));
  add_hl();
  add_label(_("Cosmetics"));
  add_entry(MNID_BEHOLDER, _("Cosmetic: Beholder"));
  add_hl();
  add_label(_("Sounds"));
  add_entry(MNID_HADOUKEN, _("Fireball Sound: Hadouken"));
  add_entry(MNID_SHORYUKEN, _("Jump Sound: Shoryuken"));
  add_hl();
  add_label(_("Moves"));
  add_entry(MNID_FLIP, _("Tux Move: Flip"));
  add_hl();
  add_entry(MNID_RESET, _("Reset shop"));
  add_back(_("Back"));
}

void
ShopMenu::menu_action(MenuItem* item)
{
  auto worldmap = worldmap::WorldMap::current();
  if (!worldmap)
  {
    log_warning << "couldn't access WorldMap::current()" << std::endl;
  }
  else
  {
    auto status = worldmap->get_savegame().get_player_status();
    auto shop = Shop::current();

    switch(item->id)
    {

        case MNID_BEHOLDER:
          if (!shop->itemOwned("beholder")){
            status->add_coins(-beholderPrice); 
          }
          shop->buyItem("beholder");
          break;

        case MNID_HADOUKEN:
          if(!shop->itemOwned("hadouken")){
            status->add_coins(-hadoukenPrice);
          }
          shop->buyItem("hadouken");
          break;

        case MNID_SHORYUKEN:
          if(!shop->itemOwned("shoryuken")){
            status->add_coins(-shoryukenPrice);
          }
          shop->buyItem("shoryuken");
          break;

        case MNID_FLIP:
          if(!shop->itemOwned("flip")){
            status->add_coins(-flipPrice);
          }
          shop->buyItem("flip");
          break;
        case MNID_RESET:
          shop->reset();
    }
  }

  MenuManager::instance().clear_menu_stack();
}