#include <iostream>
#include "Lab4_1.h"
#include <cstring>
#include <locale.h>
#include <stdlib.h>
#include <memory>
using namespace std;

// ������� 1 ��� ����������� ����� ������
int Lab4_1::dlina1(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

// ������� 2 ��� ����������� ����� ������
int Lab4_1::dlina2(char* str) {
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		len++;
	}
	return len;
}

// ������� 3 ��� ����������� ����� ������
int Lab4_1::dlina3(char* str) {
	return strlen(str);
}

// ������� ��� ��������� ������ � ����������� ������
char* Lab4_1::kopir(char* str2) {
	int len = Lab4_1::dlina1(str2);
	char* str1 = (char*)malloc((len + 1) * sizeof(char));
	for (int i = 0; i <= len; i++) {
		str1[i] = str2[i];
	}
	return str1;
}

// ������� ��� ��������� �����
int Lab4_1::sravn(char* str1, char* str2) {
	return strcmp(str1, str2);
}

// ������� ��� ������������ �����
char* Lab4_1::konkat(char* str1, char* str2) {
	int len1 = Lab4_1::dlina1(str1);
	int len2 = Lab4_1::dlina1(str2);
	str1 = (char*)realloc(str1, (len1 + len2 + 1) * sizeof(char));
	for (int i = 0; i < len2; i++) {
		str1[len1 + i] = str2[i];
	}
	str1[len1 + len2] = '\0';
	return str1;
}

int main() {


	setlocale(LC_ALL, "Russian");

	//������� malloc
	/*char* str1, * str2;
	str1 = (char*)malloc(100 * sizeof(char));
	memcpy(str1, "qwerty", strlen("qwerty") + 1);

	str2 = (char*)malloc(100 * sizeof(char));
	memcpy(str2, "123456789", strlen("123456789") + 1);
	*/
	//������� calloc
	

	char* str1, * str2;
	str1 = (char*)calloc(100, sizeof(char));
	memcpy(str1, "qwerty", 7); // �������� 6 �������� ���� ����������� ����

	str2 = (char*)calloc(100, sizeof(char));
	memcpy(str2, "123456789", 10); // �������� 9 �������� ���� ����������� ����




	//������������� ������� ����� ������

	cout << "����� str1= " << Lab4_1::dlina1(str1) << " , str2= ";
	cout << Lab4_1::dlina1(str2) << endl;

	cout << "����� str1= " << Lab4_1::dlina2(str1) << " , str2= ";
	cout << Lab4_1::dlina2(str2) << endl;

	cout << "����� str1= " << Lab4_1::dlina3(str1) << " , str2= ";
	cout << Lab4_1::dlina3(str2) << endl;

	cout << "��������� ���������: str1= " << str1;
	cout << ", str2=" << str2 << ", " << Lab4_1::sravn(str1, str2) << endl;

	Lab4_1::konkat(str1, str2);
	cout << "��������� ���������: str1= " << str1;
	cout << ", str2=" << str2 << endl;

	char* str3 = Lab4_1::kopir(str2);
	cout << "��������� �����������: str3= " << str3;
	cout << ", str2=" << str2 << endl;

	free(str1);
	free(str2);
	free(str3);

	return 0;
}