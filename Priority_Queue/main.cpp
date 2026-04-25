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
            if(index*2+2<endIndex && heap[largest]<heap[index*2+2]){
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
        if(heap.empty()) return;
        heap[0] = heap[heap.size()-1];
        heap.erase(heap.begin()+heap.size()-1);
        int index = 0;
        heapifyDown(index);
    };

    int top() {
    if (heap.empty()) throw std::runtime_error("Heap is empty");
    return heap[0];
}

    bool empty() {
    return heap.empty();
    }

};

int main() {
    Myheap myHeap;

    // Test 1: Basic Insertion
    std::cout << "--- Test 1: Inserting 10, 20, 5, 30 ---" << std::endl;
    myHeap.insert(10);
    myHeap.insert(20);
    myHeap.insert(5);
    myHeap.insert(30);
    
    std::cout << "Expected Root: 30 | Actual Root: " << myHeap.top() << std::endl;

    // Test 2: Sequence of Pops (Heapsort behavior)
    std::cout << "\n--- Test 2: Popping elements in order ---" << std::endl;
    // We expect 30 -> 20 -> 10 -> 5
    while (!myHeap.empty()) {
        std::cout << "Popping: " << myHeap.top() << std::endl;
        myHeap.pop();
    }

    // Test 3: Handling Large Inputs
    std::cout << "\n--- Test 3: Large Input ---" << std::endl;
    for(int i = 1; i <= 10; i++) {
        myHeap.insert(i * 7 % 13); // Scrambled numbers
    }
    std::cout << "Max element after scrambled inserts: " << myHeap.top() << " (Expected: 11)" << std::endl;

    return 0;
}