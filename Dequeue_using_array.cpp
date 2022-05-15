#include <iostream>
using namespace std;

class dequeue{
    private:
        int length;
        int front;
        int rear;
        int * list;
    public:
        dequeue(){
            length = 0;
            front = -1;
            rear = -1;
        }

        dequeue(int len){
            list = new int[len + 1];
            front = 0;
            rear = len;
            length = len + 1;
            int x;
            cout << "enter the elements: ";
            for (int i = 1; i < len + 1; i++){
                cin >> x;
                list[i] = x;
            }
        }

        void f_enqueue(int value){
            if (isfull()){
                cout << "queue is full!" << endl;
            }else{
                if (front == 0){
                    list[front] = value;
                    front = length - 1;
                }else{
                    list[front--] = value;
                }
            }
        }

        void b_enqueue(int value){
            if (isfull()){
                cout << "queue is full!" << endl;
            }else{
                if (rear == length - 1){
                    list[0] = value;
                    rear = 0;
                }else{
                    list[++rear] = value;
                }
            }
        }

        int f_dequeue(){
            if (isempty()){
                cout << "queue is already empty!" << endl;
            }else{
                if (front == length - 1){
                    front = 0;
                }else{
                    front++;
                }
            }
        }

        int b_dequeue(){
            if (isempty()){
                cout << "queue is already empty!" << endl;
            }else{
                if (rear == 0){
                    rear = length - 1;
                }else{
                    rear--;
                }
            }
        }

        int getlength(){
            return length - 1;
        }

        void display(){
            if (length <= 1){
                ;
            }else{
                if (front <= rear){
                    for (int i = front + 1; i <= rear; i++){
                        cout << list[i] << " ";
                    }
                    cout << endl;
                }else{
                    for (int i = front + 1; i < length; i++){
                        cout << list[i] << " ";
                    }

                    for (int i = 0; i <= rear; i++){
                        cout << list[i] << " ";
                    }
                    cout << endl;
                }
            }
        }

        int isfull(){
            if (front - rear == 1 || rear - front == length - 1){
                return 1;
            }else{
                return 0;
            }
        }

        int isempty(){
            if (front == rear){
                return 1;
            }else{
                return 0;
            }
        }
};



int main(){
    dequeue list(5);
    list.b_dequeue();
    cout << list.getlength() << endl;
    list.f_enqueue(6);
    list.b_dequeue();
    list.f_enqueue(7);
    list.b_dequeue();
    list.f_enqueue(8);
    cout << list.getlength() << endl;
    list.b_dequeue();
    list.display();
    return 0;
}


