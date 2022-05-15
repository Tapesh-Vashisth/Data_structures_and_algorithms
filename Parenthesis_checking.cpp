#include <iostream>
using namespace std;

class node{
    private:
        int data;
        node * next;
    public:
        node(){
            data = 0;
            next = NULL;
        }

        int getdata(){
            return data;
        }

        node * getnext(){
            return next;
        }

        void setdata(int value){
            data = value;
        }

        void setnext(node * n){
            next = n;
        }
};

class stack{
    private:
        int top;
        node * t;
        int length;
    public:
        stack(){
            top = -1;
            t = NULL;
        }

        stack(int len){
            length = len;
            top = len - 1;
            cout << "enter the elements: ";
            node * f = new node;
            int x;
            cin >> x;
            f->setdata(x);
            f->setnext(NULL);
            for (int i = 1; i < len; i++){
                node * n = new node;
                cin >> x;
                n->setdata(x);
                n->setnext(f);
                f = n;
            }
            t = f;
        }

        void push(int value){
            if (top < length - 1){
                node * n = new node;
                n->setdata(value);
                n->setnext(t);
                t = n;
                top++;
            }else{
                cout << "stack overflow" << endl;
            }
        }

        int pop(){
            if (top == -1){
                cout << "stack is empty!" << endl;
            }else{
                node * holder = t;
                int ans = t->getdata();
                t = t->getnext();
                top--;
                delete holder;
                return ans;
            }
        }

        int peek(int pos){
            if (pos > 0 && pos <= top + 1){
                node * p = t;
                for (int i = 0; i < pos - 1; i++){
                    p = p->getnext();
                }
                return p->getdata();
            }else{
                cout << "invalid index" << endl;
            }
        }

        int stacktop(){
            if (top != -1){
                return t->getdata();
            }else{
                cout << "empty stack" << endl;
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
    stack imp;
    string s;
    cout << "enter the sentence: ";
    cin >> s;
    int decider = 0;
    if (s[0] == '[' || s[0] == ']' || s[0] == '{' || s[0] == '}' || s[0] == '(' || s[0] == ')'){
        imp.push(s[0]);
    }
    for (int i = 1; i < s.length(); i++){
        if (s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' || s[i] == '(' || s[i] == ')'){
            if (imp.isempty()){
                imp.push(s[i]);
            }else{
                if (imp.stacktop() == '{' && s[i] == '}' || imp.stacktop() == '[' && s[i] == ']' || imp.stacktop() == '(' && s[i] == ')'){
                    imp.pop();
                }else{
                    imp.push(s[i]);
                }
            }
        }else{
            ;
        }
    }

    if (imp.isempty()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}