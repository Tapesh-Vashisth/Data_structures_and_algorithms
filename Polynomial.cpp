#include <iostream>
using namespace std;

class individual_term{
    private:
        int coefficient;
        int degree;
    public:
        int getcoef(){
            return coefficient;
        }
        int getdegree(){
            return degree;
        }

        void setcoef(int value){
            coefficient = value;
        }


        void setdegree(int value){
            degree = value;
        }
};

class polynomial{
    private:
        int degree;
        individual_term * equation;
    
    public:

        polynomial(int degree){
            this->degree = degree;
            equation = new individual_term[degree + 1];
        }

        void create(){
            for (int i = degree; i >= 0; i--){
                int x;
                cout << "enter the coefficient of degree " << i <<  " :";
                cin >> x;
                equation[degree - i].setdegree(i);
                equation[degree - i].setcoef(x); 
            }
        }

        friend polynomial add(polynomial p1, polynomial p2){
            int first = 0;
            int second = 0;
            int insert = 0;
            int deg;
            if (p1.degree >= p2.degree){
                deg = p1.degree;
            }else{
                deg = p2.degree;
            }

            polynomial sum(deg);
            while (first <= p1.degree && second <= p2.degree){
                if (p1.equation[first].getdegree() > p2.equation[second].getdegree()){
                    sum.equation[insert].setcoef(p1.equation[first].getcoef());
                    sum.equation[insert].setdegree(insert);
                    first++;
                    insert++;
                }else if(p1.equation[first].getdegree() < p2.equation[second].getdegree()){
                    sum.equation[insert].setcoef(p2.equation[second].getcoef());
                    sum.equation[insert].setdegree(insert);
                    second++;
                    insert++;
                }else{
                    sum.equation[insert].setcoef(p2.equation[second].getcoef() + p1.equation[first].getcoef());
                    sum.equation[insert].setdegree(insert);
                    first++;
                    second++;
                    insert++;
                }
            }

            for (;first <= p1.degree; first++){
                sum.equation[insert].setcoef(p1.equation[first].getcoef());
                sum.equation[insert].setdegree(insert);
                insert++;
            }
            for (;second <= p2.degree; second++){
                sum.equation[insert].setcoef(p1.equation[second].getcoef());
                sum.equation[insert].setdegree(insert);
                insert++;
            }
            return sum;
        }

        void display(){
            for (int i = 0; i <= degree; i++){
                cout << equation[i].getdegree() << " " << equation[i].getcoef() << endl;
             }
        }
};

int main(){
    int deg;
    cin >> deg;
    polynomial eq1(deg);
    eq1.create();
    eq1.display();
    polynomial eq2(deg);
    eq2.create();
    eq2.display();
    cout << "sum:" << endl;
    polynomial sum = add(eq1, eq2);
    sum.display();
    return 0;
}