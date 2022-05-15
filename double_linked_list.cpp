#include <iostream>
#include <math.h>
using namespace std;

class node{
    private:
        node * next;
        int data;
        node * prev;
    
    public:
        node(){
            next = NULL;
            prev = NULL;
            data = 0;
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

class double_linked_list{
    private:
        int len;
        node * first;
        node * last;
    public:
        double_linked_list(int * A, int length){
            node * f = new node;
            len = length;
            f->setdata(A[0]);
            f->setprev(NULL);
            f->setnext(NULL);
            first = f;
            last  = first;
            node * p;
            for (int i = 1; i < length; i++){
                 p = new node;
                 p->setdata(A[i]);
                 p->setnext(NULL);
                 p->setprev(f);
                 last = p;
                 f->setnext(p);
                 f = p;
            }
        }

        int getlength(){
            return len;
        }

        void fdisplay(){
            node * p = first;
            while (p != NULL){
                cout << p->getdata() << " ";
                p = p->getnext();
            }
            cout << endl;
        }

        void bdisplay(){
            node * p = last;
            while (p != NULL){
                cout << p->getdata() << " ";
                p = p->getprev(); 
            }
            cout << endl;
        }

        int length(){
            node * p = first;
            int count = 0;
            while(p != NULL){
                count++;
                p = p->getnext();
            }
            return count;
        }

        void insert(int pos, int value){
            if(pos <= len){
                int decider = ceil(len/2.0);
                node * n = new node;
                n->setdata(value);
                if (pos <= decider){
                    if (pos == 0){
                        n->setprev(NULL);
                        n->setnext(first); 
                        first->setprev(n);
                        first = n;
                        len++;
                    }else{
                        node * p = first;
                        for (int i = 0; i < pos-1; i++){
                            p = p->getnext();
                        }
                        n->setprev(p);
                        n->setnext(p->getnext());
                        p->getnext()->setprev(n);
                        p->setnext(n);
                        len++;
                    }
                }else{
                    if (pos == len){
                        node * p = last;
                        n->setprev(p);
                        n->setnext(NULL);
                        p->setnext(n);
                        last = n;
                        len++;
                    }else{
                        node * p = last;
                        int updated = len - pos;
                        for (int i = 0; i < updated -1; i++){
                            p = p->getprev();
                        }
                        n->setnext(p);
                        n->setprev(p->getprev());
                        p->getprev()->setnext(n);
                        p->setprev(n);
                        len++;
                    }
                }
            }
        }

        void del(int pos){
            int decider = len/2;
            if (pos < decider){
                if (pos == 0){
                    node * n = first;
                    first = first->getnext();
                    first->setprev(NULL);
                    delete n;
                    len--;
                }else{
                    node * p = first;
                    for (int i = 0; i < pos; i++){
                        p = p->getnext();
                    }
                    p->getprev()->setnext(p->getnext());
                    p->getnext()->setprev(p->getprev());
                    delete p;
                    len--;
                }
            }else{
                if (pos == len - 1){
                    node * n = last;
                    last = last->getprev();
                    last->setnext(NULL);
                    delete n;
                    len--;
                }else{
                    node * p = last;
                    int updated = len - pos - 1;
                    for (int i = 0; i < updated; i++){
                        p = p->getprev();
                    }
                    p->getprev()->setnext(p->getnext());
                    p->getnext()->setprev(p->getprev());
                    delete p;
                    len--;
                }
            }
        }

        void reverse(){
            node * p = first;
            node * q = first->getnext();
            last = first;
            while(q != NULL){
                p->setnext(p->getprev());
                p->setprev(q);
                p = q;
                q = q->getnext();
            }
            p->setnext(p->getprev());
            p->setprev(q);
            first = p;
        }

        

};

int main(){
    int A[] = {1, 2, 3, 4};
    double_linked_list list(A, 4);
    list.insert(4, -1);
    list.fdisplay();
    list.del(1);
    list.fdisplay();
    list.reverse();
    list.fdisplay();
    cout << list.getlength() << endl;
    return 0;
}