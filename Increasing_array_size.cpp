#include <iostream>
using namespace std;

int * increased_array(int * array, int newsize){
    int * new_array = new int[newsize];
    for(int i = 0; i < newsize; i++){
        new_array[i] = array[i];
    }
    delete [] array;
    array = new_array;
    new_array = NULL;
}

int main(){
    int * initial = new int[10];
    cout << initial << endl;
    initial = increased_array(initial, 15);
    cout << initial << endl;
    return 0;
}