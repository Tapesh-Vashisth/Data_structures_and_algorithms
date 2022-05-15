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

class circular_linked_list{
    private:
        node * head;
        int len;
    public:
        circular_linked_list(){
            head = NULL;
            len = 0;
        }

        circular_linked_list(int * A, int len){
            node * first = new node;
            head = first;
            first->setdata(A[0]);
            first->setnext(head);
            for (int i = 1; i < len; i++){
                node * p = new node;
                p->setdata(A[i]);
                p->setnext(head);
                first->setnext(p);
                first = p;
            }
        }

        node * gethead(){
            return head;
        }

        void display(){
            node * p = head;
            do{
                cout << p->getdata() << " ";
                p = p->getnext();
            }while(p != head);
            cout << endl;
        }

        void r_display(node * p){
            static int decider = 0;
            if (decider == 0 || p != head){
                decider = 1;
                cout << p->getdata() << " ";
                r_display(p->getnext());
            }else{
                decider = 0;
                cout << endl;
            }
        }

        void insert(int pos, int value){
            if (pos == 0){
                node * p = new node;
                p->setdata(value);
                if (head == NULL){
                    head = p;
                    p->setnext(head);
                }else{
                    p->setnext(head);
                    node * move = head;
                    do{
                        move = move->getnext();
                    }while(move->getnext() != head);

                    move->setnext(p);
                }
            }else if(pos > 0){
                node * p = new node;
                node * move = head;
                p->setdata(value);
                for (int i = 0; i < pos - 1; i++){
                    move = move->getnext();
                }
                p->setnext(move->getnext());
                move->setnext(p);
            }else{
                cout << "invalid index" << endl;
            }
        }

        int length(){
            int len = 0;
            node * p = head;
            do{
                p = p->getnext();
                len++;
            }while(p != head);

            return len;
        }

        void del(int pos){
            if(pos == 0){
                node * p = head;
                do{
                    p = p->getnext();
                }while(p->getnext() != head);
                p->setnext(head->getnext());
                p = head;
                head = head->getnext();
                delete p;
            }else{
                node * p = head;
                node * q = NULL;
                for (int i = 0; i < pos; i++){
                    q = p;
                    p = p->getnext();
                }

                q->setnext(p->getnext());
                delete p;
            }
        }

};

int main(){
    int A[] = {1, 2, 3, 4};
    circular_linked_list list(A, 4);
    list.insert(5, 3);
    list.r_display(list.gethead());
    list.del(0);
    list.r_display(list.gethead());
    cout << list.length() << endl;
    return 0;
}