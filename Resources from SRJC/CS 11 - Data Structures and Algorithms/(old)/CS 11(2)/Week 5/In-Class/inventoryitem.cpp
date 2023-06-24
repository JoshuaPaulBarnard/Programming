//#pragma warning(disable:4996)
#include "inventoryitem.h"
#include <iostream>
#include <cassert>
using namespace std;

char InventoryItem::operator[](int index) {
  assert (index >= 0 && index < strlen(description));
  return description[index];
}

char InventoryItem::operator[](int index) const {
  assert (index >= 0 && index < strlen(description));
  return description[index];
}

InventoryItem::~InventoryItem()
{
  delete[] description;
}

InventoryItem InventoryItem::operator=(const InventoryItem& right) {
  if(this != &right)
  {
    units = right.units;
    delete[] description;
    description = new char[strlen(right.description) + 1];
    strcpy(description, right.description);
  }
  return *this;
}

InventoryItem::InventoryItem(const InventoryItem& copyMe) {
  units = copyMe.units;
  description = new char[strlen(copyMe.description) + 1];
  strcpy(description, copyMe.description);
}

InventoryItem::InventoryItem(const char* inDescription) {
  units = 0;
  description = new char[strlen(inDescription) + 1];
  strcpy(description, inDescription);
}


InventoryItem::InventoryItem() {
  units = 0;
  description = new char[1];
  strcpy(description, "");
}


void InventoryItem::setInfo(const char* inDescription, int inUnits) {
  units = inUnits;

  // This will prevent a memory leak by deallocating the ...
  delete[] description;

  description = new char[strlen(inDescription) + 1];
  strcpy(description, inDescription);
}


void InventoryItem::setUnits(int inUnits) {
  units = inUnits;
}

ostream
