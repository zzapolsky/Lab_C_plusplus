#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Открываем входной и выходной файлы
    std::ifstream input_file("input.txt");
    std::ofstream output_file("output.txt");

    // Проверяем, открылись ли файлы
    if (!input_file.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    if (!output_file.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    // Объявляем переменные для хранения текущей строки, содержимого страницы и номера страницы
    std::string line;
    std::string page_content;
    std::string page_number;

    // Читаем файл строка за строкой
    while (std::getline(input_file, line)) {
        // Ищем номер страницы в текущей строке
        size_t pos = line.find('-');
        if (pos != std::string::npos && line.find('-', pos + 1) != std::string::npos) {
            page_number = line.substr(pos + 1, line.find_last_of('-') - pos - 1);
            // Если номер страницы найден, добавляем остальную часть строки в содержимое страницы
            page_content += line.substr(line.find_last_of('-') + 1) + " ";
        }
        else {
            // Если номер страницы не найден, добавляем текущую строку в содержимое страницы
            page_content += line + " ";
        }

        // Проверяем, является ли текущая строка управляющим символом перехода на новую страницу
        if (line.find("\f") != std::string::npos) {
            // Если номер страницы уже найден, выводим содержимое страницы и номер страницы в выходной файл
            if (!page_number.empty()) {
                output_file << page_content << page_number << std::endl;
                page_content.clear();
                page_number.clear();
            }
        }
    }

    if (!page_number.empty()) {
        output_file << page_content << page_number << std::endl;
   }

    // Закрываем входной и выходной файлы
    input_file.close();
    output_file.close();

    return 0;
}
