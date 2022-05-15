#include <iostream>
#include <math.h>
using namespace std;

class term{
    private:
        int coef;
        int deg;
        term * next;
    public:
        term(){
            coef = 0;
            deg = 0;
            next = NULL;
        }

        int getcoef(){
            return coef;
        }

        int getdeg(){
            return deg;
        }

        term * getnext(){
            return next;
        }

        void setcoef(int value){
            coef = value;
        }

        void setdeg(int value){
            deg = value;
        }

        void setnext(term * n){
            next = n;
        }
};

class polynomial{
    private:
        int no_of_terms;
        term * first;

    public:
        polynomial(){
            no_of_terms = 0;
            first = NULL;
        }

        polynomial(int elements){
            no_of_terms = elements;
            term * t = new term;
            int coef, deg;
            cout << "enter the 1st coefficient: ";
            cin >> coef;
            cout << "enter the 1st degree: ";
            cin >> deg;
            first = t;
            t->setcoef(coef);
            t->setdeg(deg);
            t->setnext(NULL);
            for (int i = 1; i < elements; i++){
                term * n = new term;
                cout << "enter the " << (i+1) << "coefficient: ";
                cin >> coef;
                cout << "enter the " << (i+1) << "degree: ";
                cin >> deg;
                n->setcoef(coef);
                n->setdeg(deg);
                n->setnext(NULL);
                t->setnext(n);
                t = n;
            }
        }

        void display(){
            term * p = first;
            while (p != NULL){
                cout << p->getcoef() << "x" << p->getdeg() << " + ";
                p = p->getnext();
            }
            cout << endl;
        }

        float eval(int x){
            term * p = first;
            int ans = 0;
            while(p != NULL){
                ans += p->getcoef() * pow(x, p->getdeg());
                p = p->getnext();
            }
        }
};


int main(){
    polynomial equation(3);
    equation.display();
    return 0;
}