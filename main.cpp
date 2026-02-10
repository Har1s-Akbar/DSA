#include <iostream>
using namespace std;
class vector{
    int size=0;
    int capacity=0;
    int* base_addr = nullptr;

    public:
    // Here  we are initializing the vector with size=0, capacity=0,base_addr=bull_pointer    
    vector():size(0),capacity(0),base_addr(nullptr){};
        
    ~vector(){
        delete[] base_addr;
    };


    vector(class vector& other):size(other.size),capacity(other.capacity){
        base_addr = new int[capacity];
        for(int i = 0; i<size;i++){
            base_addr[i] = other.base_addr[i];
        };
    };

    vector& operator=(const class vector &other){
        if(this == &other)
            return *this;
        
        delete[] base_addr;

        capacity = other.capacity;
        size = other.size;
        base_addr = new int[capacity];

        for(int i =0;i<size;i++){
            base_addr[i] = other.base_addr[i];
        };

        return *this;
    };

        // Here we are creating the push method for vector
        void push(int num){
            // If capacity is zero or we have null pointer (That means we are initializing the vector)
            if(capacity == 0){
                size = 0;
                capacity = 2;
                // Giving initial values for the vector then the vector will internally calculate 
                // the size and capacity and resize on it's own
                base_addr = new int[capacity];
            } else if (size == capacity){
                // if our size ==  capacity of memory we will then reallocate the capacity and the memeory
                capacity = max(1, 2*capacity);
                // Here we are craeting a temporary pointer so that we can copy the data from 
                // previous address and then again insert it back after we relocate the address
                
                int *temp = new int[capacity];                                      

                for(int i=0; i<size ; i++){
                    temp[i] = base_addr[i];
                };
                // Freeing up the previous memory (essential)
                delete [] base_addr;
                // inserting the data from temporary pointer to the base_address
                base_addr = temp;
            };
            // we need these two lines always no matter what because we have to 
            // push the given integer and also increment the size.
            base_addr[size] = num;
            size++;
            
        }

};

int main(){
    return 0;
}