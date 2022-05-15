#include <iostream>
using namespace std;


int pow(int base, int exp){
    if (exp == 0){
        return 1;
    }else{
        return base * pow(base ,exp - 1);
    }
}

int better_pow(int base, int exp){
    if (exp == 0){
        return 1;
    }else{
        if (exp%2){
            return base * better_pow(base * base, exp/2);
        }else{
            return better_pow(base * base, exp/2);
        }
    }
}

int main(){
    cout << better_pow(2, 9);
    return 0;
}