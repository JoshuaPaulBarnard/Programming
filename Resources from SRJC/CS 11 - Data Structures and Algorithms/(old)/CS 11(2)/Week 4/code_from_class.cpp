#include <iostream>
using namespace std;

class feetInches
  {
    public:
      feetInches(int inFeet = 0, int inInches = 0);
      feetInches operator+(const feetInches &other) const;
      void print() const;
      feetInches operator++();
      feetInches operator++(int);
    private:
      void simplify();
      int feet;
      int inches;
  }
