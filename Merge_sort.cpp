#include <iostream>
#include <malloc.h>
using namespace std;

void merge_sort(int * array, int start, int end);
void merge(int * array, int start, int divider, int end);

int len = 10;

int main(){
    int array[] = {23, 2, 30, 3, 0, 55, 32, 23, 45, 80};
    int length = sizeof(array)/sizeof(int);
    merge_sort(array, 0, length);
    for (int i= 0; i < length; i++){
        cout << array[i] << endl;
    }
    return 0;
}

void merge_sort(int * array, int start, int end){
    if (end - start <= 1){
        ;
    }else{
        int divider = start + (end-start)/2;
        merge_sort(array, start, divider);
        merge_sort(array, divider, end);
        merge(array, start, divider, end);
    }
}

void merge(int * array, int start, int divider, int end){
    int * first = (int *)malloc(sizeof(int) * (divider - start));
    int * second = (int *)malloc(sizeof(int) * (end - divider));
    for (int i = 0; i < divider - start; i++){
        first[i] = array[start + i];
    }
    for (int i = 0; i < end - divider; i++){
        second[i] = array[divider + i];
    }
    int first_c = 0;
    int second_c = 0;
    for (int i = start; i < end; i++){
        if (first_c < divider - start && second_c < end - divider){
            if (*first >= *second){
                array[i] = *second;
                second++;
                second_c++;
            }else{
                array[i] = *first;
                first++;
                first_c++;
            }
        }else{
            if(first_c >= divider - start){
                array[i] = *second;
                second++;
                second_c++;
            }else{
                array[i] = *first;
                first++;
                first_c++;
            }
        }
    }
    free(first);
    free(second);
}


