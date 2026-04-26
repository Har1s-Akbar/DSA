#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>


class Heap{
    private:
    std::vector<int> heap;
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
            if(index*2+1<endIndex && heap[largest]<heap[(index*2+1)]){
                largest = index*2+1;
            };
            if(index*2+2 <endIndex && heap[largest] < heap[index*2+2]){
                largest = index*2+2;
            };

            if(largest == index) break;

            std::swap(heap[index],heap[largest]);

            index = largest;

        }

    }

    public:

        Heap(std::vector<int> array){
        heap = array;

        if(heap.size()<=0) return;

        for(int i = (heap.size()/2)-1; i>=0; i--){
            heapifyDown(i);
        }
    }


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

    int top(){
        return heap[0];
    }

    bool empty(){
        return heap.empty();
    };

    std::vector<int> sortedResult(){
        std::vector<int> sortedHeap;
        if(heap.size() == 0)return sortedHeap;
        int index = heap.size()-1;
        for(int i =0 ; i<=index ; i++){
            sortedHeap.push_back(top());
            pop();
        };
        return sortedHeap;
    }
};


int main() {
    // 1. Generate 10,000 scrambled numbers
    std::vector<int> data(10000);
    std::iota(data.begin(), data.end(), 1); // Fill 1 to 10,000
    
    std::shuffle(data.begin(), data.end(), std::mt19937{std::random_device{}()});

    std::cout << "--- Starting Stress Test ---" << std::endl;
    std::cout << "Input Size: " << data.size() << " elements." << std::endl;

    // 2. Build Heap (Bottom-Up O(n))
    Heap myHeap(data);

    // 3. Extract Sorted Results (O(n log n))
    std::vector<int> result = myHeap.sortedResult();

    // 4. Verification Logic
    bool isSorted = true;
    for (size_t i = 1; i < result.size(); i++) {
        if (result[i] > result[i - 1]) { // Should be descending
            isSorted = false;
            break;
        }
    }

    std::cout << "Result Size: " << result.size() << std::endl;
    std::cout << "Sorted Correctly: " << (isSorted ? "YES ✅" : "NO ❌") << std::endl;
    
    if (isSorted && !result.empty()) {
        std::cout << "Max Value: " << result.front() << " | Min Value: " << result.back() << std::endl;
    }

    return 0;
}