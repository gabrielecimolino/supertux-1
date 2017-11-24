#include "shop/shop.hpp"
#include "shop/shop_item.hpp"
#include "util/reader_mapping.hpp"
#include "util/writer.hpp"

#include <memory>
#include <iostream>
#include <vector>

Shop::Shop() :
  shopItems(std::vector<ShopItem>()),
  currentCosmetic(""),
  currentFireballSound(""),
  currentJumpSound(""),
  currentMove("")
{
  reset();
}

Shop::~Shop()
{
}

void
Shop::reset(){
  std::vector<std::string> items = {"beholder", "hadouken", "shoryuken", "flip"};
  shopItems = std::vector<ShopItem>();
  for (const auto &item : items){
    ShopItem shopItem;
    shopItem.setItemName(item);
    shopItems.push_back(shopItem);
  }

  currentCosmetic = "";

  currentFireballSound = "";
  currentJumpSound = "";

  currentMove = "";
}

void
Shop::write(Writer& writer){
  for (ShopItem& shopitem : shopItems){
    writer.write(shopitem.getItemName(), shopitem.getItemOwned());
  }

  writer.write("cosmetic", currentCosmetic);
  writer.write("fireball", currentFireballSound);
  writer.write("jump", currentJumpSound);
  writer.write("move", currentMove);
}

void 
Shop::read(const ReaderMapping& lisp){
  reset();

  for (ShopItem& shopitem : shopItems){
    const char* itemName = shopitem.getItemName().c_str();
    bool owned;
    lisp.get(itemName, owned);
    if(owned){
      buyItem(shopitem.getItemName());
    }

    lisp.get("cosmetic", currentCosmetic);
    lisp.get("fireball", currentFireballSound);
    lisp.get("jump", currentJumpSound);
    lisp.get("move", currentMove);
  }
}

void
Shop::buyItem(const std::string& item){
  for (ShopItem& shopitem : shopItems){
    if (shopitem.getItemName() == item){
      shopitem.itemOwned = true;
      
      if(item == "beholder")
        currentCosmetic = currentCosmetic == "beholder" ? "" : "beholder";
      if(item == "hadouken")
        currentFireballSound = currentFireballSound == "sounds/hadouken.wav" ? "" : "sounds/hadouken.wav";
      if(item == "shoryuken")
        currentJumpSound = currentJumpSound == "sounds/shoryuken.wav" ? "" : "sounds/shoryuken.wav";
      if(item == "flip")
        currentMove = currentMove == "flip" ? "" : "flip";
    }
  }
}

bool
Shop::itemOwned(const std::string& item){
  for (ShopItem& shopitem : shopItems){
    if(shopitem.getItemName() == item){
      return shopitem.getItemOwned();
    }
  }
  return false;
}

std::string
Shop::getCurrentCosmetic(){
  return currentCosmetic;
}

std::string
Shop::getCurrentFireballSound(){
  return currentFireballSound;
}

std::string
Shop::getCurrentJumpSound(){
  return currentJumpSound;
}

std::string
Shop::getCurrentMove(){
  return currentMove;
}