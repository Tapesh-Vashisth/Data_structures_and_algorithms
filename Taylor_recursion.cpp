#include <iostream>
using namespace std;

float taylor_r(int x, int n){
    static double fact = 1;
    static double power = 1;
    if (n == 0){
        return 1;
    }else{
        double r = taylor_r(x,n-1);
        power=power*x;
        fact=fact*n;
        return r + power / fact;
    }
}

float taylor_horner_r(int x, int n){
    static double s;
    if(n==0)
    return s;
    s=1+x*s/n;
    return taylor_horner_r(x,n-1);
}

int main(){
    cout << taylor_horner_r(3, 20);
    return 0;
}