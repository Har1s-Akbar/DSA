#include <iostream>
#include <vector>
#include <string>

struct Task{
    std::string task;
    int priority;

    Task(std::string name, int imp):task(name), priority(imp){};
};

class Priority_Queue{
    private:
        std::vector<Task> pQueue;
    
        void heapifyUp(int index){
            while(index>0){
                if(pQueue[index].priority>pQueue[(index-1)/2].priority){
                    std::swap(pQueue[(index-1)/2],pQueue[index]);
                    index = (index-1)/2;
                }else{
                    break;
                }
            }
        }

        void heapifyDown(int index){
            int endIndex = pQueue.size()-1;
            int largest = index;

            while(index <= endIndex){
                if(index*2+1<=endIndex && pQueue[largest].priority < pQueue[index*2+1].priority){
                    largest =  index*2+1;
                };
                if(index*2+2 <=endIndex && pQueue[largest].priority<pQueue[index*2+2].priority ){
                    largest = index*2+2;
                };
                if(largest == index) break;

                std::swap(pQueue[index], pQueue[largest]);
                index = largest;
            }
        }

    public:
    void push(Task task){
        pQueue.push_back(task);
        int index = pQueue.size()-1;
        heapifyUp(index);
    };

    void pop(){
        if(pQueue.size()-1<0) return;
        std::swap(pQueue[0],pQueue[pQueue.size()-1]);
        pQueue.pop_back();

        int index = 0;
        if(!pQueue.empty()){
            heapifyDown(index);
        }
    }

    Task top(){
        return pQueue[0];
    };

    bool empty(){
        if(pQueue.size() == 0) return true;
        if(pQueue.size() != 0) return false;
    }

};
