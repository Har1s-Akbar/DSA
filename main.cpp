#include <iostream>
#include <algorithm>
using namespace std;


class vector{
    int vSize=0;
    int vCapacity=0;
    int* base_addr = nullptr;

    public:
    // Here  we are initializing the vector with vSize=0, vCapacity=0,base_addr=bull_pointer    
    vector():vSize(0),vCapacity(0),base_addr(nullptr){};
        
    ~vector(){
        delete[] base_addr;
    };


    vector(const vector& other):vSize(other.vSize),vCapacity(other.vCapacity){
        base_addr = new int[vCapacity];
        for(int i = 0; i<vSize;i++){
            base_addr[i] = other.base_addr[i];
        };
    };

    vector& operator=(const class vector &other){
        if(this == &other)
            return *this;
        
        // delete[] base_addr;
        // vCapacity = other.vCapacity;
        
        int *temp = new int[other.vCapacity];

        for(int i =0;i<other.vSize;i++){
            temp[i] = other.base_addr[i];
        };
        delete[] base_addr;
        base_addr = temp;
        vSize = other.vSize;
        vCapacity = other.vCapacity;
        

        return *this;
    };

        // Here we are creating the push method for vector
        void push(int num){
            // If vCapacity is zero or we have null pointer (That means we are initializing the vector)
            if(vCapacity == 0){
                vSize = 0;
                vCapacity = 2;
                // Giving initial values for the vector then the vector will internally calculate 
                // the vSize and vCapacity and resize on it's own
                base_addr = new int[vCapacity];
            } else if (vSize == vCapacity){
                // if our vSize ==  vCapacity of memory we will then reallocate the vCapacity and the memeory
                vCapacity = std::max(1, 2*vCapacity);
                // Here we are craeting a temporary pointer so that we can copy the data from 
                // previous address and then again insert it back after we relocate the address
                
                int *temp = new int[vCapacity];                                      

                for(int i=0; i<vSize ; i++){
                    temp[i] = base_addr[i];
                };
                // Freeing up the previous memory (essential)
                delete [] base_addr;
                // inserting the data from temporary pointer to the base_address
                base_addr = temp;
            };
            // we need these two lines always no matter what because we have to 
            // push the given integer and also increment the vSize.
            base_addr[vSize] = num;
            vSize++;
            
        }
        int size() const {
            return vSize;
        };
        int capacity() const{
            return vCapacity;
        };

        bool is_empty ()const{
            return  vSize ? false : true;
        }

};

int main(){

    vector a;
    a.is_empty() ? cout<<"Vector is empty\n" : cout<<"Vector is not empty\n";
    a.push(3);
    a.is_empty() ? cout<<"Vector is empty\n": cout <<"Vector has 1 element\n";
    a.push(10);
    a.push(79);
    a.push(20);
    a.push(0);
    int size_of_vector = a.size();
    int capacity_of_vector = a.capacity();
    cout<<"The size of the vector is "<< size_of_vector << " The capacity is "<<capacity_of_vector<<"\n";

    vector b;
    b.is_empty() ? cout<<"Vector is empty\n" : cout<<"Vector is not empty\n";
    b = a;
    b.is_empty() ? cout<<"Vector is empty\n" : cout<<"Vector b has elements "<<b.size();
    
    // After checking and running it we can say it is working smoothly 
    return 0;
}