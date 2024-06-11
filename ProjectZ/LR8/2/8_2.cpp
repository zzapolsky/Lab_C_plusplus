#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <thread> // ��������� ���������� ��� ������ � ��������

class FileEncryptor { // ������ ����� FileEncryptor
public:
    void encrypt_file(const std::string& input_file, const std::string& output_file, const std::string& key) {
        std::ifstream infile(input_file);
        std::ofstream outfile(output_file);

        if (!infile || !outfile) {
            std::cerr << "������ ��� �������� �������� ��� ��������� �����." << std::endl;
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
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input_file, output_file, key;

    std::cout << "������� ��� �������� �����: ";
    std::cin >> input_file;

    std::cout << "������� ��� ��������� �����: ";
    std::cin >> output_file;

    std::cout << "������� �������� ����: ";
    std::cin >> key;

    FileEncryptor encryptor; // ������ ��������� ������ FileEncryptor
    std::thread encrypt_thread(&FileEncryptor::encrypt_file, &encryptor, input_file, output_file, key); // ������ �����, ����������� ����� encrypt_file
    encrypt_thread.join(); // �������� ���������� ������
    std::cout << "���� '" << input_file << "' ��� ���������� � �������� � '" << output_file << "' � �������������� ����� '" << key << "'." << std::endl;

    return 0;
}
