#include <iostream>
#include <algorithm>

void sort_array_interval(int arr[], int n, int start, int end) {
    if (start < 0 || end >= n || start > end) {
        std::cout << "Íåâåðíûé èíòåðâàë èíäåêñîâ" << std::endl;
        return;
    }

    std::sort(arr + start, arr + end + 1);

    std::cout << "Îòñîðòèðîâàííûé èíòåðâàë: ";
    for (int i = start; i <= end; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 12, 3, 5, 7, 8, 9, 1, 6, 15, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 3;
    int end = 9;

    sort_array_interval(arr, n, start, end);

    return 0;
}
