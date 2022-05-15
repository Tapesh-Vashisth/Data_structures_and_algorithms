#include <iostream>
using namespace std;

void Insertion_sort(int * array, int length);

int main(){
    int array[] = {23, 2, 30, 3, 55, 32, 23, 0, 45, 80};
    int length = sizeof(array)/sizeof(int);
    Insertion_sort(array, length);
    for (int i= 0; i < length; i++){
        cout << array[i] << endl;
    }
    return 0;
}

void Insertion_sort(int * array, int length){
    for (int i = 1; i < length; i++){
        // int grab = array[i];
        for (int j = 0; j < i; j++){
            if (array[j] <= array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                
            }
            for (int i= 0; i < length; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
}