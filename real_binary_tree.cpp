#include <iostream>
using namespace std;

class node{
    private:
        int data;
        node * left;
        node * right;
    public:
        node(){
            data = 0;
            left = NULL;
            right = NULL;
        }

        int getdata(){
            return data;
        }

        node * getleft(){
            return left;
        }

        node * getright(){
            return right;
        }

        void setdata(int value){
            data = value;
        }

        void setleft(node * l){
            left = l;
        }

        void setright(node * r){
            right = r;
        }
};

class real_binary_tree{
    private:
        node * root;

    public:
        real_binary_tree(){
            int x;
            char choice = 'y';
            int count = 0;
            while (choice == 'y'){
                cout << "enter the element: ";
                cin >> x;
                node * p = NULL;
                node * q = NULL;
                if (count == 0){
                    root = new node;
                    root->setdata(x);
                    count++;
                }else{
                    p = root;
                    int ldecider = 0;
                    int rdecider = 0;
                    while (p){
                        if (x == p->getdata()){
                            rdecider = 0;
                            ldecider = 0;
                            break;
                        }

                        q = p;
                        if (x > p->getdata()){
                            p = p->getleft();
                            ldecider = 1;
                        }else if(x < p->getdata()){
                            p = p->getright();
                            rdecider = 1;
                        }

                    }

                    if (ldecider){
                        node * n = new node;
                        n->setdata(x);
                        q->setleft(n);
                    }else if(rdecider){
                        node * n = new node;
                        n->setdata(x);
                        q->setright(n);
                    }else{
                        ;
                    }
                }
                cout << "do you want to enter more?(y/n)";
                cin >> choice;
            }
            
        }

        node * getroot(){
            return root;
        }

        node * insert(node * p, int value){
            if (p){
                if (p->getdata() == value){
                    return NULL;
                }else if (p->getdata() > value){
                    p->setright(insert(p->getright(), value)); 
                }else{
                    p->setleft(insert(p->getleft(), value));
                }
            }else{
                node * n = new node;
                n->setdata(value);
                return n;
            }
        }

        void inorder(node * p){
            if (p){
                inorder(p->getleft());
                cout << p->getdata() << " ";
                inorder(p->getright());
            }
        }
       
};


int main(){
    real_binary_tree tree;
    tree.inorder(tree.getroot()); 
    return 0;
}