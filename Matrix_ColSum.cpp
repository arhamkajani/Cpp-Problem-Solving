#include <iostream>
#include <iomanip>
using namespace std;
void printMatrix(int* matrix, int total_size, int col_size);
int sumMatrix(int* matrix, int total_size);
int colSumMatrix(int* matrix, int total_size, int col_size, int col);

int main(){
    int matrix_0[][3]={{1,20,300},{400,50,6},{7,80,900}};
    int* matrix=&matrix[0];
    printMatrix(&matrix[0],9,3);
    cout<<sumMatrix(&matrix[0],9)<<'\n';
    cout<<colSumMatrix(&matrix[0],9,3,3);

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
int sumMatrix(int* matrix, int total_size){
    int sum=0;
    for(int i=0; i< total_size; i++){
        sum+= *(matrix + i);
    }
    return sum;
}
int colSumMatrix(int* matrix, int total_size, int col_size, int col) {
    int colSum = 0;
    int Starting_index;

    cout << "Enter the column number: ";
    cin >> col;

    Starting_index = col - 1; 

    for (int i = Starting_index; i < total_size; i += col_size) {
        colSum += *(matrix + i);
    }

    return colSum;
}
