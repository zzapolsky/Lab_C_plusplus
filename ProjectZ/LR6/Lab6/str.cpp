#include <iostream> 
#include <cstring> 
#include "str.h" 

using namespace std; 

Stroka::Stroka(const char* string) { // Конструктор класса Stroka, принимающий const char*
    strcpy(str, string); // Копируем строку string в поле str класса Stroka
}

Stroka::Stroka(const Stroka& s) { // Конструктор копирования класса Stroka
    strcpy(str, s.str); // Копируем строку s.str в поле str класса Stroka
}

Stroka::~Stroka() { // Деструктор класса Stroka
    // Деструктор (не требуется явных действий, так как нет динамической памяти)
}

Stroka& Stroka::operator=(const Stroka& s) { // Перегрузка оператора присваивания для класса Stroka
    if (this != &s) { // Проверяем, не является ли объект s текущим объектом
        strcpy(str, s.str); // Копируем строку s.str в поле str класса Stroka
    }
    return *this; 
}

Stroka Stroka::operator+(const Stroka& s) const { // Перегрузка оператора сложения для класса Stroka (const метод)
    Stroka temp; 
    strcpy(temp.str, str); // Копируем строку str в поле str временного объекта
    strcat(temp.str, s.str); // Конкатенируем строку s.str к строке str временного объекта
    return temp; 
}

bool Stroka::operator==(const Stroka& s) const { // Перегрузка оператора сравнения для класса Stroka (const метод)
    return strcmp(str, s.str) == 0; // Сравниваем строки str и s.str с помощью функции strcmp и возвращаем результат
}

int Stroka::dlina() const { // Метод dlina класса Stroka (const метод)
    return strlen(str); // Возвращаем длину строки str с помощью функции strlen
}

void Stroka::vvod() { // Метод vvod класса Stroka
    cin >> str; // Вводим строку с помощью стандартного потока ввода cin
}

void Stroka::vyvod() const { // Метод vyvod класса Stroka (const метод)
    cout << str; // Выводим строку с помощью стандартного потока вывода cout
}
