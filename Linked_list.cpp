#include <iostream>
using namespace std;

class node{
    private:
        int data;
        node * next;
    
    public:
        void setdata(int value){
            data = value;
        }

        void setnext(node * dest){
            next = dest;
        }

        node * getnext(){
            return next;
        }

        int getdata(){
            return data;
        }
};

class linked_list{
    private:
        node * first, * last;
        int len;
    
    public:
        linked_list(){
            len = 0;
            first = NULL;
            last = first;
        }

        linked_list(int * A, int length){
            first = new node;
            first->setdata(A[0]);
            first->setnext(NULL);
            last = first;
            len++;
            for (int i = 1; i < length; i++){
                node * t = new node;
                t->setdata(A[i]);
                t->setnext(NULL);
                last->setnext(t);
                last = t;
                len++;
            }
        }

        node * getfirst(){
            return first;
        }


        int getlen(){
            return len;
        }

        void display(){
            node * iterator = first;
            while(iterator != NULL){
                cout << iterator->getdata() << " ";
                iterator = iterator->getnext();
            }
            cout << endl;
        }

        void rdisplay(node * p){
            if (p == NULL){
                cout << endl;
            }else{
                cout << p->getdata() << " ";
                rdisplay(p->getnext());
            }
        }

        int count(){
            int count = 0;
            node * p = first;
            while (p != NULL){
                count += 1;
                p = p->getnext();
            }
            return count;
        }

        int r_count(node * p){
            if (p == NULL){
                return 0;
            }else{
                return r_count(p->getnext()) + 1;
            }
        }

        int sum(){
            node * p = first;
            int add = 0;
            while (p != NULL){
                add += p->getdata();
                p = p->getnext();
            }
            return add;
        }

        int r_sum(node * p){
            if (p == NULL){
                return 0;
            }else{
                return r_sum(p->getnext()) + p->getdata();
            }
        }

        int max(){
            node * it = first;
            int max = first->getdata();
            while(it != NULL){
                if (it->getdata() > max){
                    max = it->getdata();
                }
                it = it->getnext();
            }

            return max;
        }

        int r_max(node * p){
            if (p == NULL){
                return 0;
            }else{
                int max = r_max(p->getnext());
                if (p->getdata() > max){
                    return p->getdata();
                }else{
                    return max;
                }
            }
        }

        node * linear_search(int value){
            node * p = first;
            while (p != NULL){
                if (p->getdata() == value){
                    return p;
                }
                p = p->getnext();
            }
            return NULL;
        }

        node * move_to_head_linear_search(int value){
            node * p = first;
            node * q = NULL;
            while (p != NULL){
                if (p->getdata() == value){
                    q->setnext(p->getnext());
                    p->setnext(first);
                    first = p;
                    return p;
                }else{
                    q = p;
                    p = p->getnext();
                }
            }
            
        }

        void insert(int pos, int value){
            if(pos <= 0){
                node * n = new node;
                n->setdata(value);
                n->setnext(first);
                first = n;
                len++;
            }else{
                node * p = first;
                for (int i = 0; i < pos - 1 && p; i++){
                    p = p->getnext();
                }
                if (p){
                    node * n = new node;
                    n->setdata(value);
                    n->setnext(p->getnext());
                    p->setnext(n);
                    len++;
                }
            }
        }


        void insertlast(int value){
            node * n = new node;
            n->setdata(value);
            n->setnext(NULL);
            if (first == NULL){
                last = n;
                first = last;
                len++;
            }else{
                last->setnext(n);
                last = n;
                len++;
            }
        }

        void insert_sorted(int value){
            node * n = new node;
            n->setdata(value);
            node * p = first; 
            node * q = first;
            if (first == NULL){
                n->setnext(NULL);
                first = n;
                last = n;
                len++;
            }else{
                if (p -> getdata() >= value){
                    n->setnext(p);
                    first = n;
                    len++;
                }else{
                    p = first->getnext();
                    q = first;
                    while(p != NULL && p->getdata() < value){
                        p = p->getnext();
                        q = q->getnext();
                    }
                    if (p == NULL){
                        len++;
                        n->setnext(NULL);
                        last = n;
                        q->setnext(n);
                    }else{
                        len++;
                        q->setnext(n);
                        n->setnext(p);
                    }
                }
            }
        }

        void del(int pos){
            if (first != NULL){
                if (pos <= 0){
                    node * pos;
                    pos = first->getnext();
                    delete first;
                    first = pos;
                    len--;
                }else if(pos < len){
                    node * p, * q;
                    p = first;
                    q = NULL;
                    for (int i = 0; i < pos; i++){
                        q = p;
                        p = p->getnext();
                    }
                    q->setnext(p->getnext());
                    delete p;
                    len--;
                }
            }
        }

