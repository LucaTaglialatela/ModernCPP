#include "sec12_challenge.h"

using namespace std;

int *apply_all(const int *const array1, size_t array1_size, const int *const array2, size_t array2_size) {
    int *result = new int[array1_size * array2_size];

    int idx {0};
    for (size_t i {0}; i < array1_size; i++) {
        for (size_t j {0}; j < array2_size; j++) {
            *(result + idx) = array1[i] * array2[j];
            idx++; 
        }
    }
    return result;
}

void print(const int array[], size_t array_size) {
    cout << "[ ";
    for (size_t i {0}; i < array_size; i++) {
        cout << *(array + i) << ' ';
    }
    cout << ']' << endl;
    return;
}

void section_12_challenge() {
    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};

    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int *result {apply_all(array1, array1_size, array2, array2_size)};
    constexpr size_t result_size {array1_size * array2_size};

    cout << "Result: ";
    print(result, result_size);
    
    return;
}