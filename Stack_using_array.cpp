#include <iostream>
using namespace std;

class stack{
    private:
        int length;
        int * s;
        int top;
    
    public:
        stack(){
            length = 0;
            s = NULL;
            top = -1;
        }

        stack(int depth){
            length = depth;
            s = new int[depth];
            top = depth - 1;
            cout << "enter the elements: "; 
            for (int i = 0; i < depth; i++){
                int x;
                cin >> x;
                s[i] = x;
            }
        }

        void push(int value){
            if (top < length - 1){
                s[++top] = value;
            }else{
                cout << "stack overflow" << endl;
            }
        }

        int pop(){
            if (top == -1){
                cout << "stack is empty!" << endl;
            }else{
                return s[top--];
            }
        }

        int peek(int pos){
            if (pos > 0 && pos <= top + 1){
                int index = top + 1 - pos;
                return s[index];
            }else{
                cout << "invalid index" << endl;
            }
        }

        int stacktop(){
            if (top != -1){
                return s[top];
            }else{
                return -1;
            }
        }

        int isempty(){
            if (top == -1){
                return 1;
            }else{
                return 0;
            }
        }

        int isfull(){
            if (top == length - 1){
                return 1;
            }else{
                return 0;
            }
        }
};

int main(){
    stack s(5);
    cout << s.stacktop() << endl;
    s.push(6);
    cout << s.peek(5) << endl;
    s.pop();
    
    cout << s.stacktop() << endl;
    cout << s.isfull() << endl;
    cout << s.stacktop() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.isempty() << endl;
    s.pop();
    return 0;
}