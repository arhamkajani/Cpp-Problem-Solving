#include <iostream>
using namespace std;
void reverse(int array[],int start, int end);

int main(){
    const int size =6;
    int numbers[size]={1,7,6,3,2,8};
    reverse(numbers,0,size-1);
    for (int i=0; i<size; i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    return 0;
    }
void reverse(int array[], int start, int end){
    if(start>=end) return;
    int temp=array[start];
    array[start]=array[end];
    array[end]=temp;
    reverse(array,start+1,end-1);

}

