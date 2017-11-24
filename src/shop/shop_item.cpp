#include <string>

#include "shop/shop.hpp"
#include "shop/shop_item.hpp"

ShopItem::ShopItem() :
	itemName(""),
	itemOwned(false)
{	
}

ShopItem::~ShopItem()
{
}

void
ShopItem::setItemName(const std::string& name){
  	this->itemName = name;
}

void
ShopItem::setItemOwned(bool owned){
	this->itemOwned = owned;
}