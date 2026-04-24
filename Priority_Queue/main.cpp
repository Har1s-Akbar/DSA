#include <iostream>
#include <vector>

class Myheap{
    private:
    std::vector<int> heap;

    int parent(int i){
        return (i-1)/2;
    };
    int left(int i){
        return (2*i+1);
    };
    int right(int i){
        return (2*i+2);
    }
    public:

    void insert(int num){
        
    }
    
}