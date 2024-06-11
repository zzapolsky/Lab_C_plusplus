#include <iostream> // ���������� ��� ������ � ������-�������
#include <locale.h> // ���������� ��� ������ � ��������
#include "Money.h" // ����������� ������������� ����� ������ Money

using namespace std; // ������������� ������������ ���� std

// ��������� ������� ���������� �������
template <class T>
void Sort(T array[], size_t size) {
    int i, j;
    T tmp;
    for (i = 0; i < size; i++) { // ���� �� ��������� �������
        for (j = 0; j < size; j++) { // ���� �� ��������� �������
            if (array[j] > array[i]) { // ��������� ��������� �������
                tmp = array[i]; // ���������� �������� ������� � ���������� tmp
                array[i] = array[j]; // ����������� �������� ������� � ������ ������
                array[j] = tmp; // ����������� �������� �� ���������� tmp � ������ �������
            }
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian"); // ��������� ������� ������

    // �������� ������� �������� ������ Money
    Money mas[] = { Money(19,10),
                   Money(99,99),
                   Money(99,95),
                   Money(19,95)
    };

    // ����� ������� ���������� �������
    Sort(mas, sizeof(mas) / sizeof(mas[0]));

    // ����� ����������� ������� �� �����
    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++)
        cout << "mas[" << i << "] =  " << mas[i] << endl;

    return 0; // ������� ���� ������ �� ���������
}
