#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money
{
    long dollars;
    int cents;
public:
    Money();
    Money(long, int);
    ~Money();
    int operator>(const Money&);
    friend std::ostream& operator <<(std::ostream&, Money&);
};

#endif //MONEY_H