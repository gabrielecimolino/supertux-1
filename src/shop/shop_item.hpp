#ifndef HEADER_SUPERTUX_SHOP_SHOP_ITEM_HPP
#define HEADER_SUPERTUX_SHOP_SHOP_ITEM_HPP

#include <string>

class ShopItem
{
public:
  ShopItem();
  virtual ~ShopItem();

  std::string getItemName() const {
    return this->itemName;
  }
  bool getItemOwned() const {
  	return this->itemOwned;
  }

  void setItemName(const std::string& name);

  void setItemOwned(bool owned);

  std::string itemName;
  bool itemOwned;
};

#endif