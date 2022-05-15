#include <iostream>
using namespace std;

class rectangle{
    private:
        int length;
        int breadth;

    public:
        rectangle(){
            length = 0;
            breadth = 0;
        }

        rectangle(int len, int bre){
            length = len;
            breadth = bre;
        }

        int getlength() const{
            return length;
        }

        int getbreadth() const{
            return breadth;
        }

        const rectangle operator =(rectangle r){
            length = r.length;
            breadth = r.breadth;
            return *this;
        }

        friend ostream & operator << (ostream & o, rectangle & r);
};

ostream & operator << (ostream & o, rectangle & r){
    o << "breadth: " << r.getbreadth() << " length: " << r.getlength();
    return o;
}




int islessthanarea(const rectangle & first, const rectangle & second){
    int firsta = first.getlength() * first.getbreadth();
    int seconda = second.getlength() * second.getbreadth();
    if (firsta >= seconda){
        return 0;
    }else{
        return 1;
    }
}

int islessthanperi(const rectangle & first, const rectangle & second){
    int firsta = 2*(first.getlength() + first.getbreadth());
    int seconda = 2*(second.getlength() + second.getbreadth());
    if (firsta >= seconda){
        return 0;
    }else{
        return 1;
    }
}


template <typename Object>
const Object findMax(const Object * list, int length,  int (*islessthan)(const Object & first, const Object & second)){
    Object & max = const_cast <Object &>(list[0]);
    for (int i = 1; i < length; i++){
        if (islessthan(max, list[i])){
            max = list[i];
        }
    }

    return max;
}


int main(){
    rectangle list[5] = {{1,2}, {1,1}, {3,1}, {4,1}, {2,2}};
    rectangle max = findMax <rectangle> (list, 5, islessthanperi);
    cout << max << endl;
    return 0;
}