#include <iostream>
#include <cstring>
#include "Stroka.h"

using namespace std;

Stroka::Stroka(const char *string) {  // Используем const char*
    strcpy(str, string);
}

Stroka::Stroka(const Stroka &s) {
    strcpy(str, s.str);
}

Stroka::~Stroka() {
    // Деструктор (не требуется явных действий, так как нет динамической памяти)
}

Stroka& Stroka::operator=(const Stroka &s) {
    if (this != &s) {
        strcpy(str, s.str);
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka &s) const {  // const метод
    Stroka temp;
    strcpy(temp.str, str);
    strcat(temp.str, s.str);
    return temp;
}

bool Stroka::operator==(const Stroka &s) const {  // const метод
    return strcmp(str, s.str) == 0;
}

int Stroka::dlina() const {  // const метод
    return strlen(str);
}

void Stroka::vvod() {
    cin >> str;
}

void Stroka::vyvod() const {  // const метод
    cout << str;
}
