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
#include <limits>

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
    int k = 1;
    int k2 = 1;

    int i = 0;

    while (k2 <= arr[length - 1] && i < length) {
        if (k2 == arr[i])
            ++i;
        else {
            if (k2 > arr[i]) {
                std::cout << arr[i] << '\t';
                ++i;
            } else {
                ++k;
                k2 = k * k;
            }
        }
    }
}

float Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *) &i;
    y = y * (threehalfs - (x2 * y * y));

    return y;
}

// O(n)
void algorithm4(const int arr[], const int &length) {
    for (int i = 0; i < length; ++i) {
        float sqrt = 1 / Q_rsqrt(static_cast<float>(arr[i]));
        int sqrt_i = (int) sqrt;
        if (arr[i] / sqrt_i != sqrt_i) {
            std::cout << arr[i] << '\t';
        }
    }
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

    int choice;
    bool isFinished = false;

    while (!isFinished) {
        std::cout << "Choose algorithm (1, 2, 3 or 4, 0 - exit): ";
        std::cin >> choice;

        while (std::cin.fail() || (choice < 0 || 4 < choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cout << "Bad entry. Choose algorithm (1, 2, 3 or 4): ";
            std::cin >> choice;
        }


        switch (choice) {
            case 0:
                isFinished = true;
                break;
            case 1:
                // работает как с упорядоченным, так и не с упорядоченным массивом
                algorithm1(arrOrdered, lengthOrdered);
                break;

            case 2:
                // работает толдько с упорядоченным
                algorithm2(arrOrdered, lengthOrdered);
                break;

            case 3:
                algorithm3(arrOrdered, lengthOrdered);
                break;

            case 4:
                // x [O(1)->] 1/√x [O(1)->] √x
                algorithm4(arrOrdered, lengthOrdered);
                break;

            default:
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}
