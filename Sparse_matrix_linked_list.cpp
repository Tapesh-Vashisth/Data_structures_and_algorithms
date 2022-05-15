#include <iostream>
using namespace std;

class row{
    private:
        int data;
        int column;
        row * next;
    
    public:
        row(){
            data = 0;
            column = 0;
            next = NULL;
        }

        int getdata(){
            return data;
        }

        int getcolumn(){
            return column;
        }

        row * getnext(){
            return next;
        }

        void setdata(int value){
            data = value;
        }

        void setcolumn(int value){
            column = value;
        }

        void setnext(row * n){
            next = n;
        }
};

class sparse{
    private:
        row * rows;
        int no_of_rows;
        int no_of_columns;
        int len;

    public:
        sparse(){
            rows = NULL;
            no_of_rows = 0;
        }

        sparse(int nrow, int ncolumn){
            no_of_rows = nrow;
            no_of_columns = ncolumn;
            rows = new row[nrow];
            int total;
            cout << "enter the number of non-zero elements: ";
            cin >> total;
            len = total;
            int prev = 0;
            int index = 0;
            int c, r, value;
            cout << "enter the column number: ";
            cin >> c;
            cout << "enter the row number: ";
            cin >> r;
            cout << "enter the value: ";
            cin >> value;
            row * previous;
            rows[index].setdata(value);
            rows[index].setnext(NULL);
            rows[index].setcolumn(c);
            previous = &rows[index];
            for (int i = 0; i < total - 1; i++){
                cout << "enter the column number: ";
                cin >> c;
                cout << "enter the row number: ";
                cin >> r;
                cout << "enter the value: ";
                cin >> value;
                if (r == prev){
                    row * n = new row;
                    n->setdata(value);
                    n->setcolumn(c);
                    n->setnext(NULL);
                    previous->setnext(n);
                    previous = n;
                }else{
                    index++;
                    rows[index].setdata(value);
                    rows[index].setnext(NULL);
                    rows[index].setcolumn(c);
                    previous = &rows[index];
                }
                prev = r;
            }
        }

        void display(){
            for (int i = 0; i < no_of_rows; i++){
                row * p = &rows[i];
                for (int j = 0; j < no_of_columns; j++){
                    if (p && p->getcolumn() == j){
                        cout << p->getdata() << " ";
                        p = p->getnext();
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }


};


int main(){
    sparse s(4, 3);
    s.display();
    return 0;
}