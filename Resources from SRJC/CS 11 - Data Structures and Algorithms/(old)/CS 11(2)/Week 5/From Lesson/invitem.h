// This is the file "invitem.h"

#ifndef INVITEM_H
#define INVITEM_H
#include <iostream>

class InventoryItem {
    public:
        InventoryItem();
        InventoryItem(const char *inDesc);
        InventoryItem(const InventoryItem& right);
        ~InventoryItem();
        InventoryItem operator=(const InventoryItem& right);
        void setInfo(const char *inDesc, int inUnits);
        void setUnits(int inUnits);
        friend std::ostream& operator<<(std::ostream& out, const InventoryItem& source);
        friend std::istream& operator>>(std::istream& in, InventoryItem& target);
        char operator[](int index) const;
        char& operator[](int index);
    private:
        char *description;
        int units;
};

#endif
