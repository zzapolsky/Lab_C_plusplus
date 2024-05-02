#include "Lab5.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


int main(void) {
    setlocale(LC_ALL, "Russian");
    char name[50], ch;
    int empty_chars = 0, non_empty_chars = 0;
    FILE* in;
    printf("������� ��� ����� ��� ���������: ");
    scanf("%s", name);
    if (!(in = fopen(name, "r")))
        printf("���� %s �� ������\n", name);
    else {
        while ((ch = getc(in)) != EOF) {
            putchar(ch);
            if (ch == ' ')
                empty_chars++;
            else
                non_empty_chars++;
        }
        fclose(in);
        printf("\n������ ��������: %d\n", empty_chars);
        printf("�������� ��������: %d\n", non_empty_chars);
    }
    return 0;
}
/*void main(void)
{
	char ch, name[50];
		FILE* in;
		printf("������� ��� ����� ��� ���������:");
		scanf("%s", name);
		if ((in = fopen(name, "r")) == NULL)
			printf("���� %s �� ������", name);
		else
			while (!feof(in))
		{
			ch = getc(in);
			putchar(ch);
		}
}*/