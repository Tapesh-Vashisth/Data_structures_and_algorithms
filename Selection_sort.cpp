#include <iostream>
using namespace std;

void selection_sort(int * array, int length);

int main(){
    int array[] = {23, 2, 30, 3, 55, 32, 23, 0, 45, 80};
    int length = sizeof(array)/sizeof(int);
    selection_sort(array, length);
    for (int i= 0; i < length; i++){
        cout << array[i] << endl;
    }
    return 0;
}


void selection_sort(int * array, int length){
    for (int i = 0; i < length; i++){
        int min = i;

        for (int j = i; j < length; j++){
            if(array[min] > array[j]){
                min = j; 
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}