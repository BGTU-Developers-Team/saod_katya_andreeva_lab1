/*
 * Придумать несколько алгоритмов и сравнить их порядок
сложности в лучшем, среднем и худшем случаях для решения
следующей задачи.
Дана упорядоченная последовательность целых чисел.
Необходимо определить, какие из этих чисел не являются точными
квадратами.
Комментарий 1: операция извлечения корня является очень
трудоемкой.
Комментарий 2: использование квадратного корня можно
заменить последовательностью делений.*/

#include <iostream>

bool isPreciseRoot(int val);

// O(n*log2(N))
void algorithm1(const int *arr, const int &n) {
    for (int i = 0; i < n; ++i) {
        if (!isPreciseRoot(arr[i])) {
            std::cout << arr[i] << '\t';
        }
    }
}

// O(n)
void algorithm2(const int *arr, const int &n) {
    int k = 1;

    for (int i = 0; i < n; ++i) {
        if (k * k > arr[i]) {
            std::cout << arr[i] << '\t';
        } else if (k * k < arr[i]) {
            while (k * k < arr[i]) ++k;

            if (k * k > arr[i])
                std::cout << arr[i] << '\t';
        }
    }
}

// O(n)
void algorithm3(const int *arr, const int length) {

}

bool isPreciseRoot(const int val) {
    int div = 1;
    double operationResult;
    while (true) {
        operationResult = val / div;

        if (operationResult == div)
            return true;
        else if (operationResult > div)
            div++;
        else
            return false;
    }
}

int main() {
    const int lengthUnordered = 12;
    const int lengthOrdered = 10;
    auto arrUnordered = new int[lengthUnordered]{21, 22, 1, 4, 9, 16, 20, 21, 25, 100, 1000, 10000};
    auto arrOrdered = new int[lengthOrdered]{1, 4, 9, 16, 20, 21, 25, 100, 1000, 10000};


    algorithm1(arrUnordered, lengthUnordered); // работает как с упорядоченным, так и не с упорядоченным массивом
    algorithm2(arrOrdered, lengthUnordered); // работает толдько с упорядоченным
    algorithm3(arrOrdered,
               lengthOrdered); // x O(1)-> 1/√x O(1)-> √4(x) -> O(1)√4(x) * √4(x) = √x -> √x * √x + 0.00005 != x


    std::cout << std::endl;

    return 0;
}
