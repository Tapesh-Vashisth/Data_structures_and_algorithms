#include <iostream>
using namespace std;

class circular_queue{
    private:
        int front;
        int rear;
        int length;
        int * storage;
    public:
        circular_queue(){
            front = -1;
            rear = -1;
            length = 0;
            storage = NULL;
        }

        circular_queue(int len){
            length = len + 1;
            front = 0;
            rear = len;
            storage = new int[length + 1];
            cout << "enter the elements: ";
            for (int i = 1; i <= len; i++){
                int x;
                cin >> x;
                storage[i+1] = x;
            }
        }

        void enqueue(int value){
            if (isfull()){
                cout << "queue overflow!" << endl;
            }else{
                if (rear == length - 1){
                    storage[0] = value;
                    rear = 0;
                }else{
                    storage[++rear] = value;
                }
            }
        }

        int dequeue(){
            if (isempty()){
                cout << "queue is empty!" << endl;
            }else{
                if (front == length - 1){
                    front = 0;
                    return storage[1];
                }else{
                    int ans = front + 1;
                    front = front + 1;
                    return storage[ans];
                }
            }
        }

        void display(){
            if (rear < front){
                for (int i = front + 1; i < length; i++){
                    cout << storage[i] << " ";
                }

                for (int i = 0; i <= rear; i++){
                    cout << storage[i] << " ";
                }
                cout << endl;
            }else{
                for (int i = front; i <= rear; i++){
                    cout << storage[i] << " ";
                }
                cout << endl;
            }
        }
        

        int isempty(){
            if (front == rear){
                return 1;
            }else{
                return 0;
            }
        }

        int isfull(){
            if (rear - front == length - 1 || front - rear == 1){
                return 1;
            }else{
                return 0;
            }
        }
};


int main(){
    circular_queue list(4);
    cout << list.isfull() << endl;
    list.dequeue();
    list.dequeue();
    list.dequeue();
    list.dequeue();
    cout << list.isfull() << endl;
    cout << list.isempty() << endl;
    list.enqueue(15);
    // list.enqueue(20);
    // list.dequeue();
    // list.dequeue();
    // list.dequeue();
    // list.dequeue();
    // list.dequeue();
    return 0;
}