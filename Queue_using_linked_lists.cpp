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


class queue{
    private:
        int length;
        node * front;
        node * rear;
    public:
        queue(){
            length = 0;
            front = NULL;
            rear = NULL;
        }

        queue(int len){
            length = len;
            cout << "enter the elements: ";
            int x;
            cin >> x;
            front = new node;
            front->setdata(x);
            front->setnext(NULL);
            rear = front;
            node * temp = front;
            node * n;
            for (int i = 1; i < len; i++){
                n = new node;
                cin >> x;
                n->setdata(x);
                n->setnext(NULL);
                temp->setnext(n);
                temp = n;
                rear = n;
            }
        }

        void enqueue(int value){
            node * n = new node;
            if (n == NULL){
                cout << "heap full" << endl;
            }else{
                if (front == NULL){
                    front = n;
                    front->setdata(value);
                    front->setnext(NULL);
                    rear = front;
                }else{
                    n->setdata(value);
                    n->setnext(NULL);
                    rear->setnext(n);
                    length++;
                }
            }
        }

        int dequeue(){
            if (isempty()){
                cout << "queue is empty!" << endl;
            }else{
                if (length == 1){
                    node * holder = front;
                    front = front->getnext();
                    length--;
                    rear = NULL;
                    int value = holder->getdata();
                    delete holder;
                    return value;
                }else{
                    node * holder = front;
                    front = front->getnext();
                    length--;
                    int value = holder->getdata();
                    delete holder;
                    return value;
                }
            }
        }

        void display(){
            node * p = front;
            while(p != NULL){
                cout << p->getdata() << " ";
                p = p->getnext();
            }
            cout << endl;
        }

        int isempty(){
            if (front == NULL){
                return 1;
            }else{
                return 0;
            }
        }

        int getlength(){
            return length;
        }
};


int main(){
    queue list(5);
    list.enqueue(5);
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    return 0;
}