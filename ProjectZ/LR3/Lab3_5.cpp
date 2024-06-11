#include <iostream>
#include <algorithm>

void sort_array_interval(int arr[], int n, int start, int end) {
    if (start < 0 || end >= n || start > end) {
        std::cout << "Неверный интервал индексов" << std::endl;
        return;
    }

    std::sort(arr + start, arr + end + 1, std::greater<int>());

    std::cout << "Отсортированный интервал: ";
    for (int i = start; i <= end; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 12, 3, 5, 7, 8, 9, 1, 6, 15, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 2;
    int end = 6;

    sort_array_interval(arr, n, start, end);

    return 0;
}
