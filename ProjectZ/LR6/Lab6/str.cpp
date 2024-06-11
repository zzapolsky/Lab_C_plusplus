#include <iostream> 
#include <cstring> 
#include "str.h" 

using namespace std; 

Stroka::Stroka(const char* string) { // ����������� ������ Stroka, ����������� const char*
    strcpy(str, string); // �������� ������ string � ���� str ������ Stroka
}

Stroka::Stroka(const Stroka& s) { // ����������� ����������� ������ Stroka
    strcpy(str, s.str); // �������� ������ s.str � ���� str ������ Stroka
}

Stroka::~Stroka() { // ���������� ������ Stroka
    // ���������� (�� ��������� ����� ��������, ��� ��� ��� ������������ ������)
}

Stroka& Stroka::operator=(const Stroka& s) { // ���������� ��������� ������������ ��� ������ Stroka
    if (this != &s) { // ���������, �� �������� �� ������ s ������� ��������
        strcpy(str, s.str); // �������� ������ s.str � ���� str ������ Stroka
    }
    return *this; 
}

Stroka Stroka::operator+(const Stroka& s) const { // ���������� ��������� �������� ��� ������ Stroka (const �����)
    Stroka temp; 
    strcpy(temp.str, str); // �������� ������ str � ���� str ���������� �������
    strcat(temp.str, s.str); // ������������� ������ s.str � ������ str ���������� �������
    return temp; 
}

bool Stroka::operator==(const Stroka& s) const { // ���������� ��������� ��������� ��� ������ Stroka (const �����)
    return strcmp(str, s.str) == 0; // ���������� ������ str � s.str � ������� ������� strcmp � ���������� ���������
}

int Stroka::dlina() const { // ����� dlina ������ Stroka (const �����)
    return strlen(str); // ���������� ����� ������ str � ������� ������� strlen
}

void Stroka::vvod() { // ����� vvod ������ Stroka
    cin >> str; // ������ ������ � ������� ������������ ������ ����� cin
}

void Stroka::vyvod() const { // ����� vyvod ������ Stroka (const �����)
    cout << str; // ������� ������ � ������� ������������ ������ ������ cout
}
