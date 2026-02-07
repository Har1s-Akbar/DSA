#include <iostream>
using namespace std;
class vector{
    int size=0;
    int capacity=0;
    int* base_addr = nullptr;

    public:
        vector():size(0),capacity(0),base_addr(nullptr){};
        void push(int num){
            // capacity = capacity < size ? capacity + size*2 : capacity;

            if(capacity == 0 || base_addr == nullptr){
                size = 0;
                capacity = 2;
                base_addr = new int[capacity];
                base_addr[size] = num;
                size++;
            } else if (size > capacity){
                int new_capacity = max(1, 2*capacity);
                int *temp = new int[new_capacity];
                for(int i=0; i<size ; i++){
                    temp[i] = base_addr[i];
                };
                delete [] base_addr;
                base_addr = temp;
                delete temp;
            }
            
        }
};

int main(){
    return 0;
}