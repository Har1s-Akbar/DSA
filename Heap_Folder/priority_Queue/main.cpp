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
    

    public:
    void push(Task task){
        pQueue.push_back(task);
        
    }

};
