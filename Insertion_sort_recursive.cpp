#include <iostream>
using namespace std;

void Rinsertion_sort(int * array, int length);

int main(){
    int array[] = {23, 2, 30, 3, 55, 32, 23, 0, 45, 80};
    int length = sizeof(array)/sizeof(int);
    Rinsertion_sort(array, length);
    for (int i= 0; i < length; i++){
        cout << array[i] << endl;
    }
    return 0;
}


void Rinsertion_sort(int * array, int length){
    static int main_index = 1;
    if(main_index >= length){
        ;
    }else{
        int exchange = array[main_index];
        int count = 0;
        int temp;
        for (int i = 0; i < main_index; i++){
            if(array[i] > array[main_index] && count == 0){
                temp = array[i+1];
                array[i+1] = array[i];
                array[i] = exchange;
                int holder;
                for (int j = i+1; j < main_index; j++){
                    holder = array[j+1];
                    array[j+1] = temp;
                    temp = holder;
                }
                break;
            }        
        }    
        main_index++;
        Rinsertion_sort(array, length);
    }
}