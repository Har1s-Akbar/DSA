#include <iostream>
#include <vector>

class Heap{
    private:
    std::vector<int> heap;

    Heap(std::vector<int> array){
        heap = array;

        if(heap.size()<=0) return;

        

    }


    void heapifyUp(int index){
        while(index>0){
            if(heap[index]>heap[(index-1)/2]){
                std::swap(heap[index],heap[(index-1)/2]);
                index = (index-1)/2;
            }else{
                break;
            }
        }
    }

    void heapifyDown(int index){
        int endIndex = heap.size();
        int largest= index;

        while(index<endIndex){
            if(largest<endIndex && heap[index]<heap[(index*2+1)]){
                largest = index*2+1;
            };
            if(largest <endIndex && heap[largest] < heap[index*2+2]){
                largest = index*2+2;
            };

            if(largest == index) break;

            std::swap(heap[index],heap[largest]);

            index = largest;

        }

    }

    public:
    void insert(int num){
        heap.push_back(num);
        int index = heap.size()-1;
        heapifyUp(index);
    };

    void pop(){
        if(heap.size()==0) return;
        int index = 0;
        heap[index] = heap[heap.size()-1];
        heap.erase(heap.begin()+heap.size()-1);

        heapifyDown(index);

    };

};
