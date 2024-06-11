#include <iostream>
#include <algorithm>
#include <vector>

void sortArray(int arr[], int n) {
    // Ñîçäàåì äâà îòäåëüíûõ âåêòîðà äëÿ ÷åòíûõ è íå÷åòíûõ ÷èñåë
    std::vector<int> even, odd;

    // Ðàçäåëÿåì ìàññèâ íà ÷åòíûå è íå÷åòíûå ÷èñëà
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even.push_back(arr[i]);
        }
        else {
            odd.push_back(arr[i]);
        }
    }

    // Ñîðòèðóåì ÷åòíûå ÷èñëà ïî âîçðàñòàíèþ
    std::sort(even.begin(), even.end());

    // Ñîðòèðóåì íå÷åòíûå ÷èñëà ïî óáûâàíèþ
    std::sort(odd.begin(), odd.end(), std::greater<int>());

    // Îáúåäèíÿåì îòñîðòèðîâàííûå âåêòîðà ÷åòíûõ è íå÷åòíûõ ÷èñåë â îäèí ìàññèâ
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
