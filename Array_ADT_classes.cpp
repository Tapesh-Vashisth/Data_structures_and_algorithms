#include <iostream>
using namespace std;

class array{
    private:
        int * list;
        int len;
        int size;
    public:
        array(){
            len = 0;
            size = 0;
        }

        array(int size){
            list = new int[size];
            this->size = size;
            len = 0;
        }

        int get_length(){
            return len;
        }

        int get_size(){
            return size;
        }

        void set_elements(int n){
            if (n <= size){
                cout << "enter all the " << n << " elements: " << endl;
                for (int i = 0; i < n; i++){
                    cin >> list[i];
                    len++;
                }
            }else{
                cout << "storage not enough in the array!" << endl;
            }
        }

        void display(){
            for (int i = 0; i < len; i++){
                cout << list[i] << " ";
            }
            cout << endl;
        }

        void append(int x){
            if (len == size){
                cout << "list is already full" << endl;
            }else{
                list[len] = x;
                len++;
            }
        }

        void insert(int x, int index){
            if (len >= size || index > len || index < 0){
                cout << "space not enough for inserting!" << endl;
            }else{
                int temp = x;
                for (int i = index; i < len + 1; i++){
                    int holder = list[i];
                    list[i] = temp;
                    temp = holder;
                }
                len++;
                cout << "successfully inserted!" << endl;
            }
        }

        void remove(int index){
            if (index < 0 && index >= len){
                cout << "invalid index!" << endl;
            }else{
                for (int i = index; i < len - 1; i++){
                    list[i] = list[i + 1];
                }
                len--;
            }
        }

        int swap(int f_index, int s_index){
            int temp = list[f_index];
            list[f_index] = list[s_index];
            list[s_index] = temp;
        }

        // transposition and move to front 
        int linear_search(int value){
            for (int i = 0; i < len; i++){
                if(value == list[i]){
                    if (i != 0){
                        swap(i, i-1);
                    }
                    return i;
                }
            }
            return -1;
        }

        int binary_search(int value){
            int low = 0;
            int high = len - 1;
            while (low <= high){
                int middle = (low + high)/2;
                if (list[middle] > value){
                    high = middle - 1;
                }else if(list[middle] < value){
                    low = middle + 1;
                }else{
                    return middle;
                }
            }
            return -1;
        }

        int get(int index){
            if (index < len && index >= 0){
                return list[index];
            }else{
                cout << "invalid index" << endl;
            }
        }

        void set(int index, int value){
            if (index < len && index >= 0){
                list[index] = value;
            }else{
                cout << "invalid index!" << endl;
            }
        }

        int max(){
            int m = list[0];
            for (int i = 0; i < len; i++){
                if (list[i] > m){
                    m = list[i];
                }
            }
            return m;
        }

        int min(){
            int m = list[0];
            for (int i = 0; i < len; i++){
                if (list[i] < m){
                    m = list[i];
                }
            }
            return m;
        }

        int sum(){
            int sum = 0;
            for (int i = 0; i < len; i++){
                sum += list[i];
            }
            return sum;
        }

        float avg(){
            return float(sum())/len;
        }

        void reverse(){
            for (int i = 0; i < len/2; i++){
                int temp = list[i];
                list[i] = list[len - 1 - i];
                list[len - 1 - i] = temp;
            }
        }

        void left_shift(){
            for (int i = 0; i < len - 1; i++){
                list[i] = list[i + 1];
            }
            list[len - 1] = 0;
        }

        void right_shift(){
            for (int i = len - 1; i > 0; i--){
                list[i] = list[i - 1];
            }
            list[0] = 0;
        }

        void rotate_left(){
            int temp = list[0];
            for (int i = 0; i < len - 1; i++){
                list[i] = list[i + 1];
            }
            list[len - 1] = temp;
        }

        void rotate_right(){
            int temp = list[len - 1];
            for (int i = len - 1; i > 0; i--){
                list[i] = list[i - 1];
            }
            list[0] = temp;
        }

        void sorted_insert(int value){
            if (size == len){
                cout << "oops... no space available" << endl;
            }else{
                if (value > list[len - 1]){
                    list[len] = value;
                }else{
                    int temp = list[len - 1];
                    for (int i = len - 1; i >= 0; i--){
                        if (list[i] > value){
                            list[i] = list[i - 1];
                        }else{
                            list[i] = value;
                        }
                    }
                    list[len] = temp;
                }
                len++;
            }
        }

