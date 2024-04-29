#include <iostream>
#include <algorithm>
#include <vector>

void sortArray(int arr[], int n) {
    // ������� ��� ��������� ������� ��� ������ � �������� �����
    std::vector<int> even, odd;

    // ��������� ������ �� ������ � �������� �����
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even.push_back(arr[i]);
        }
        else {
            odd.push_back(arr[i]);
        }
    }

    // ��������� ������ ����� �� �����������
    std::sort(even.begin(), even.end());

    // ��������� �������� ����� �� ��������
    std::sort(odd.begin(), odd.end(), std::greater<int>());

    // ���������� ��������������� ������� ������ � �������� ����� � ���� ������
    int k = 0;
    for (int i = 0; i < even.size(); i++) {
        arr[k++] = even[i];
    }
    for (int i = 0; i < odd.size(); i++) {
        arr[k++] = odd[i];
    }
}

int main() {
    int arr[] = { 5, 8, 3, 1, 6, 7, 2, 9, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}