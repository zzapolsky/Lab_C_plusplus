#include <iostream> // Библиотека для работы с вводом-выводом
#include <locale.h> // Библиотека для работы с локалями
#include "Money.h" // Подключение заголовочного файла класса Money

using namespace std; // Использование пространства имен std

// Шаблонная функция сортировки массива
template <class T>
void Sort(T array[], size_t size) {
    int i, j;
    T tmp;
    for (i = 0; i < size; i++) { // Цикл по элементам массива
        for (j = 0; j < size; j++) { // Цикл по элементам массива
            if (array[j] > array[i]) { // Сравнение элементов массива
                tmp = array[i]; // Сохранение элемента массива в переменную tmp
                array[i] = array[j]; // Перемещение элемента массива в другую ячейку
                array[j] = tmp; // Перемещение элемента из переменной tmp в ячейку массива
            }
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian"); // Установка русской локали

    // Создание массива объектов класса Money
    Money mas[] = { Money(19,10),
                   Money(99,99),
                   Money(99,95),
                   Money(19,95)
    };

    // Вызов функции сортировки массива
    Sort(mas, sizeof(mas) / sizeof(mas[0]));

    // Вывод содержимого массива на экран
    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++)
        cout << "mas[" << i << "] =  " << mas[i] << endl;

    return 0; // Возврат кода выхода из программы
}
