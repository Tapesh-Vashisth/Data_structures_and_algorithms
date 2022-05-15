#include <iostream>
using namespace std;

class queue{
    private:
        int length;
        int rear;
        int * storage;
    public:
        queue(){
            length = 0;
            rear = -1;
            storage = NULL;
        }

        queue(int len){
            length = len;
            rear = -1;
            storage = new int[len];
            cout << "enter the elements: ";
            int x;
            for (int i = 0; i < len; i++){
                cin >> x;
                storage[++rear] = x;
            }
        }

        void enqueue(int value){
            if (isfull()){
                cout << "queue overflow!" << endl;
            }else{
                storage[++rear] = value;
                length++;
            }
        }

        int dequeue(){
            if (isempty()){
                cout << "queue empty!" << endl;
            }else{
                int ans = storage[0];
                for (int i = 1; i < length; i++){
                    storage[i-1] = storage[i];
                }
                rear--;
                return ans;
            }
        }

        void display(){
            for (int i = 0; i <= rear; i++){
                cout << storage[i] << " ";
            }
            cout << endl;
        }

        int isempty(){
            if (rear == -1){
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
    queue list(5);
    cout << list.isfull() << endl;
    list.display();
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