        int check_sorted(){
            if (first != NULL){
                node * p;
                int x = first->getdata();
                p = first->getnext();
                while(p != NULL){
                    if (p->getdata() < x){
                        return 0;
                    }
                    p = p->getnext();
                }
                return 1;
            }else{
                return 0;
            }
        }

        void delete_dup_sorted(){
            if (first != NULL){
                int pos = 0;
                int x = first->getdata();
                node * p = first->getnext();
                pos++;
                while (p != NULL){
                    if (p->getdata() == x){
                        p = p->getnext();
                        del(pos);
                    }else{
                        x = p->getdata();
                        p = p->getnext();
                        pos++;
                    }
                }
            }
        }

        void reverse_by_elements(){
            int length = count();
            int * container = new int[length];
            node * p = first;
            int index = 0;
            while(p != NULL){
                container[length - index - 1] = p->getdata();
                index++;
                p = p->getnext();            
            }

            p = first;
            index = 0;
            while (p != NULL){
                p->setdata(container[index]);
                index++;
                p = p->getnext();
            }

            delete [] container;
        }

        void reverse_by_links(){
            node *p, *q, *r;
            r = NULL;
            q = NULL;
            p = first;
            while (p != NULL){
                r = q;
                q = p;
                p = p->getnext();
                q->setnext(r);
            }
            first = q;
        }

        void reverse_by_recursion(node * one, node * two){
            if (two == last){
                first = two;
                two->setnext(one);
            }else{
                reverse_by_recursion(two, two->getnext());
                if(one == NULL){
                    last = two;
                    two->setnext(one);
                }else{
                    two->setnext(one);
                }
            }
        }

        void concatenation(linked_list l2){
            node * p = first;
            while (p->getnext() != NULL){
                p = p->getnext();
            }
            p->setnext(l2.getfirst());
        }


        void merging(linked_list list){
            node * mer_last;
            node * mer_first;
            if (first->getdata() <= list.getfirst()->getdata()){
                mer_last = first;
                mer_first = first;
                first = first->getnext();
                mer_last->setnext(NULL);
            }else{
                mer_last = list.getfirst();
                mer_first = list.getfirst();
                list.first = list.first->getnext();
                mer_last->setnext(NULL);
            }
            while (first != NULL && list.getfirst() != NULL){
                if (first->getdata() <= list.getfirst()->getdata()){
                    mer_last->setnext(first);
                    mer_last = first;
                    first = first->getnext();
                    mer_last->setnext(NULL);
                }else{
                    mer_last->setnext(list.first);
                    mer_last = list.first;
                    list.first = list.first->getnext();
                    mer_last->setnext(NULL);
                }
            }
            node * p = first;
            while (p != NULL){
                mer_last->setnext(p);
                mer_last = p;
                p = p->getnext();
                mer_last->setnext(NULL);

            }
            p = list.first;
            while (p != NULL){
                mer_last->setnext(p);
                mer_last = p;
                p = p->getnext();
                mer_last->setnext(NULL);
            }

            first = mer_first;
        }

        int LOOP_or_not(){
            node * p;
            node * q;
            p, q = first;
            do{
                p = p->getnext();
                q = q->getnext();
                q = (q->getnext() == NULL? NULL : q->getnext());
            }while(p && q && p != q);

            if (p == q){
                return 1;
            }else{
                return 0;
            }
        }


        int max_trick(){
            node * fast = first;
            node * slow = first;

            while(fast != NULL){
                if (fast->getnext() == NULL){
                    break;
                }else{
                    fast = fast->getnext();
                }

                if (fast->getnext() == NULL){
                    break;
                }else{
                    fast = fast->getnext();
                }

                slow = slow->getnext();
            }

            return slow->getdata();
        }

        
};


int main(){
    int A[] = {1, 2, 3};
    linked_list list(A, 3);
    cout << list.max_trick() << endl;
    list.rdisplay(list.getfirst());
    // cout << list.r_count(list.getfirst()) << endl;
    // cout << list.r_sum(list.getfirst()) << endl;
    // cout << list.r_max(list.getfirst()) << endl;
    // cout << list.move_to_head_linear_search(5)->getdata() << endl;
    // list.insert(10, 11);
    // list.display();
    linked_list list2;
    list2.insert_sorted(1);
    list2.insert_sorted(1);
    list2.insert_sorted(2);
    list2.insert_sorted(2);
    list2.insert_sorted(2);
    list2.insertlast(3);
    list2.display();
    list.merging(list2);
    list.display();
    list2.reverse_by_recursion(NULL, list2.getfirst());
    // cout << list2.check_sorted() << endl;
    list2.display();
    list2.delete_dup_sorted();
    // cout << list2.getlen() << endl;
    // list2.display();
    // list2.display();
    return 0;
}