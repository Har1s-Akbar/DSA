#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

class Graph{
    private:
        std::unordered_map<std::string,std::vector<std::string>> graph;
        std::unordered_map<std::string,int> inDegree;
    public:
    void addEdge(std::string fromVertex, std::string targetVertex){
        graph[fromVertex].push_back(targetVertex);

        if(inDegree.find(fromVertex) == inDegree.end()) inDegree[fromVertex] = 0;

        inDegree[targetVertex]++;
    };

    void topologicalOrder(){
        std::queue<std::string> q;
        while(!inDegree.end()){
            
        }
    };


};
