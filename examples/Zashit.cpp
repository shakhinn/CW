#include <iostream>
using namespace std;

struct A{
    int x;
    int y;
};

template<class T>

class Array{
public:
    Array(){
        arr = new T[1];
        size = 0;
    }
    void push_back(T& item){
        arr = my_realloc(arr, size+1);
        arr[size] = item;
        size++;
    }
    void pop_back() {
        size--;
        arr = my_realloc(arr, size);
    }
    T get(size_t index) {
        return arr[index];
    }
private:
T* my_realloc(T* src, size_t new_size){
    size_t size = sizeof(src)/sizeof(T);
    T* newSrc = new T[new_size];
    for(int i = 0; i<new_size; i++){
        newSrc[i] = src[i];
    }
    delete [] src;
    src = newSrc;
    return src;
}
private:
    T* arr;
    int size;
};

template<class T_key, class T_val>
class Dictionary{
public:
    Dictionary(){
        arrkey = Array<T_key>();
        arrVal = Array<T_val>();
        size = 0;
    }
    void add(T_key& key, T_val& val){
        arrVal.push_back(val);
        arrkey.push_back(key);
        size++;
    }
    void remove(T_key& key) {
        int iteration;
        for(int i = 0; i< size; i++){
            if(arrkey.get(i)==key){
                iteration = i;
            }
            break;
        }
        for(int i = iteration; i < size-1; i++){
            arrkey[i] = arrkey[i+1];
            arrVal[i] = arrVal[i+1];
        }
        size--;
    }
    T_val find(T_key& key){
        for(int i = 0; i < size; i++){
            if(arrkey.get(i) == key){
                return arrVal.get(i);
            }
            break;
        }
    }
private:
    Array<T_key> arrkey;
    Array<T_val> arrVal;
    int size;
};

int main() {
    int size, reallocsize;
    cin>> size>>reallocsize;
    Dictionary<int, int> dict = Dictionary<int, int>();
    int find = 3, value = 56;

   dict.add(find, value);

    cout<< dict.find(find);
    dict.remove(find);
    value = 72;
    dict.add(find, value);
    cout<< dict.find(find);


    return 0;
}

