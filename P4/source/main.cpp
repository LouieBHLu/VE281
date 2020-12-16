#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int nodeNum;
    class Edge{
    public:
        int weight;
        int start_index;
        int end_index;
        Edge *next = nullptr;
        Edge(int weight, int start, int end) {
            this->weight = weight;
            this->start_index = start;
            this->end_index = end;
        }        
    };

    class Node{
    public:
        Edge* headEdge = nullptr;
        int index = 0;
        int D = -1;
        bool visited = false;
        int indegree = 0;
        Node(Edge* headEdge, int ID, int D, int indegree){
            this->headEdge = headEdge;
            this->index = ID;
            this->D = D;
            this->visited = false;
            this->indegree = indegree;
        }
    };

    Node* nodes;

public:
    Graph(int node_num){
        this->nodeNum = node_num;
        nodes = new Node[node_num];
    }

    ~Graph(){
        // TODO
        delete[] nodes;
    }
};

int readGraph(){

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
