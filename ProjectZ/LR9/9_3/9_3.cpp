#include "9_3.h" // Подключение заголовочного файла
#include <iostream> // Библиотека для работы с вводом-выводом
#include <string.h> // Библиотека для работы со строками

using namespace std; // Использование пространства имен std

// Шаблонный класс стека
template <class T>
class Tstack {
protected:
    int numItem; // Количество элементов в стеке
    T* item; // Указатель на массив элементов стека
public:
    // Конструктор класса стека
    Tstack(size_t size = 10) {
        numItem = 0;
        item = new T[size];
    }

    // Деструктор класса стека
    ~Tstack() {
        delete[] item;
    }

    // Функция добавления элемента в стек
    void push(T t);

    // Функция извлечения элемента из стека
    T pop();

    // Функция проверки стека на пустоту
    bool isEmpty() {
        return (numItem <= 0);
    }
};

// Реализация функции добавления элемента в стек
template <class T>
void Tstack <T>::push(T t) {
    item[numItem++] = t;
}

// Реализация функции извлечения элемента из стека
template <class T>
T Tstack <T>::pop() {
    return item[--numItem];
}

// Функция вывода массива на экран
void printArr(int a[], int SIZE) {
    cout << " - ";
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " - ";
    }

    cout << endl;
}

// Функция сортировки массива с помощью трех стеков
void  sortStack(const int a[], int SIZE) {
    int max, buff = 0; // Переменные для хранения максимального элемента и буфера
    int s = SIZE; // Количество элементов в массиве
    int arr[s]; // Массив для хранения отсортированных элементов
    Tstack <int> st_left(s); // Левый стек
    Tstack <int> st_right(s); // Правый стек
    Tstack <int> st_bottom(s); // Нижний стек

    // Заполнение левого стека элементами массива
    for (int i = 0; i < s; i++) {
        st_left.push(*(a + i));
    }

    // Цикл сортировки элементов с помощью трех стеков
    while (!(st_left.isEmpty() && st_right.isEmpty()))
    {
        // Перемещение элементов из левого стека в правый стек, и поиск максимального элемента
        while (!st_left.isEmpty()) {
            buff = st_left.pop();
            if (buff > max) max = buff;
            st_right.push(buff);
        }

        // Перемещение элементов из правого стека в левый стек, и добавление максимального элемента в нижний стек
        while (!st_right.isEmpty()) {
            buff = st_right.pop();
            if (buff == max) st_bottom.push(buff);
            else st_left.push(buff);
        }

        // Сброс максимального элемента
        max = 0;
    }

    // Перемещение элементов из нижнего стека в массив
    int i = 0;
    while (!st_bottom.isEmpty()) {
        arr[i] = st_bottom.pop();
        i++;
    }

    // Вывод отсортированного массива на экран
    printArr(arr, s);
}

int main(void) {

    // Создание и инициализация двух массивов
    int n1[] = { 3,5,1 };
    int n2[] = { 1,10,6, 8,3 };
    int s1 = sizeof(n1) / sizeof(int);
    int s2 = sizeof(n2) / sizeof(int);

    // Вывод неотсортированных массивов на экран
    cout << "=== Train unsorted ===" << endl;
    printArr(n1, s1);
    printArr(n2, s2);

    // Вывод отсортированных массивов на экран
    cout << "=== Train sorted ===" << endl;
    sortStack(n1, s1);
    sortStack(n2, s2);

    // Возврат кода выхода из программы
    return 0;
}
