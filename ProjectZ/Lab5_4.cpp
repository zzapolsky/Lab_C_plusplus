#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // ��������� ������� � �������� �����
    std::ifstream input_file("input.txt");
    std::ofstream output_file("output.txt");

    // ���������, ��������� �� �����
    if (!input_file.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    if (!output_file.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    // ��������� ���������� ��� �������� ������� ������, ����������� �������� � ������ ��������
    std::string line;
    std::string page_content;
    std::string page_number;

    // ������ ���� ������ �� �������
    while (std::getline(input_file, line)) {
        // ���� ����� �������� � ������� ������
        size_t pos = line.find('-');
        if (pos != std::string::npos && line.find('-', pos + 1) != std::string::npos) {
            page_number = line.substr(pos + 1, line.find_last_of('-') - pos - 1);
            // ���� ����� �������� ������, ��������� ��������� ����� ������ � ���������� ��������
            page_content += line.substr(line.find_last_of('-') + 1) + " ";
        }
        else {
            // ���� ����� �������� �� ������, ��������� ������� ������ � ���������� ��������
            page_content += line + " ";
        }

        // ���������, �������� �� ������� ������ ����������� �������� �������� �� ����� ��������
        if (line.find("\f") != std::string::npos) {
            // ���� ����� �������� ��� ������, ������� ���������� �������� � ����� �������� � �������� ����
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

    // ��������� ������� � �������� �����
    input_file.close();
    output_file.close();

    return 0;
}
