#include <iostream>
using namespace std;

class diagonal_matrix{
    private:
        int n;
        int * A;
    public:
        diagonal_matrix(){
            n = 0;
            A = new int[0];
        }

        diagonal_matrix(int n){
            this->n = n;
            A = new int[n];
        }

        void set(int i, int j, int value){
            if (i == j && i < n){
                A[i] = value;
            }else{
                cout << "invalid index!" << endl;
            }
        }

        int get(int i, int j){
            if (i == j){
                return A[i];
            }else{
                return 0;
            }
        }

        void display(){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i == j){
                        cout << A[i] << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }

        int getDimension(){
            return n;
        }

        ~diagonal_matrix(){
            delete [] A;
            cout << "destructed" << endl;
        }
};

class Rlower_trigonal_matrix{
    private:
        int n;
        int * A;
    public:
        Rlower_trigonal_matrix(){
            n = 0;
            A = new int[0];
        }

        Rlower_trigonal_matrix(int n){
            this->n = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int value){
            if (i >= j && i < n && j < n){
                A[(i*(i+1))/2 + j] = value;
            }else{
                ;
            }
        }

        int get(int i, int j){
            if (i >= j){
                return A[(i*(i+1))/2 + j];
            }else{
                return 0;
            }
        }

        void display(){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i >= j){
                        cout << A[(i*(i+1))/2 + j] << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }

        int getDimension(){
            return n;
        }

        ~Rlower_trigonal_matrix(){
            delete [] A;
            cout << "destructed" << endl;
        }
};

class Clower_trigonal_matrix{
    private:
        int n;
        int * A;
    public:
        Clower_trigonal_matrix(){
            n = 0;
            A = new int[0];
        }

        Clower_trigonal_matrix(int n){
            this->n = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int value){
            if (i >= j && i < n && j < n){
                A[n*j - (j*(j-1))/2 + (i - j)] = value;
            }else{
                ;
            }
        }

        int get(int i, int j){
            if (i >= j){
                return A[n*j - (j*(j-1))/2 + (i - j)];
            }else{
                return 0;
            }
        }

        void display(){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i >= j){
                        cout << A[n*j - (j*(j-1))/2 + (i - j)] << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }

        int getDimension(){
            return n;
        }

        ~Clower_trigonal_matrix(){
            delete [] A;
            cout << "destructed" << endl;
        }
};


class Rupper_trigonal_matrix{
    private:
        int n;
        int * A;
    
    public:
        Rupper_trigonal_matrix(){
            n = 0;
            A = new int[0];
        }

        Rupper_trigonal_matrix(int n){
            this->n = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int value){
            if (j >= i && i < n && j < n){
                A[n*i - (i*(i-1))/2 + (j - i)] = value;
            }
        }

        int get(int i, int j){
            if (j >= i){
                return A[n*i - (i*(i-1))/2 + (j - i)];
            }else{
                return 0;
            }
        }

        void display(){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (j >= i){
                        cout << A[n*i - (i*(i-1))/2 + (j - i)] << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }

        int getDimension(){
            return n;
        }

        ~Rupper_trigonal_matrix(){
            delete [] A;
            cout << "destructed" << endl;
        }
};

class Cupper_trigonal_matrix{
    private:
        int n;
        int * A;
    public:
        Cupper_trigonal_matrix(){
            n = 0;
            A = new int[0];
        }

        Cupper_trigonal_matrix(int n){
            this->n = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int value){
            if (j >= i && i < n && j < n){
                A[(j*(j+1))/2 + i] = value;
            }else{
                ;
            }
        }

        int get(int i, int j){
            if (j >= i){
                return A[(j*(j+1))/2 + i];
            }else{
                return 0;
            }
        }

        void display(){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (j >= i){
                        cout << A[(j*(j+1))/2 + i] << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }

        int getDimension(){
            return n;
        }

        ~Cupper_trigonal_matrix(){
            delete [] A;
            cout << "destructed" << endl;
        }
};

class symmetric{
    private:
        int n;
        int * A;
    public:
        symmetric(){
            n = 0;
            A = new int[0];
        }

        symmetric(int n){
            this->n = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int value){
            if (i >= j && i < n && j < n){
                A[(i*(i+1))/2 + j] = value;
            }else{
                ;
            }
        }

        int get(int i, int j){
            if (i >= j){
                return A[(i*(i+1))/2 + j];
            }else{
                return A[(j*(j+1))/2 + i];
            }
        }

        void display(){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (i >= j){
                        cout << A[(i*(i+1))/2 + j] << " ";
                    }else{
                        cout << A[(j*(j+1))/2 + i] << " ";
                    }
                }
                cout << endl;
            }
        }

        int getDimension(){
            return n;
        }

        ~symmetric(){
            delete [] A;
            cout << "destructed" << endl;
        }   
};

int main(){
    Cupper_trigonal_matrix matrix(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0 ; j < 4; j++){
            int x;
            cin >> x;
            matrix.set(i, j, x); 
        }
    }
    cout << matrix.get(2, 3) << endl;
    matrix.display();

    return 0;
}