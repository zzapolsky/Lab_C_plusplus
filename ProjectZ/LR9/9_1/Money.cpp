#include "Money.h"
#include <iostream>
using namespace std;

Money::Money() {
    this->dollars = 0;
    this->cents = 0;
    cout << "Constructor " << this << endl;
}

Money::Money(long d, int c)
{
    this->dollars = d;
    this->cents = c;
    cout << "Constructor " << this << " ; dollars - " << d << " ; cents - " << c << endl;
}

Money::~Money() {
    cout << "Destructor " << this << endl;
}

int Money::operator>(const Money& amt)
{
    return dollars > amt.dollars || ((dollars == amt.dollars) && (cents > amt.cents));
}

ostream& operator << (ostream& os, Money& amt)
{
    os << '$' << amt.dollars << "." << amt.cents;
    return os;
}