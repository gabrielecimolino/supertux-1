#ifndef HEADER_SUPERTUX_SHOP_SHOP_MENU_HPP
#define HEADER_SUPERTUX_SHOP_SHOP_MENU_HPP

#include "gui/menu.hpp"

class ShopMenu : public Menu
{
private:
  enum MenuIDs {
    MNID_BEHOLDER,
    MNID_HADOUKEN,
    MNID_SHORYUKEN,
    MNID_FLIP,
    MNID_RESET
  };

public:
  ShopMenu();

  void menu_action(MenuItem* item) override;

private:
  ShopMenu(const ShopMenu&) = delete;
  ShopMenu& operator=(const ShopMenu&) = delete;
};

#endif