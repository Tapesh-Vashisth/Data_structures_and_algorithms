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

class circular_double_linked_list{
    private:
        node * head;
        int len;
    
    public:
        circular_double_linked_list(int * A, int length){
            node * f = new node;
            f->setdata(A[0]);           
            f->setnext(head);
            f->setprev(head);
            head = f;
            for (int i = 1; i < length; i++){
                node * n = new node;
                n->setdata(A[i]);
                n->setnext(head);
                n->setprev(f);
                f->setnext(n);
                f = n;
            }
            head->setprev(f);
            len = length;
        }


        void fdisplay(){
            node * p = head;
            do{
                cout << p->getdata() << " ";
                p = p->getnext();
            }while(p != head);
            cout << endl;
        }

        void bdisplay(){
            node * p = head;
            do{
                cout << p->getdata() << " ";
                p = p->getprev();
            }while(p != head);
            cout << endl;
        }

        void insert(int pos, int value){
            if (pos == 0){
                node * n = new node;
                n->setdata(value);
                n->setnext(head);
                head->setprev(n);
                node * p = head;
                do{
                    p = p->getnext();
                }while(p->getnext() != head);
                n->setprev(p);
                p->setnext(n);
            }else{
                node * n = new node;
                n->setdata(value);
                node * p = head;
                for (int i = 0; i < pos - 1; i++){
                    p = p->getnext();
                }
                n->setnext(p->getnext());
                n->setprev(p);
                p->getnext()->setprev(n);
                p->setnext(n);
            }
        }


        void del(int pos){
            if (pos == 0){
                node * p = head;
                do{
                     p = p->getnext();
                }while(p->getnext() != head);
                p->setnext(head->getnext());
                head->getnext()->setprev(p);
                delete head;
                head = p->getnext();
            }else{
                node * p = head;
                for (int i = 0; i < pos; i++){
                    p = p->getnext();
                }
                p->getprev()->setnext(p->getnext());
                p->getnext()->setprev(p->getprev());
            }
        }

        
};


int main(){
    int A[] = {1, 2, 3, 4};
    circular_double_linked_list list(A, 4);
    list.del(2);
    list.bdisplay();
    return 0;
}