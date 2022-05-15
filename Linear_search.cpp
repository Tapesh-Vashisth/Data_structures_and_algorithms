#include <iostream>
using namespace std;

int linear_search(int * array, int length, int value);

int main(){
    int array[] = {23, 2, 30, 3, 55, 32, 23, 0, 45, 80};
    int length = sizeof(array)/sizeof(int);
    int index = linear_search(array, length, 30);
    cout << index;
    return 0;
}

int linear_search(int * array, int length, int value){
    for (int i = 0; i < length; i++){
        if(value == array[i]){
            return i;
        }
    }
    return -1;
}