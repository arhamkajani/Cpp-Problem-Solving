// Write a function that returns a random alphabet letter. The letter can be any uppercase letter from A to Z, or any lowercase letter from a to z.
// Your function must give uppercase and lowercase letters with equal chance. (This means: 50% chance an uppercase letter, 50% chance a lowercase letter.)
// Inside each group (A–Z or a–z), every letter must also be equally likely.
#include <iostream>
#include <ctime>
int main(){
    srand(time(NULL));
    int num1= rand()%2;
    if(num1==0){
        int k_Upper=rand()%26;
        char RandomLetter ='A' + k_Upper;
        std::cout<<RandomLetter;
    }
    else{
        int k_Lower=rand()%26;
        char RandomLetter ='a' + k_Lower;
        std::cout<<RandomLetter;
    }
    return 0;
}