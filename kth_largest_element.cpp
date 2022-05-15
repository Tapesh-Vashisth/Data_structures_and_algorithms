#include <iostream>
using namespace std;

int klargest(int * list, int length, int k){
    for (int i = 1; i < k; i++){
        int j = i;
        while(j >= 1 && list[j] > list[j - 1]){
            list[j] = list[j] ^ list[j - 1];
            list[j-1] = list[j] ^ list[j - 1];
            list[j] = list[j] ^ list[j - 1];
            j--;
        }
    }

    for (int i = 0; i < length; i++){
        cout << list[i] << " ";
    }
    cout << endl;

    for (int i = k; i < length; i++){
        if (list[i] > list[k - 1]){
            list[i] = list[i] ^ list[k-1];
            list[k-1] = list[i] ^ list[k-1];
            list[i] = list[i] ^ list[k-1];
            int j = k-1;
            while(j >= 1 && list[j] > list[j-1]){
                list[j] = list[j] ^ list[j - 1];
                list[j-1] = list[j] ^ list[j - 1];
                list[j] = list[j] ^ list[j - 1];
                j--;
            }
        }else{
            ;
        }
    }

    return list[k-1];
}

int main(){
    int list[5] = {2, 1, 4, 7, 3};
    cout << klargest(list, 5, 4) << endl;
    return 0;
}