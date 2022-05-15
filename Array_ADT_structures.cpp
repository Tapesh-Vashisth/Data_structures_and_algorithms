#include <iostream>
using namespace std;

struct array{
    int * list;
    int length;
    int size;
};

void initialise(array &arr){
    arr.list = new int[arr.size];
    arr.length = 0;
}

void Display(array &arr){
    for (int i = 0; i < arr.length; i++){
        cout << endl << arr.list[i];
    }
    cout << endl;
}

void append(array &arr, int x){
    if (arr.length >= arr.size){
                cout << "list is already full" << endl;
            }else{
                arr.list[arr.length] = x;
                arr.length++;
            }
}

void insert(array &arr, int x, int index){
    if (arr.length >= arr.size){
        cout << "space not enough for inserting!" << endl;
    }else{
        int temp = x;
        for (int i = index; i < arr.length + 1; i++){
            int holder = arr.list[i];
            arr.list[i] = temp;
            temp = holder;
        }
        arr.length++;
        cout << "successfully inserted!" << endl;
    }
}

void remove(array &arr, int index){
    if (index < 0 && index >= arr.length){
        cout << "invalid index!" << endl;
    }else{
        for (int i = index; i < arr.length - 1; i++){
            arr.list[i] = arr.list[i + 1];
        }
        arr.length--;
    }
}

int linear_search(array arr, int value){
    for (int i = 0; i < arr.length; i++){
        if(value == arr.list[i]){
            return i;
        }
    }
    return -1;
}

int binary_search(array arr, int low, int high, int value){
    if (low <= high){
        int middle = (low + high)/2;
        if (arr.list[middle] > value){
            return binary_search(arr, low, middle - 1, value);
        }else if(arr.list[middle] < value){
            return binary_search(arr, middle + 1, high, value);
        }else{
            return middle;
        }
    }
    return -1;
}

int get(array arr, int index){
    if (index < arr.length && index >= 0){
        return arr.list[index];
    }else{
        cout << "invalid index" << endl;
    }
}

int max(array arr){
    int m = arr.list[0];
    for (int i = 0; i < arr.length; i++){
        if (arr.list[i] > m){
            m = arr.list[i];
        }
    }
    return m;
}

int min(array arr){
    int m = arr.list[0];
    for (int i = 0; i < arr.length; i++){
        if (arr.list[i] < m){
            m = arr.list[i];
        }
    }
    return m;
}

int sum(array arr){
    int sum = 0;
    for (int i = 0; i < arr.length; i++){
        sum += arr.list[i];
    }
    return sum;
}

void reverse(array arr){
    for (int i = 0; i < arr.length/2; i++){
        int temp = arr.list[i];
        arr.list[i] = arr.list[arr.length - 1 - i];
        arr.list[arr.length - 1 - i] = temp;
    }
}


typedef struct array array;

int main(){
    array arr;
    cout << "enter the size of the array" << endl;
    cin >> arr.size;
    initialise(arr);
    int n;
    cout << "enter the number of elements to be added: ";
    cin >> n;
    cout << "enter all n elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr.list[i];
        arr.length++;
    }
    insert(arr, 5, 2);
    Display(arr);
    remove(arr, 2);
    Display(arr);
    cout << linear_search(arr, 3) << endl;
    cout << binary_search(arr, 0, arr.length - 1, 4) << endl;
    cout << get(arr, 2) << endl;
    return 0;
}