#include <iostream>
#include <stdio.h>
#include <map>
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


int evaluate(string equation){
    stack engine;
    for (int i = 0; i < equation.length(); i++){
        if (equation[i] != '*' && equation[i] != '-' && equation[i] != '+' && equation[i] != '/'){
            engine.push(equation[i] - '0');
        }else{
            if (!engine.isempty()){
                int first = engine.pop();
                int second = engine.pop();
                char op = equation[i];
                int ans;
                switch (op){
                    case '*':
                        ans = first*second;
                        break;
                    case '/':
                        ans = first/second;
                        break;
                    case '+':
                        ans = first + second;
                        break;
                    case '-':
                        ans = first - second;
                        break;
                    default:
                        cout << "invalid operator" << endl;
                        break;
                }             
                engine.push(ans);
            }
        }
    }

    return engine.pop();
}

int main(){
    map <char, int> order;
    order.insert({'*', 2});
    order.insert({'/', 2});
    order.insert({'+', 1});
    order.insert({'-', 1});
    for (int i = 0; i < 25; i++){
        order.insert({'a' + i, 3});
    }
    for (int i = 0; i < 10; i++){
        order.insert({'0' + i, 3});
    }
    string expression;
    stack store;
    int len;
    cout << "enter the length: ";
    cin >> len;
    string infix;
    int index = 0;
    for (int i = 0; i < len; i++){
        char x;
        cin >> x;
        if (store.isempty()){
            // cout << "hi" << endl;
            store.push(x);
        }else{
            if (order[store.stacktop()] >= order[x]){
                while(!store.isempty() && order[store.stacktop()] >= order[x]){
                    char x = store.pop();
                    printf("%c", x);
                    infix.insert(infix.end(), x);
                }
                store.push(x);
            }else{
                store.push(x);
            }
        }
    }

    while (!store.isempty()){
        char x = store.pop();
        printf("%c", x);
        infix.insert(infix.end(), x);
    }

    cout << endl;

    // cout << "hi" << endl;
    cout << "value of the expression: " << evaluate(infix) << endl;
    return 0;
}