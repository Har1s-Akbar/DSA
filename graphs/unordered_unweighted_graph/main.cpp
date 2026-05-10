#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Graph{
    private:
        std::unordered_map<std::string,std::vector<std::string>> graph;

    public:
    void addEdge(std::string baseVertex, std::string targetVertex){
        graph[baseVertex].push_back(targetVertex);
        graph[targetVertex].push_back(baseVertex);
    };
    void printVertices(){
        if(graph.empty()){
            std::cout<<"No vertices\n";
        }

        for(const auto& [vertex, neighbours] : graph){
            std::cout<<"\n-"<<vertex<<"\n";
            for(const auto& x:neighbours){
                std::cout<<x<<" ";
            }
        };
    }
};


int main() {
    Graph mySocialNetwork;

    mySocialNetwork.addEdge("Alice", "Bob");
    mySocialNetwork.addEdge("Alice", "Charlie");
    mySocialNetwork.addEdge("Bob", "David");

    mySocialNetwork.printVertices();

    return 0;
}