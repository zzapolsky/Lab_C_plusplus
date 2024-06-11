#include <iostream>
#include <string.h>

using namespace std;

template <class T>
T getmax(T t1, T t2)		//Возврашает больший из двух
{					// параметров
    return t1 > t2 ? t1 : t2;
}
const char* getmax(const char* s1, const char* s2) {
    return strcmp(s1, s2) > 0 ? s1 : s2;
}
template <class T>
T getmax(T t[], size_t size)
{
    T retval = t[0];
    int i;
    for (i = 0; i < size; i++)
        if (t[i] > retval) retval = t[i];
    return retval;
}

int main(void)
{
    int i1 = 3, i2 = 5;
    char* s1 = "string1";
    char* s2 = "string2";
    cout << "max int = " << getmax(i1, i2) << endl;
    cout << "max str = " << getmax(s1, s2) << endl;
    return 0;
}

