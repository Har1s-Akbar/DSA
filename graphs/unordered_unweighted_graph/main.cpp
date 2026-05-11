#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <unordered_set>

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
            std::cout<<"\n-"<<vertex<<":\n";
            for(const auto& x:neighbours){
                std::cout<<x<<" ";
            }
        };
    }
    void bfSearch(std::string start){
        std::queue<std::string> current ;
        std::unordered_set<std::string> visited ;

        current.push(start);
        visited.insert(start);
        while(!current.empty()){
            std::string curr = current.front();
            current.pop();

            auto it = graph.find(curr);
            if(it!= graph.end()){
                const std::vector<std::string>& neighbours = it->second;
                for(const auto& neigh:neighbours){
                    if (visited.find(neigh) == visited.end()) {
                        visited.insert(neigh);
                        current.push(neigh);
                    };
                };
            };
        };
    };
};


int main() {
    Graph mySocialNetwork;

    mySocialNetwork.addEdge("Alice", "Bob");
    mySocialNetwork.addEdge("Alice", "Charlie");
    mySocialNetwork.addEdge("Bob", "David");

    mySocialNetwork.printVertices();

    std::cout << "Adjacency List:";
    mySocialNetwork.printVertices();

    std::cout << "\nBFS Traversal from Alice: ";
    mySocialNetwork.bfSearch("Alice");

    return 0;
}