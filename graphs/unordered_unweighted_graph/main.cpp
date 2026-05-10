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
};