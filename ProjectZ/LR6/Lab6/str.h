#ifndef STROKA_H
#define STROKA_H

class Stroka {
private:
    char str[80];
public:
    Stroka(const char* string = "");  
    Stroka(const Stroka& s);
    ~Stroka();
    Stroka& operator=(const Stroka& s);
    Stroka operator+(const Stroka& s) const;  
    bool operator==(const Stroka& s) const;   
    int dlina() const;                       
    void vvod();
    void vyvod() const;                     
};

#endif 
