#include "Lab5_5.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

void encrypt_file(const std::string& input_file, const std::string& output_file, const std::string& key) {
    std::ifstream infile(input_file);
    std::ofstream outfile(output_file);

    if (!infile || !outfile) {
        std::cerr << "Ошибка при открытии входного или выходного файла." << std::endl;
        return;
    }

    size_t i = 0;
    char c;
    while (infile.get(c)) {
        outfile << static_cast<char>(c ^ key[i % key.size()]);
        i++;
    }

    infile.close();
    outfile.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input_file, output_file, key;

    std::cout << "Введите имя входного файла: ";
    std::cin >> input_file;

    std::cout << "Введите имя выходного файла: ";
    std::cin >> output_file;

    std::cout << "Введите цифровой ключ: ";
    std::cin >> key;

    encrypt_file(input_file, output_file, key);
    std::cout << "Файл '" << input_file << "' был зашифрован и сохранен в '" << output_file << "' с использованием ключа '" << key << "'." << std::endl;

    return 0;
}