        int check_sorted(){
            for (int i = 0; i < len - 1; i++){
                if (list[i] > list[i + 1]){
                    return -1;
                }
            }
            return 1;
        }
        
        void negative_positive(){
            int negative = 0;
            int positive = len - 1;
            while(negative < positive){
                if (list[negative] >= 0 && list[positive] < 0){
                    swap(positive, negative);
                    positive++;
                    negative++;
                }

                if (list[negative] < 0){
                    negative++;
                }
                if (list[positive] >= 0){
                    positive--;
                }
            }
        }

        int * merge(array first, array second){
            if (first.check_sorted() == 1 && second.check_sorted() == 1){
                int * merged = new int[first.len + second.len];
                int first_index = 0;
                int second_index = 0;
                while (first_index < first.len && second_index < second.len){
                    if (first.list[first_index] < second.list[second_index]){
                        merged[first_index + second_index] = first.list[first_index];
                        first_index++;
                    }else{
                        merged[first_index + second_index] = second.list[second_index];
                        second_index++;
                    }
                }

                if (second_index < second.len){
                    for (int i = second_index; i < second.len; i++){
                        merged[first_index + second_index] = second.list[second_index];
                        second_index++;
                    }
                }else if(first_index < first.len){
                    for (int i = first_index; i < first.len; i++){
                        merged[first_index + second_index] = first.list[first_index];
                        first_index++;
                    }
                }
                return merged;
            }else{
                cout << "not sorted!" << endl;
            }
        }

        int * U(array first, array second){
            int * un = new int[first.len + second.len]; 
            if (first.check_sorted() == 1 && second.check_sorted() == 1){
                int * merged = new int[first.len + second.len];
                int first_index = 0;
                int second_index = 0;
                int main_index = 0; 
                while (first_index < first.len && second_index < second.len){
                    if (first.list[first_index] < second.list[second_index]){
                        merged[main_index] = first.list[first_index];
                        first_index++;
                        main_index++;   
                    }else if(first.list[first_index] > second.list[second_index]){
                        merged[main_index] = second.list[second_index];
                        second_index++;
                        main_index++;   
                    }else{
                        merged[main_index] = second.list[second_index];
                        second_index++;
                        first_index++;
                        main_index++;   
                    }
                }

                if (second_index < second.len){
                    for (int i = second_index; i < second.len; i++){
                        merged[main_index] = second.list[second_index];
                        second_index++;
                        main_index++;
                    }
                }else if(first_index < first.len){
                    for (int i = first_index; i < first.len; i++){
                        merged[main_index] = first.list[first_index];
                        first_index++;
                        main_index++;
                    }
                }
                return merged;
            }else{
                for (int i = 0; i < first.len; i++){
                    un[i] = first.list[i];
                }    

                int index = first.len;
                for (int i = 0; i < second.len; i++){
                    int decider = 0;
                    for (int j = 0; j < first.len; j++){
                        if (second.list[i] == first.list[j]){
                            decider = 1;
                            break;
                        }    
                    }
                    if (decider){
                        ;
                    }else{
                        un[index] = second.list[i];
                        index++;
                    }
                }

                return un;
            }
        }

        int * intersection(array first, array second){
            int length;
            if (first.len > second.len){
                length = second.len;
            }else{
                length = first.len;
            }

            int * intersect = new int[length];

            if (first.check_sorted() == 1 && second.check_sorted() == 1){
                if (first.check_sorted() == 1 && second.check_sorted() == 1){
                int first_index = 0;
                int second_index = 0;
                int main_index = 0; 
                while (first_index < first.len && second_index < second.len){
                    if (first.list[first_index] < second.list[second_index]){
                        first_index++;   
                    }else if(first.list[first_index] > second.list[second_index]){
                        second_index++;   
                    }else{
                        intersect[main_index] = second.list[second_index];
                        second_index++;
                        first_index++;
                        main_index++;   
                    }
                }
                return intersect;
            }else{
                int index = 0;
                for (int i = 0; i < first.len; i++){
                    int decider = 0;
                    for (int j = 0; j < second.len; j++){
                        if (first.list[i] == second.list[j]){
                            decider = 1;
                            break;
                        }
                    }
                    
                    if (decider){
                        intersect[index] = first.list[i];
                        index++;
                    }else{
                        ;
                    }

                }
                return intersect;
                }
            }
        }

