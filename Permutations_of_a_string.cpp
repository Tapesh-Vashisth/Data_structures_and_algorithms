#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int fact(int n){
    int fa = 1;
    while(n > 0){
        fa *= n;
        n--;
    }
    return fa;
}

void rotate_right(string &s){
        char temp = s[s.length() - 1];
        for (int i = s.length() - 1; i > 0; i--){
            s[i] = s[i - 1];
        }
        s[0] = temp;
    }

void permutations(string s){
    int decider = 1;
    int times = fact(s.length());
    for (int i = 0; i < times/2; i++){
        cout << s << endl;
        reverse(s.begin(), s.end());
        cout << s << endl;
        reverse(s.begin(), s.end());
        rotate_right(s);
    }
}

int main(){
    permutations("ABC");

    return 0;
}