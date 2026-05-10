#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Graph{
    private:
        std::unordered_map<std::string,std::vector<std::string>> graph;

    public:
    void addEdge(std::string baseVertex, std::string targetVertex){
        auto it = graph.find(baseVertex);

        if(it != graph.end()){
            it->second.push_back(targetVertex);
        }else{
            graph.try_emplace(baseVertex, {targetVertex});
        }
    };
};