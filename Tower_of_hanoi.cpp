#include <iostream>
using namespace std;

void Tower_of_hanoi(int no_of_piles, string A, string B, string C){
    if (no_of_piles == 0){
        ;
    }else{
        Tower_of_hanoi(no_of_piles - 1, A, C, B);
        cout << A << " to " << C << endl;
        Tower_of_hanoi(no_of_piles - 1, B, A, C);
    }
}

int main(){
    Tower_of_hanoi(3, "A", "B", "C");
    return 0;
}