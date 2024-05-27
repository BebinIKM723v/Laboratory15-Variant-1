#include <iostream>
using namespace std;
#include "windows.h"

void selectionSortDescending(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        int max = i;
        for (int j = i + 1; j < array_size; j++) {
            if (array[j] > array[max]) {
                max = j;
            }
        }
        if (i != max) {
            int temp = array[i];
            array[i] = array[max];
            array[max] = temp;
        }
    }
}

void bubbleSortDescending(int array[], int array_size) {
    for (int i = 0; i < array_size - 1; i++) {
        for (int j = 0; j < array_size - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void generateFibonacciArray(int array[], int array_size) {
    if (array_size > 0) array[0] = 0;
    if (array_size > 1) array[1] = 1;
    for (int i = 2; i < array_size; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int array_size = 10;
    int fibonacciArray[array_size];

    generateFibonacciArray(fibonacciArray, array_size);

    cout << "Масив чисел Фібоначчі:" << endl;
    printArray(fibonacciArray, array_size);

    int selectionSortedArray[array_size];
    copy(begin(fibonacciArray), end(fibonacciArray), begin(selectionSortedArray));
    selectionSortDescending(selectionSortedArray, array_size);
    cout << "Масив після сортування методом вибору за спаданням:" << endl;
    printArray(selectionSortedArray, array_size);

    int bubbleSortedArray[array_size];
    copy(begin(fibonacciArray), end(fibonacciArray), begin(bubbleSortedArray));
    bubbleSortDescending(bubbleSortedArray, array_size);
    cout << "Масив після сортування методом бульбашки за спаданнямм:" << endl;
    printArray(bubbleSortedArray, array_size);

    return 0;
}