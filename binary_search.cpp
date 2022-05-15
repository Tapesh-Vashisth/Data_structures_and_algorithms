#include <iostream>
using namespace std;

int binary_search(int * array, int start, int end, int value);

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length = sizeof(array)/sizeof(int);
    cout << binary_search(array, 0, length, 4) << endl;
    return 0;
}

int binary_search(int * array, int start, int end, int value){
    if (end - start <= 1){
        if (array[start] == value){
            return start;
        }else{
            return -1;
        }
    }else{
        int decider = start + (end - start)/2;
        if (array[decider] > value){
            return binary_search(array, start, decider, value);
        }else if(array[decider] < value){
            return binary_search(array, decider + 1, end, value);
        }else{
            return decider;
        }

    }
}