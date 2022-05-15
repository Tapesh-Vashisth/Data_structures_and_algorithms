#include <iostream>
using namespace std;


class node{
    private:
        int data;
        node * next;
        node * prev;
    public:
        node(){
            data = 0;
            next = NULL;
            prev = NULL;
        }

        int getdata(){
            return data;
        }

        node * getnext(){
            return next;
        }

        node * getprev(){
            return prev;
        }

        void setdata(int value){
            data = value;
        }

        void setnext(node * n){
            next = n;
        }

        void setprev(node * p){
            prev = p;
        }
};

class dequeue{
    private:
        int length;
        node * front;
        node * rear;
    public:
        dequeue(){
            length = 0;
            front = NULL;
            rear = NULL;
        }

        dequeue(int len){
            length = len;
            cout << "enter the elements: ";
            int x;
            cin >> x;
            node * p = new node;
            p->setdata(x);
            p->setnext(NULL);
            p->setprev(NULL);
            front = p;
            rear = p;
            node * n = NULL;
            for (int i = 1; i < len; i++){
                cin >> x;
                n = new node;
                n->setdata(x);
                n->setprev(p);
                n->setnext(NULL);
                rear = n;
                p->setnext(n);
                p = n;
            }
        }

        void f_display(){
            node * p = front;
            while (p != NULL){
                cout << p->getdata() << " ";
                p = p->getnext();
            }
            cout << endl;
        }

        void b_display(){
            node * p = rear;
            while (p != NULL){
                cout << p->getdata() << " ";
                p = p->getprev();
            }
            cout << endl;
        }

        void b_enqueue(int value){
            node * n = new node;
            if (n == NULL){
                cout << "heap is full" << endl;
            }else{
                length++;
                n->setdata(value);
                n->setnext(NULL);
                if (front == NULL){
                    n->setprev(NULL);
                    front = n;
                    rear = n;
                }else{
                    rear->setnext(n);
                    n->setprev(rear);
                    rear = n;
                }
            }
        }

        void f_enqueue(int value){
            node * n = new node;
            if (n == NULL){
                cout << "heap is full" << endl;
            }else{
                length++;
                n->setdata(value);
                n->setprev(NULL);
                if (front == NULL){
                    n->setnext(NULL);
                    front = n;
                    rear = n;
                }else{
                    n->setnext(front);
                    front->setprev(n);
                    front = n;
                }
            }
        }

        int f_dequeue(){
            if (front == NULL){
                cout << "already empty" << endl;
            }else{
                if (front == rear){
                    node * p = front;
                    int ans = p->getdata();
                    front = NULL;
                    rear = NULL;
                    delete p;
                    return ans;
                }else{
                    node * p = front;
                    int ans = p->getdata();
                    front = front->getnext();
                    front->setprev(NULL);
                    delete p;
                    return ans;
                }
            }
        }

        int b_dequeue(){
            if (front == NULL){
                cout << "already empty" << endl;
            }else{
                if (front == rear){
                    node * p = rear;
                    int ans = p->getdata();
                    front = NULL;
                    rear = NULL;
                    delete p;
                    return ans;
                }else{
                    node * p = rear;
                    int ans = p->getdata();
                    rear = rear->getprev();
                    rear->setnext(NULL);
                    delete p;
                    return ans;
                }
            }
        }

        int getlength(){
            return length;
        }

        int isempty(){
            return front == NULL;
        }
};


int main(){
    dequeue list(3);
    cout << list.b_dequeue() << endl;
    list.f_dequeue();
    list.f_dequeue();
    list.f_dequeue();
    // list.b_dequeue();
    list.b_enqueue(5);
    list.f_enqueue(6);
    list.f_display();
    return 0;
}