        int * difference(array first, array second){
            int * diff = new int[first.len];

            if (first.check_sorted() == 1 && second.check_sorted() == 1){
                int first_index = 0;
                int second_index = 0;
                int main_index = 0; 
                while (first_index < first.len && second_index < second.len){
                    if (first.list[first_index] < second.list[second_index]){
                        diff[main_index] = first.list[first_index];
                        first_index++;   
                        main_index++;
                    }else if(first.list[first_index] > second.list[second_index]){
                        second_index++;   
                    }else{
                        second_index++;
                        first_index++;   
                    }
                }
                return diff;
            }else{
                int index = 0;
                for (int i = 0; i < first.len; i++){
                    int decider = 0;
                    for (int j = 0; j < second.len; j++){
                        if (first.list[i] == second.list[j]){
                            decider = 1;
                            break;
                        }
                    }
                    
                    if (decider){
                        ;
                    }else{
                        diff[index] = first.list[i];
                        index++;
                    }

            }
            return diff;
            }
        }

        int one_missing_n_natural(int starting, int end){
            for (int i = 0; i < end - starting; i++){
                if (list[i] - i !=  starting){
                    return list[i] - 1; 
                }
            }
        }

        int * multiple_missing_n_natural(int starting, int end){
            int * missing = new int[end - starting];
            int index = 0;
            cout << "hi" << endl;
            for (int i = 0; i < len; i++){
                if (list[i] - i != starting){
                    for (int j = 1; j <= list[i] - i - starting; j++){
                        missing[index] = list[i] - j;
                        index++;
                    }
                    starting += list[i] - i - starting;
                }
            }

            return missing;
        }

        void missing_n_natural_hashtable(int n){
            int * hash = new int[n+1];
            for (int i = 0; i < len; i++){
                hash[list[i]]++;
            }

            for (int i = 1; i <= n; i++){
                if (hash[i] == 0){
                    cout << i << " ";
                }
            }
            cout << endl;
        }

        void duplicates(){
            if (check_sorted() == 1){
                int last;
                int count = 1;
                int controller = 0;
                for (int i = 0; i < len-1; i++){
                    if (list[i] == list[i+1]){
                        int j = i + 1;
                        while(list[j] == list[i]){
                            j++;
                        }
                        cout << list[i] << " " << j - i << endl;
                        i = j - 1;
                    }
                }
            }
        }


        int * min_max(){
            int min = list[0];
            int max = list[1];
            for (int i = 1; i < len; i++){
                if (list[i] > min){
                    if (list[i] > max){
                        max = list[i];
                    }
                }else{
                    min = list[i];
                }
            }
            int * hold = new int[2];
            hold[0] = min;
            hold[1] = max;
            return hold;
        }

        int pair_sum_sorted(int n){
            if (check_sorted() == 1){
                int start = 0;
                int end = len - 1;
                int count = 0;
                while (start < end){
                    if (list[start] + list[end] == n){
                        count++;
                        cout << list[start] << " " << list[end] << endl;
                        start++;
                        end--;
                    }else if(list[start] + list[end] > n){
                        end--;
                    }else{
                        start++;
                    }
                }
                return count;
            }else{
                int m = max();
                int * hash = new int[m+1];
                for (int i = 0; i < m+1; i++){
                    hash[i] = 0;
                }
                int count = 0;
                for (int i = 0; i < len; i++){
                    if (hash[n - list[i]] != 0){
                        count++;
                        hash[n - list[i]]--;
                        cout << list[i] << " " << n - list[i] << endl;
                    }else{
                        hash[list[i]]++;
                    }
                }
                return count;
            }
        }

};

int main(){
    array holder(10);
    array holder2(5);
    holder.set_elements(10);
    holder2.set_elements(4);
    cout << holder.pair_sum_sorted(10);
    // int * merged = new int[holder.get_length() + holder2.get_length()];

    // merged = holder.difference(holder, holder2);
    // cout << endl;
    // holder.negative_positive();
    // holder.display();
    // holder.insert(10, 2);
    // holder.display();
    // holder.remove(2);
    // holder.display();
    // // cout << holder.linear_search(3) << endl;
    // // holder.display();
    // cout << holder.binary_search(3) << endl;
    // cout << holder.get(2) << endl;
    // holder.set(2, 5);
    // holder.display();
    // cout << holder.max() << endl;
    // holder.reverse();
    // holder.display();
    // holder.right_shift();
    // holder.display();
    // // holder.sorted_insert(2);
    // // holder.display();
    // cout << holder.check_sorted() << endl;
    return 0;
}