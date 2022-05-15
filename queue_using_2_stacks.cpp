#include <iostream>
#include <stack>
using namespace std;

class queue{
    private:
        stack <int> inp;
        stack <int> out;
        int length;
    public:
        queue(){
            length = 0;
        }

        queue(int len){
            length = len;
            cout << "enter the elements: ";
            for (int i = 0; i < len; i++){
                int x;
                cin >> x;
                out.push(x);
            }
        }

        int dequeue(){
            if (isempty()){
                cout << "queue is already empty!" << endl;
            }else{
                if (out.empty()){
                    while(!inp.empty()){
                        out.push(inp.top());
                        inp.pop();
                    }
                    length--;
                    int value = out.top();
                    out.pop();
                    return value;
                }else{
                    length--;
                    int value = out.top();
                    out.pop();
                    return value;
                }
            }
        }

        void enqueue(int value){
            inp.push(value);
            length++;
        }

        int getlength(){
            return length;
        }

        int isempty(){
            if (inp.empty() && out.empty()){
                return 1;
            }else{
                return 0;
            }
        }
};


int main(){
    queue list(5);
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    cout << list.dequeue() << endl;
    list.enqueue(8);
    list.enqueue(8);
    list.enqueue(8);
    list.enqueue(8);
    cout << list.getlength() << endl;
    cout << list.dequeue() << endl;
    return 0;
}
