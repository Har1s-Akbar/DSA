#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <unordered_set>

class Graph{
    private:
        std::unordered_map<std::string,std::vector<std::string>> graph;

    void utilityDepthFirst(std::string vertex, std::unordered_set<std::string>& visited, std::vector<std::string>& arr){
        visited.insert(vertex);
        arr.push_back(vertex);
        auto it = graph.find(vertex);
        if(it != graph.end()){
            for(const std::string& neigh:it->second){
                if(visited.find(neigh) == visited.end()){
                    utilityDepthFirst(neigh,visited,arr);
                }
            }
        }

    };

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
    };

    void dfSearch(std::string vertex){
        if(graph.empty()) {
        std::cout << "\n Graph is empty\n";
        return; 
    }
    
    std::unordered_set<std::string> visited;
    std::vector<std::string> arr;
    
    utilityDepthFirst(vertex, visited, arr);

    for(const std::string& node : arr) {
        std::cout << node << " ";
    }
    };

    void bfSearch(std::string start){
        std::queue<std::string> current ;
        std::unordered_set<std::string> visited ;

        current.push(start);
        visited.insert(start);
        while(!current.empty()){
            std::string curr = current.front();
            current.pop();

            std::cout<<curr<<" ";

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
    Graph network;

    // Test Case 1: Building a Social Network
    // Alice -- Bob -- David
    //   |      |
    // Charlie--/
    network.addEdge("Alice", "Bob");
    network.addEdge("Alice", "Charlie");
    network.addEdge("Bob", "David");
    network.addEdge("Bob", "Charlie");

    network.printVertices();

    // Test Case 2: BFS (Layer by Layer)
    // Starting from Alice, it should visit neighbors (Bob, Charlie) before David.
    std::cout << "BFS starting from Alice: ";
    network.bfSearch("Alice"); 
    // Expected: Alice Bob Charlie David (order of Bob/Charlie may vary)
    
    std::cout << "\n\n";

    // Test Case 3: DFS (Deep Dive)
    // Starting from David, it will go David -> Bob -> Alice -> Charlie
    std::cout << "DFS starting from David: ";
    network.dfSearch("David");
    // Expected: David Bob Alice Charlie (order may vary based on vector order)

    std::cout << "\n\n";

    // Test Case 4: Non-existent Node
    std::cout << "Testing non-existent node (Zane): ";
    network.bfSearch("Zane"); // Should print nothing/handle gracefully
    
    std::cout << "\nTests Complete." << std::endl;

    return 0;
}