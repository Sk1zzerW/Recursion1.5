#include <iostream>
using namespace std;

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

int maxVal(int a, int b, int c) {
    return maxVal(maxVal(a, b), c);
}

int maxVal(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int maxVal(int** arr, int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}

int maxVal(int*** arr, int x, int y, int z) {
    int max = arr[0][0][0];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                if (arr[i][j][k] > max) max = arr[i][j][k];
            }
        }
    }
    return max;
}

int main() {
    int a = 10, b = 20, c = 15;
    cout << "максимум из двух чисел " << maxVal(a, b) << endl;
    cout << "ммаксимум из трех чисел " << maxVal(a, b, c) << endl;

    int arr1D[5] = { 1, 5, 3, 9, 2 };
    cout << "максимум в одномерном массиве " << maxVal(arr1D, 5) << endl;

    int rows = 2, cols = 3;
    int** arr2D = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr2D[i] = new int[cols] {i + 1, i + 2, i + 3};
    }
    cout << "максимум в двумерном массиве " << maxVal(arr2D, rows, cols) << endl;

    int x = 2, y = 2, z = 2;
    int*** arr3D = new int** [x];
    for (int i = 0; i < x; i++) {
        arr3D[i] = new int* [y];
        for (int j = 0; j < y; j++) {
            arr3D[i][j] = new int[z] {i + j + 1, i + j + 2};
        }
    }
    cout << "максимум в трехмерном массиве " << maxVal(arr3D, x, y, z) << endl;

    for (int i = 0; i < rows; i++) delete[] arr2D[i];
    delete[] arr2D;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) delete[] arr3D[i][j];
        delete[] arr3D[i];
    }
    delete[] arr3D;

    return 0;
}
