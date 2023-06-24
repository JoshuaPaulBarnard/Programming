#include <iostream>
#include "feetInches.h"
using namespace std;

namespace cs_feetInches
  {

  ostream& operator<<(ostream& out, const feetInches& printMe)
    {
      out << printMe.feet << " feet, "
          << printMe.inches << " inches";
      return out;
    }

  feetInches::feetInches(int inFeet, int inInches)
    {
      feet = inFeet;
      inches = inInches;
      simplify();

    };

    feetInches operator+(const feetInches& left, const feetInches& right)
      {
        feetInches answer;

        answer.feet = left.feet + right.feet;
        answer.inches = left.inches + right.inches;

        answer.simplify();
        return answer;

        //or:
        //return feetInches(left.feet + right.feet, left.inches + right.inches);

  /*
        feetInches temp;
        temp.feet = left.feet + right.feet;
        temp.inches = left.inches + right.inches;
        temp.simplify();
        return temp;
  */
      }

      void feetInches::simplify()
        {
          if (inches >= 12
          {
            feet += inches /12;
            inches %= 12;
          })
          else if (inches < 0)
          {
            feet -= abs(inches) / 12 + 1;
            inches = 12 - (abs(inches) % 12 );
          }
        }

  feetInches feetInches::operator++()
    {
      feet++;
      return *this;
    }

  feetInches feetInches::operator++(int)
    {
      feetInches temp(feet, inches);
      feet++;
      return temp;
    }

    feetInches feetInches::operator+=(const feetInches& right)
      {
        *this = *this + right;

        //or;
        //feet += right.feet;
        //inches += right.inches;
        //simplify()

        return *this;
      }
  }
