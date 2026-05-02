#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int* matrix, int total_size, int col_size);
int sumMatrix(int* matrix, int total_size);
int colSumMatrix(int* matrix, int total_size, int col_size, int col);

int main() {
    int matrix_0[][3] = {
        {1, 20, 300},
        {400, 50, 6},
        {7, 80, 900}
    };

    int* matrix = &matrix_0[0][0];

    printMatrix(matrix, 9, 3);
    cout << "Sum of the Matrix: " << sumMatrix(matrix, 9) << '\n';
    cout << "Sum of the specified column is: " << colSumMatrix(matrix, 9, 3, 3) << '\n';

    return 0;
}

void printMatrix(int* matrix, int total_size, int col_size) {
    for (int i = 0; i < total_size; i++) {
        cout << setw(6) << *(matrix + i);
        if ((i + 1) % col_size == 0) {
            cout << '\n';
        }
    }
}

int sumMatrix(int* matrix, int total_size) {
    int sum = 0;
    for (int i = 0; i < total_size; i++) {
        sum += *(matrix + i);
    }
    return sum;
}

int colSumMatrix(int* matrix, int total_size, int col_size, int col) {
    if (col < 1 || col > col_size) {
        return 0;
    }

    int colSum = 0;
    int starting_index = col - 1;

    for (int i = starting_index; i < total_size; i += col_size) {
        colSum += *(matrix + i);
    }

    return colSum;
}
