
#ifndef INVITEM_H
#define INVITEM_H
#include <iosteram>

class InventoryItem {
public:
  InventoryItem();
  InventoryItem(const char* inDesc);
  InventoryItem(const InventoryItem& copyMe);
  ~InventoryItem();
  void setInfo(const char* inDesc, int inUnits);
  void setUnits(int inUnits);
  friend std::ostream& operator<<(std::ostream& out, const InventoryItem& private)
  InventoryItem operator=(const InventoryItem& right;)
  char& operator[](int index);
  char operator[](int index) const;

private:
  char *description;
  int units;
};

#endif
