#include <iostream>
using namespace std;

class element{
    private:
        int row_no;
        int col_no;
        int value;
    public:
        element(){
            row_no = 0;
            col_no = 0;
            value = 0;
        }
        element(int row, int col, int value){
            row_no = row;
            col_no = col;
            this->value = value;
        }

        int getrow(){
            return row_no;
        }

        int getcol(){
            return col_no;
        }

        int getvalue(){
            return value;
        }

        void setrow(int x){
            row_no = x;
        }

        void setcol(int x){
            col_no = x;
        }

        void setvalue(int x){
            value = x;
        }
};

class three_col_sparse{
    private:
        int no_of_rows;
        int no_of_columns;
        int non_zeroes_values;
        element * elements;
    public:
        three_col_sparse(int rows, int columns){
            no_of_rows = rows;
            no_of_columns = columns;
        }

        three_col_sparse(int rows, int columns, int non_zeroes_value){
            no_of_rows = rows;
            no_of_columns = columns;
            this->non_zeroes_values = non_zeroes_value;
            elements = new element[non_zeroes_value];
            cout << "enter the elements: " << endl;
            for (int i = 0; i < non_zeroes_value; i++){
                int r;
                int c;
                int v;
                cout << "enter the row number of the element: ";
                cin >> r;
                cout << "enter the column number of the element: ";
                cin >> c;
                cout << "enter the value of the element: ";
                cin >> v;
                elements[i].setrow(r);
                elements[i].setcol(c);
                elements[i].setvalue(v);
            }
        }

        void Display(){
            int k = 0;
            for (int i = 0; i < no_of_rows; i++){
                for (int j = 0; j < no_of_columns; j++){
                    if (elements[k].getcol() == j && elements[k].getrow() == i){
                        cout << elements[k].getvalue() << " ";
                        k++;
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }

        friend three_col_sparse add(three_col_sparse addme1, three_col_sparse addme2){
            if (addme1.no_of_rows != addme2.no_of_rows || addme1.no_of_columns != addme2.no_of_columns){
                cout << "can't be added" << endl;
            }else{
                int first = 0;
                int second = 0;
                int insert = 0;
                three_col_sparse result(addme1.no_of_rows, addme1.no_of_columns);
                result.elements = new element[addme1.non_zeroes_values + addme2.non_zeroes_values];
                while (first < addme1.non_zeroes_values && second < addme2.non_zeroes_values){
                    if (addme1.elements[first].getrow() < addme2.elements[second].getrow()){
                        result.elements[insert].setrow(addme1.elements[first].getrow());
                        result.elements[insert].setcol(addme1.elements[first].getcol());
                        result.elements[insert].setvalue(addme1.elements[first].getvalue());
                        first++;
                        insert++;
                    }else if(addme1.elements[first].getrow() > addme2.elements[second].getrow()){
                        result.elements[insert].setrow(addme2.elements[second].getrow());
                        result.elements[insert].setcol(addme2.elements[second].getcol());
                        result.elements[insert].setvalue(addme2.elements[second].getvalue());
                        second++;
                        insert++;
                    }else{
                        if (addme1.elements[first].getcol() < addme2.elements[second].getcol()){
                            result.elements[insert].setrow(addme1.elements[first].getrow());
                            result.elements[insert].setcol(addme1.elements[first].getcol());
                            result.elements[insert].setvalue(addme1.elements[first].getvalue());
                            first++;
                            insert++;

                        }else if(addme1.elements[first].getcol() > addme2.elements[second].getcol()){
                            result.elements[insert].setrow(addme2.elements[second].getrow());
                            result.elements[insert].setcol(addme2.elements[second].getcol());
                            result.elements[insert].setvalue(addme2.elements[second].getvalue());
                            second++;
                            insert++;
                        }else{
                            result.elements[insert].setrow(addme2.elements[second].getrow());
                            result.elements[insert].setcol(addme2.elements[second].getcol());
                            result.elements[insert].setvalue(addme1.elements[insert].getvalue() + addme2.elements[insert].getvalue());
                            first++;
                            second++;
                            insert++;
                        }
                    }
                }

                if (first < addme1.non_zeroes_values){
                    while(first < addme1.non_zeroes_values){
                        result.elements[insert].setrow(addme1.elements[first].getrow());
                        result.elements[insert].setcol(addme1.elements[first].getcol());
                        result.elements[insert].setvalue(addme1.elements[first].getvalue());
                        first++;
                        insert++;
                    }
                }else if(second < addme2.non_zeroes_values){
                        result.elements[insert].setrow(addme2.elements[second].getrow());
                        result.elements[insert].setcol(addme2.elements[second].getcol());
                        result.elements[insert].setvalue(addme2.elements[second].getvalue());
                        second++;
                        insert++;
                }else{
                    ;
                }
                result.non_zeroes_values = insert;
                return result;
            }
        }
};

int main(){
    int row;
    int col;
    int non_zeroes;
    cin >> row >> col >> non_zeroes;
    three_col_sparse sparse1(row, col, non_zeroes);
    sparse1.Display();
    cin >> row >> col >> non_zeroes;
    three_col_sparse sparse2(row, col, non_zeroes);
    sparse2.Display();
    cout << "sum:" << endl;
    three_col_sparse result = add(sparse1, sparse2);
    result.Display();
    return 0;
}