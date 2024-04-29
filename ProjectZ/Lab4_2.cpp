#include <iostream>
#include "Lab4_2.h"
#include <cstring>
#include <locale.h>
#include <memory>
using namespace std;

// Функция 1 для определения длины строки
int Lab4_2::dlina1(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Функция 2 для определения длины строки
int Lab4_2::dlina2(char* str) {
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

// Функция 3 для определения длины строки
int Lab4_2::dlina3(char* str) {
    return strlen(str);
}

// Функция для выделения памяти и копирования строки
char* Lab4_2::kopir(char* str2) {
    int len = Lab4_2::dlina1(str2);
    char* str1 = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        str1[i] = str2[i];
    }
    return str1;
}

// Функция для сравнения строк
int Lab4_2::sravn(char* str1, char* str2) {
    return strcmp(str1, str2);
}

// Функция для конкатенации строк
char* Lab4_2::konkat(char* str1, char* str2) {
    int len1 = Lab4_2::dlina1(str1);
    int len2 = Lab4_2::dlina1(str2);
    char* result = new char[len1 + len2 + 1];
    memcpy(result, str1, len1);
    memcpy(result + len1, str2, len2 + 1);
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int N = 5;
    const int strSize = 100;
    char strArr[N][strSize];

    // Инициализация массива строк
    memcpy(strArr[0], "qwerty", 7);
    memcpy(strArr[1], "123456789", 10);
    memcpy(strArr[2], "hello", 6);
    memcpy(strArr[3], "world", 6);
    memcpy(strArr[4], "example", 8);

    // Использование функций длины строки
    for (int i = 0; i < N; ++i)
    {
        std::cout << "Длина strArr[" << i << "] = " << Lab4_2::dlina1(strArr[i]) << std::endl;
    }

    // Сравнение строк
    std::cout << "Результат сравнения: strArr[0] = " << strArr[0];
    std::cout << ", strArr[1] = " << strArr[1] << ", " << Lab4_2::sravn(strArr[0], strArr[1]) << std::endl;

    // Конкатенация строк
    char* result = Lab4_2::konkat(strArr[2], strArr[3]);
    std::cout << "Результат сцепления: strArr[2] = " << strArr[2];
    std::cout << ", strArr[3] = " << strArr[3] << ", result = " << result << std::endl;

    // Копирование строк
    char* strCopy = Lab4_2::kopir(strArr[4]);
    std::cout << "Результат копирования: strCopy = " << strCopy;
    std::cout << ", strArr[4] = " << strArr[4] << std::endl;

    delete[] result;
    delete[] strCopy;

    return 0;
}
