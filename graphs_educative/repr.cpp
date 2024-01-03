#include <iostream>
#include <vector>
#include <string>
#include <map>

class AdjacencyMatrix {
private:
    std::vector<std::vector<bool>> matrix;
    std::map<std::string, int> nameToIndex;
    std::vector<std::string> nodeNames;

public:
    AdjacencyMatrix() {
        // Constructor
    }

    void addNode(const std::string& name) {
        if (nameToIndex.find(name) == nameToIndex.end()) {
            nameToIndex[name] = nodeNames.size();
            nodeNames.push_back(name);
            for (auto& row : matrix) {
                row.push_back(false); // Add a new column to each row
            }
            matrix.push_back(std::vector<bool>(nodeNames.size(), false)); // Add a new row
        }
    }

    void addEdge(const std::string& from, const std::string& to) {
        if (nameToIndex.find(to) == nameToIndex.end()) {
            addNode(to);
        }
        if (nameToIndex.find(from) == nameToIndex.end()) {
            addNode(from);
        }
        int to_id = nameToIndex[to];
        int from_id = nameToIndex[from];
        matrix[from_id][to_id] = true;
    }

    void addEdges(const std::vector<std::pair<std::string, std::string>>& edges) {

        for (auto edge : edges) {
            addEdge(edge.first, edge.second);
        }    

    }

    void printMatrix() {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    AdjacencyMatrix graph;
    graph.addNode("a");
    graph.addNode("b");
    graph.addNode("c");
    graph.addEdge("a", "b");
    graph.addEdge("b", "c");

    graph.printMatrix();

    return 0;
}
