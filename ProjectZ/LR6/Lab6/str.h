#ifndef STROKA_H
#define STROKA_H

class Stroka {
private:
    char str[80];
public:
    Stroka(const char* string = "");  // ���������� const char*
    Stroka(const Stroka& s);
    ~Stroka();
    Stroka& operator=(const Stroka& s);
    Stroka operator+(const Stroka& s) const;  // const �����
    bool operator==(const Stroka& s) const;   // const �����
    int dlina() const;                        // const �����
    void vvod();
    void vyvod() const;                       // const �����
};

#endif // STROKA_H