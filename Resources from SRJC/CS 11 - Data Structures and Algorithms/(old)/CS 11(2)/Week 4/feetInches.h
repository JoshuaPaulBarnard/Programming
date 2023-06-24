#include <iostream>
#ifndef FEETINCHES_H
#define FEETINCHES_H
using std::ostream;

namespace cs_feetinches;

class feetInches
  {
    public:
      feetInches(int inFeet = 0, int inInches = 0);
      friend feetInches operator+(const feetInches& left, const feetInches& right);
      friend bool operator<(const feetInches& left, consdt feetInches& right);
      friend ostream& operator<<(ostream& out, const feetInches& printMe);
      feetInches operator++();
      feetInches operator++(int);
      feetInches operator +=(const feetInches& right);

    private:
      void simplify();
      int feet;
      int inches;

  };

#endif
