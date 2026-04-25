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

    void heapifyUp(int index){
        while(index > 0 && heap[index]>heap[(index-1)/2]){

        std::swap(heap[(index-1)/2], heap[index]);
        index = (index-1)/2;
        }
    }

    void heapifyDown(int index){
        int endIndex = heap.size();
        int largest=index;
        while(index<endIndex){
            if( index*2+1<endIndex && heap[index]<heap[index*2+1]){
                largest = index*2+1;
            };
            if(index*2+2<endIndex && heap[index]<heap[index*2+2]){
                largest = index*2+2;
            };
            if(largest==index)break;

            std::swap(heap[index],heap[largest]);

            index=largest;
        }
    }

    public:

    void insert(int num){
        heap.push_back(num);
        heapifyUp(heap.size()-1);
    };
    void pop(){
        heap[0] = heap[heap.size()-1];
        heap.erase(heap.begin()+heap.size()-1);
        int index = 0;
        heapifyDown(index);
    };
}