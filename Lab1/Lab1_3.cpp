#include <iostream>

void obmen1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    std::cout << "posle obmena 1: a = " << a << ", b = " << b << std::endl;
}

void obmen2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    std::cout << "posle obmena 2: a = " << *a << ", b = " << *b << std::endl;
}

void obmen3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    std::cout << "posle obmena 3: a = " << a << ", b = " << b << std::endl;
}

int main() {
    int a = 2, b = 5;
    std::cout << "do obmena: a = " << a << ", b = " << b << std::endl;
    obmen1(a, b);
    obmen2(&a, &b);
    obmen3(a, b);
    return 0;
}