#include <iostream>
using namespace std;

int upperBits(int n) {
    return ((!(!(n))<<31)>>31)&((-1) << (32 + (~n+1)));
}

int sign(int x) {
    return  ((x&-2147483648)>>31) | (!(!(x << 1)));
}

int getByte(int x, int n) {
  return 255<<(8*n);
}

int main(){
    int x;
    cin >> x;
    cout <<  endl;
    return 0;
}