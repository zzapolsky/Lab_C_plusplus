#include <iostream>
#include "List.h"

using namespace std;  // Использование стандартного пространства имен

struct Bus {  // Структура Bus, содержащая номер автобуса, имя водителя и номер маршрута
private:
    int bus_number;
    char* bus_driver;
    int bus_route;

public:
// Конструктор по умолчанию
    Bus() {};
// Конструктор с параметрами
    Bus(int number, char* driver, int route) {
        this->bus_number = number;
        this->bus_driver = driver;
        this->bus_route = route;
    }
 // Функция-сеттер для номера автобуса
    void setBusNumber(int busNumber) {
        bus_number = busNumber;
    }
  // Функция-сеттер для имени водителя
    void setBusDriver(char* busDriver) {
        bus_driver = busDriver;
    }
 // Функция-сеттер для номера маршрута
    void setBusRoute(int busRoute) {
        bus_route = busRoute;
    }
 // Функция-геттер для номера автобуса
    int getBusNumber() const {
        return bus_number;
    }
// Функция-геттер для имени водителя
    char* getBusDriver() const {
        return bus_driver;
    }
 // Функция-геттер для номера маршрута
    int getBusRoute() const {
        return bus_route;
    }

};
// Функция для вывода информации об автобусе
void printBus(Bus bus) {
    cout << "Bus number = " << bus.getBusNumber() << ", driver = " << bus.getBusDriver() << ", route = " << bus.getBusRoute() << " ;" << endl;
}
// Функция для вывода списка автобусов
void printBusList(char* def, List <Bus> name) {
    cout << "\t\t\t\t" << def << endl;
    int length = name.getSIZE();
    if (length == 0) {
        cout << "No Bus Present" << endl;
        cout << "\t\t\t\t***************\n\n" << endl;
        return;
    }
    for (int i = 0; i < length; i++) printBus(name[i]);
    cout << "\t\t\t\t***************\n\n" << endl;
}
// Функция для получения индекса автобуса в списке
auto getIndex(List<Bus> bus, int index) {
    for (int i = 0; i < bus.getSIZE(); i++) {
        if (index == bus[i].getBusNumber()) {
            return i;
        }
    }
    cout << "wrong number";
}


int main() {
    int choice;
     // Список автобусов на стоянке
    List<Bus> BusInPark;
     // Список автобусов в движении
    List<Bus> BusOnRoute;
    // Добавление автобусов в список BusInPark
    BusInPark.push_front(*new Bus(111, "Ivanov", 65));
    BusInPark.push_back(*new Bus(222, "Petrov", 69));
    BusInPark.push_back(*new Bus(333, "Sidorov", 64));
    cout << "\t\t\t\tWelcome to Bus tracker!\n" << "\t\t\t\t***************\n\n" << endl;
    printBusList("Bus in park list", BusInPark);
    printBusList("Bus on route list", BusOnRoute);

    // Главный цикл меню
    while (choice != 5) {
        int index;
        cout << "Bus Tracker menu:" << endl;
        cout << "1. To print bus in park list enter - \" 1 \"" << endl;
        cout << "2. To print bus on route list enter - \" 2 \"" << endl;
        cout << "3. To track bus leaving park enter - \" 3 \"" << endl;
        cout << "4. To track bus entering park enter- \" 4 \"" << endl;
        cout << "5. To exit bus tracker enter- \" 5 \"" << endl;
        cin >> choice;
        cout << endl;
         // Вывод списков автобусов на основе ввода пользователя
        if (choice == 1) printBusList("Bus in park list", BusInPark);
        if (choice == 2) printBusList("Bus on route list", BusOnRoute);
         // Отслеживание автобуса, покидающего стоянку
        if (choice == 3) {
            cout << "Please enter bus number leaving park" << endl;
            cin >> index;
            BusOnRoute.push_back(BusInPark[getIndex(BusInPark, index)]);
            BusInPark.remove(getIndex(BusInPark, index));
            cout << "bus number " << index << " left the park" << endl;
        }
         // Отслеживание автобуса, прибывающего на стоянку
        if (choice == 4) {
            cout << "Please enter bus number entering park" << endl;
            cin >> index;
            BusInPark.push_back(BusOnRoute[getIndex(BusOnRoute, index)]);
            BusOnRoute.remove(getIndex(BusOnRoute, index));
            cout << "bus number " << index << " entered the park" << endl;
        }

    }
    cout << "Goodbye";
    return 0;
}
