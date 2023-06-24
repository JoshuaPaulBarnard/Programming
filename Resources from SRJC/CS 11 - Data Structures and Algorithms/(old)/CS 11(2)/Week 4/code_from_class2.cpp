
#ifndef Header_h
#define Header_h
#include <iostream>
using namespace std;

class feetInches
  {
    public:
      feetInches(int inFeet = 0, int inInches = 0);
      friend feetInches operator+(const feetInches& left, const feetInches& right);
      friend bool operator<(const feetInches& left, consdt feetInches& right);
      void print() const;
      feetInches operator++();
      feetInches operator++(int);
      friend ostream& operator<<(ostream& out, const feetInches& printMe);

    private:
      void simplify();
      int feet;
      int inches;

  };

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


int main()
{

  feetInches f1, f2(3), f3(4, 7);
  int x;

  f1 = f2 + f3;
  f2.print();
  cout << " plus ";
  f3.print();
  cout << " equals ";
  f1.print();
  cout << endl;

  cout << f2 << " plus " << f3 << " equals " << f1 << endl;

  (f1++).print();
  cout << endl;
  (++f1).print();
  cout << endl;
  f1.print();

  cout << f1++ << endl;
  cout << ++f1 << endl;
  cout << f1 << endl;

  int x;
  x = 42;
  f1 = x + f3;

  if (f2 < f1)
    {
      cout << "f1 is now " << f1 << endl;
    }
  else
    {

    }
