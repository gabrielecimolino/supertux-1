#ifndef HEADER_SUPERTUX_SHOP_SHOP_HPP
#define HEADER_SUPERTUX_SHOP_SHOP_HPP

#include <string>
#include <vector>
#include <memory>

#include "shop/shop_item.hpp"
#include "math/vector.hpp"
#include "util/currenton.hpp"
#include "util/reader_mapping.hpp"
#include "util/writer.hpp"

class Shop : public Currenton<Shop>
{
public:
  Shop();
  virtual ~Shop();

  void reset();
  void write(Writer& writer);
  void read(const ReaderMapping& lisp);
  void buyItem(const std::string& item);
  bool itemOwned(const std::string& item);
  std::string getCurrentCosmetic();
  std::string getCurrentFireballSound();
  std::string getCurrentJumpSound();
  std::string getCurrentMove();

private:

  std::vector<ShopItem> shopItems;
  std::string currentCosmetic;
  std::string currentFireballSound;
  std::string currentJumpSound;
  std::string currentMove;

private:
  Shop(const Shop&);
  Shop& operator=(const Shop&);
};

#endif