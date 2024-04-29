#include <iostream>

int power(int, int);

int main() {
    int base, i, k;

    std::cout << "Vvedite osnovanie: ";
    std::cin >> base;

    for (i = 0; i < 10; i++) {
        k = power(base, i);
        std::cout << "i= " << i << ", k =" << k << std::endl;
    }

    return 0;
}

int power(int x, int n) {
    int i, p = 1;

    for (i = 1; i <= n; i++) {
        p *= x;
    }

    return p;
}