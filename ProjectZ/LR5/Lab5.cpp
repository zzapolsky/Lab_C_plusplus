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
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    if (!(in = fopen(name, "r")))
        printf("Файл %s не открыт\n", name);
    else {
        while ((ch = getc(in)) != EOF) {
            putchar(ch);
            if (ch == ' ')
                empty_chars++;
            else
                non_empty_chars++;
        }
        fclose(in);
        printf("\nПустых символов: %d\n", empty_chars);
        printf("Непустых символов: %d\n", non_empty_chars);
    }
    return 0;
}
/*void main(void)
{
	char ch, name[50];
		FILE* in;
		printf("Введите имя файла для просмотра:");
		scanf("%s", name);
		if ((in = fopen(name, "r")) == NULL)
			printf("Файл %s не открыт", name);
		else
			while (!feof(in))
		{
			ch = getc(in);
			putchar(ch);
		}
}*/
