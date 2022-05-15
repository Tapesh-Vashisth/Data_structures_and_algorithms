#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
    private:
        node * left;
        int data;
        node * right;

    public:
        node(){
            data = -1;
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

class instruct{
    private:
        int print;
        int left;
        int right;
        node * pointer;
    public:
        instruct(){
            print = 0;
            left = 0;
            right = 0;
            pointer = NULL;
        }

        int getprint(){
            return print;
        }

        int getleft(){
            return left;
        }

        int getright(){
            return right;
        }

        node * getpointer(){
            return pointer;
        }

        void setprint(){
            print = 1;
        }

        void setleft(){
            left = 1;
        }

        void setright(){
            right = 1;
        }

        void setpointer(node * n){
            pointer = n;
        }
};

class binary_tree{
    private:
        node * root;
    public:
        binary_tree(){
            int x;
            queue <node *> store;
            cout << "enter the value of the root element: ";
            cin >> x;
            node * p = new node;
            p->setdata(x);
            p->setleft(NULL);
            p->setright(NULL);
            root = p;
            store.push(p);
            while (!store.empty()){
                node * asker = store.front();
                store.pop();
                int x;
                cout << "enter left element (-1, if it doesnt exist)";
                cin >> x;
                if (x == -1){
                    asker->setleft(NULL);
                }else{
                    node * n = new node;
                    n->setdata(x);
                    n->setleft(NULL);
                    n->setright(NULL);
                    asker->setleft(n);
                    store.push(n);
                }

                cout << "enter right element (-1, if it doesnt exist)";
                cin >> x;
                if (x == -1){
                    asker->setright(NULL);
                }else{
                    node * n = new node;
                    n->setdata(x);
                    n->setleft(NULL);
                    n->setright(NULL);
                    asker->setright(n);
                    store.push(n);
                }
            }
        }

        node * getroot(){
            return root;
        }

        void preorder(node * p){
            if (p){
                cout << p->getdata() << " ";
                preorder(p->getleft());
                preorder(p->getright());
            }
        }

        void inorder(node * p){
            if (p){
                inorder(p->getleft());
                cout << p->getdata() << " ";
                inorder(p->getright());
            }
        }

        void postorder(node * p){
            if (p){
                postorder(p->getleft());
                postorder(p->getright());
                cout << p->getdata() << " ";
            }
        }

        void LevelOrder(){
            queue <node *> store;
            store.push(root);
            while (!store.empty()){
                node * n = store.front();
                store.pop();
                cout << n->getdata() << " ";
                if (n->getleft() != NULL){
                    store.push(n->getleft());
                }

                if (n->getright() != NULL){
                    store.push(n->getright());
                }

            }
        }

        int height(node * p){
            int x = 0;
            int first = 0, second = 0;
            if (p == NULL){
                return -1;
            }

            first = height(p->getleft());
            second = height(p->getright());

            if (first > second){
                return first + 1;
            }else{
                return second + 1;
            }
        }

        void preorder(){
            stack <node *> store;
            node * first;
            first = root;
            store.push(first);
            while (!store.empty()){
                node * p = store.top();
                store.pop();
                cout << p->getdata() << " ";

                if (p->getright() == NULL){
                    ;
                }else{
                    node * next;
                    next = p->getright();
                    store.push(next);
                }

                if (p->getleft() == NULL){
                    ;
                }else{
                    node * next;
                    next = p->getleft();
                    store.push(next);
                }
            }
            cout << endl;
        }

        void inorder(){
            stack <node *> store;
            node * first = root;
            store.push(first);
            node * p = first;
            while (!store.empty()){
                // cout << "hi" << endl;
                p = store.top();
                store.pop();
                if (p != NULL){
                    // cout << "hello" << endl;
                    store.push(p);
                    p = p->getleft();
                    store.push(p);
                }else{
                    // cout << "hi" << endl;
                    if (store.empty()){
                        ;
                    }else{
                        p = store.top();
                        store.pop();
                        cout << p->getdata() << " ";
                        store.push(p->getright());                    
                    }
                }   
            }
            cout << endl;
        }

        void postorder(){
            stack <instruct> store;
            instruct first;
            first.setpointer(root);
            store.push(first);
            while (!store.empty()){
                instruct p = store.top();
                store.pop();

                if (!p.getleft()){
                    // cout << p.getpointer()->getdata() << " ";
                    if (p.getpointer()->getleft() == NULL){
                        p.setleft();
                        store.push(p);
                    }else{
                        p.setleft();
                        store.push(p);
                        instruct q;
                        q.setpointer(p.getpointer()->getleft());
                        store.push(q);
                    }
                }else if(!p.getright()){
                    if (p.getpointer()->getright() == NULL){
                        p.setright();
                        store.push(p);
                    }else{
                        p.setright();
                        store.push(p);
                        instruct q;
                        q.setpointer(p.getpointer()->getright());
                        store.push(q);
                    }
                }else{
                    cout << p.getpointer()->getdata() << " ";
                    p.setprint();
                }
            }
            cout << endl;
        }

        int count(node * p){
            if (p){
                int x = count(p->getleft());
                int y = count(p->getright());
                return x + y + 1;
            }
            return 0;
        }
};


int main(){
    binary_tree first_tree;
    first_tree.preorder(first_tree.getroot());
    cout << endl;
    first_tree.inorder(first_tree.getroot());
    cout << endl;
    first_tree.postorder(first_tree.getroot());
    cout << endl;
    first_tree.LevelOrder();
    cout << endl;
    cout << first_tree.height(first_tree.getroot()) << endl;
    first_tree.preorder();
    first_tree.inorder();
    cout << "iterative postorder!" << endl;
    first_tree.postorder();

    cout << first_tree.count(first_tree.getroot()) << endl;
    return 0;
}