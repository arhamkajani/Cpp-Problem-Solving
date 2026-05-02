#include <iostream>
using namespace std;

struct Item{
    int weight;
    bool fragile;
};

int checkBalance(Item items[], int size);

int main(){
    Item items[5]{
        {10, false},
        {20, false},
        {30, true},
        {40, false},   
        {50, true}
    };

    int Total_Sum;

    Total_Sum = checkBalance(items, 5);
    cout << "Total Sum = " << Total_Sum << endl;

    return 0;
}

int checkBalance(Item items[], int size){
    if (size == 0){
        return 0;
    }

    int prevSum = checkBalance(items, size - 1);

    if (prevSum > 100){
        return prevSum;
    }

    int currentWeight;
    if (items[size - 1].fragile){
        currentWeight = 2 * items[size - 1].weight;
    } else {
        currentWeight = items[size - 1].weight;
    }

    int total = prevSum + currentWeight;

    if (total > 100){
        return total;
    }

    return total;
}
