#include "Stroka.h"
#include <cstring>
#include <iostream>
#include <typeinfo>

static int myStrlen(const char* p);
static void myStrcpy(char* a, char* b);
static int myStrcmp(char* a, char* b);
static char* myStrcat(char* a, char* b);

Stroka::Stroka() {
	this->str = nullptr;
	std::cout << "Constructor " << this << std::endl;
}

Stroka::~Stroka() {
	delete this->str;
	std::cout << "Destructor " << this << std::endl;
}

Stroka::Stroka(char* s)
{
	this->str = new char[myStrlen(s)];
	myStrcpy(this->str, s);
	std::cout << "Constructor " << this << " " << str << std::endl;
}

Stroka::Stroka(const Stroka& s) {
	this->str = new char[myStrlen(s.str)];
	myStrcpy(this->str, s.str);
	std::cout << "Constructor " << this << " " << str << std::endl;
}

Stroka& Stroka::operator=(const Stroka& s) {
	if (this->str != nullptr) delete this->str;
	this->str = new char[myStrlen(s.str)];
	myStrcpy(this->str, s.str);
	return *this;
}

Stroka& Stroka::operator=(const char* s) {
	if (this->str != nullptr) delete this->str;
	this->str = new char[myStrlen(s)];
	myStrcpy(this->str, (char*)s);
	return *this;
}

Stroka& Stroka::operator+(const Stroka& s) {
	char buff[1024];
	myStrcpy(buff, this->str);
	myStrcat(buff, s.str);
	delete this->str;
	this->str = new char[myStrlen(buff)];
	myStrcpy(this->str, buff);
	return *this;
}

int Stroka::operator ==(const Stroka& s) {
	if ((myStrcmp(this->str, s.str)) == 0)
		return 0;
	else
		return 1;
}

int Stroka::dlina() {
	return myStrlen(this->str);
}

std::istream& operator >>(std::istream& is, Stroka& cl) {
	char temp[1024];
	char c = 0;
	int i = 0;
	while (!is.eof()) {
		c = (char)is.get();
		if (c == '\n') 	break;
		*(temp + i) = c;
		i++;
	}
	*(temp + i) = '\0';
	cl.str = temp;
	return is;
}

std::ostream& operator <<(std::ostream& os, const Stroka& cl) {
	if (cl.str == nullptr) {
		os
			<< " = (\"" "\")";
		return os;
	}
	os
		<< typeid(cl).name()
		<< " = (\""
		<< cl.str
		<< "\")";
	return os;
}

static int myStrlen(const char* p)
{
	int i = 0;
	while (*p++)
		i++;
	return i;
}

static void myStrcpy(char* a, char* b)
{
	int k = 0;
	char* pa = a;
	char* pb = b;
	while (*b++ != '\0')
	{
		*(pa + k) = *(pb + k);
		k++;
	}

}


static int myStrcmp(char* a, char* b) {
	if (myStrlen(a) != myStrlen(b))
		return 0;
	for (int k = 0; a[k] != '\0'; k++) {
		if (a[k] != b[k])
			return 0;
	}
	return 1;
}

static char* myStrcat(char* a, char* b)
{
	int k = 0;
	int n = 0;
	char* pa = a;
	char* pb = b;
	char* pc = new char[(myStrlen(a) + myStrlen(b))];
	while (*a++ != '\0')
	{
		*(pc + k) = *(pa + k);
		k++;
	}
	while (*b++ != '\0')
	{
		*(pc + k) = *(pb + n);
		k++;
		n++;
	}
	return pc;
}