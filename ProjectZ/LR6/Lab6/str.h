#ifndef STROKA_H
#define STROKA_H

class Stroka {
private:
    char str[80];
public:
    Stroka(const char* string = "");  // Используем const char*
    Stroka(const Stroka& s);
    ~Stroka();
    Stroka& operator=(const Stroka& s);
    Stroka operator+(const Stroka& s) const;  // const метод
    bool operator==(const Stroka& s) const;   // const метод
    int dlina() const;                        // const метод
    void vvod();
    void vyvod() const;                       // const метод
};

#endif // STROKA_H