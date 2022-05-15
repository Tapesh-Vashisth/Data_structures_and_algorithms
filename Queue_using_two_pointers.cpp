#include <iostream>
using namespace std;

class Queue{
    private:
        int length;
        int front;
        int rear;
        int * storage;

    public:
        Queue(){
            length = 0;
            front = -1;
            rear = -1;
            storage = NULL;
        }

        Queue(int len){
            length = len;
            front = 0;
            rear = len - 1;
            storage = new int[len];
            cout << "enter the elements: ";
            for (int i = 0; i < len; i++){
                int x;
                cin >> x;
                storage[i] = x;
            }
        }

        int dequeue(){
            if (isempty()){
                cout << "Queue is empty!" << endl;
            }else{
                int value = storage[front];
                front = front + 1;
                return value;
            }
        }

        void enqueue(int value){
            if (isfull()){
                cout << "queue overflow!" << endl;
            }else{
                storage[++rear] = value;
            }
        }

        void display(){
            for (int i = front; i <= rear; i++){
                cout << storage[i] << " ";
            }
            cout << endl;
        }

        int isempty(){
            if (front > rear){
                return 1;
            }else{
                return 0;
            }
        }

        int isfull(){
            if (rear == length - 1){
                return 1;
            }else{
                return 0;
            }
        }
};

int main(){
    Queue list(5);
    cout << list.isfull() << endl;
    list.display();
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.isempty() << endl;
    list.enqueue(3);
    list.enqueue(2);
    cout << list.dequeue() << endl;
    return 0;
}