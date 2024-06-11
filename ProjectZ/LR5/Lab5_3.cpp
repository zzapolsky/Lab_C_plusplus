#include "Lab5_3.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


void find_substring(FILE* in, const char* sub) {
    char ch, buffer[100];
    int i = 0;
    while ((ch = getc(in)) != EOF) {
        if (ch == sub[i]) {
            buffer[i] = ch;
            i++;
            if (i == strlen(sub)) {
                printf("Подстрока '%s' найдена в файле\n", sub);
                i = 0;
            }
        }
        else {
            i = 0;
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian");
    char name[50], sub[50];
    FILE* in;
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    if (!(in = fopen(name, "r")))
        printf("Файл %s не открыт\n", name);
    else {
        printf("Введите искомую подстроку: ");
        scanf("%s", sub);
        find_substring(in, sub);
        fclose(in);
    }
    return 0;
}
//   setlocale(LC_ALL, "Russian");
