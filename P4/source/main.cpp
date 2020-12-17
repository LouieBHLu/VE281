#include <bits/stdc++.h>
#include <string>
#include <queue>
using namespace std;
const int INF = 1000000000;

// A type for shortest distance
// First item store the shortest distance to the node
// Second item store the node's index
typedef pair<int, int> iPair; 

class Graph{
private:
    int nodeNum;

    class Edge{
    public:
        int weight;
        int start_index;
        int end_index;
        Edge *next;

        Edge(int weight, int start, int end): weight(weight), start_index(start), end_index(end), next(nullptr) {}        
    };

    class Node{
    public:
        Edge* headEdge;
        int index;
        bool visited;
        Node(Edge* headEdge = nullptr, int ID = -1):
        headEdge(headEdge), index(ID), visited(false) {}
    };

    Node* nodes;

public:
    Graph(int node_num){
        nodeNum = node_num;
        nodes = new Node[node_num];
    }

    ~Graph(){
        for(int i = 0; i < nodeNum; i++){
            Edge* q = nullptr;
            Edge* p = nodes[i].headEdge;
            while(p){
                q = p->next;
                delete p;
                p = q;
            }
        }
        delete[] nodes;
    }

    void readGraph(){
        // Set index of nodes
        for(int i = 0; i < nodeNum; i++) nodes[i].index = i;

        // Read the file
        stringstream ss;
        while(!cin.eof()){
            string line;
            getline(cin, line);
            if(line.empty()) continue;
            ss.clear();
            ss.str(line);
            int start_node, end_node, weight;
            ss >> start_node >> end_node >> weight;

            if(!nodes[start_node].headEdge) nodes[start_node].headEdge = new Edge(weight, start_node, end_node);
            else{
                Edge** temp = &nodes[start_node].headEdge;
                while((*temp)->next) temp = &((*temp)->next);
                (*temp)->next = new Edge(weight, start_node, end_node);
            }
        }
    }

    void print_helper(int source_node, int end_node){
        cout << source_node << " " << end_node << " " << nodeNum << endl;
        for(int i = 0; i < nodeNum; i++){
            Edge** temp = &nodes[i].headEdge;
            if(!nodes[i].headEdge) continue;

            while(*temp){
                cout << (*temp)->start_index << " " << (*temp)->end_index << " " << (*temp)->weight << endl;
                temp = &((*temp)->next);
            } 
        }
    }

    void shortest_path(int source_node, int end_node){
        // Create a vector for distances and initialize all 
        // distances as infinite (INF) 
        vector<int> dist(nodeNum, INT_MAX);

        // Create a priority queue
        priority_queue <iPair,vector<iPair>,greater<iPair> > q;
        q.push(make_pair(0, source_node));
        dist[source_node] = 0;

        // Looping till priority queue becomes empty (or all 
        // distances are not finalized)
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            
            // scan all adjacent vertex of current node
            if(!nodes[u].headEdge) continue;
            else{
                Edge* temp = nodes[u].headEdge;
                while(temp){
                    int v = temp->end_index;
                    int w = temp->weight;

                    // If there is shorter path to v through u. 
                    if(dist[v] > dist[u] + w){
                        // Updating distance of v 
                        dist[v] = dist[u] + w;
                        q.push(make_pair(dist[v], v));
                    }

                    temp = temp->next;
                }
            }
        }
        
        // Output the shortest path length
        if(dist[end_node] == INT_MAX) cout << "No path exists!" << endl;
        else cout << "Shortest path length is " << dist[end_node] << endl;
    }

    void DAG(){
        // Calculate indegree of all nodes
        int* indegree = new int[nodeNum];
        for(int i = 0; i < nodeNum; i++) indegree[i] = 0;
        
        for(int i = 0; i < nodeNum; i++){
            if(!nodes[i].headEdge) continue;
            else{
                Edge* temp = nodes[i].headEdge;
                while(temp){
                    indegree[temp->end_index]++;
                    temp = temp->next;
                }
            }
        }

        queue<int> Q;
        int count = 0;

        // Enqueue all nodes with 0 indegree
        for(int i = 0; i < nodeNum; i++){
            if(indegree[i] == 0) Q.push(i);
        }

        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            count++;

            if(!nodes[u].headEdge) continue;
            else{
                Edge* temp = nodes[u].headEdge;
                while(temp){
                    int v = temp->end_index;
                    if(--indegree[v] == 0) Q.push(v);
                    // Check next edge
                    temp = temp->next;
                }
            }
        }

        if(count == nodeNum) cout << "The graph is a DAG" << endl;
        else cout << "The graph is not a DAG" << endl;

        delete[] indegree;
    }

    void MST(){
        vector<int> dist(nodeNum, INF);
        vector<bool> visited(nodeNum, false);
        priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
        int total_weight = 0;

        // Initialize 
        dist[0] = 0;
        pq.push(make_pair(0,0));

        while(!pq.empty()){
            int cur = pq.top().second;
            pq.pop();
            visited[cur] = true;

            // Update all neighburs
            vector<iPair> neighbours;     
            Edge* temp = nodes[cur].headEdge;
            while (temp){                                   
                int u = temp->end_index;
                int w = temp->weight;
                neighbours.push_back(make_pair(u,w));
                temp = temp->next;
            }                   

            for (int i = 0; i < nodeNum; i++){
                if(i != cur){
                    Edge *temp_1 = nodes[i].headEdge;
                    while (temp_1){
                        int p = temp_1->end_index;
                        int r = temp_1->start_index;
                        int q = temp_1->weight;
                        if(p == cur) neighbours.push_back(make_pair(r,q));
                        temp_1 = temp_1->next;
                    }                 
                }                                           
            }

            for (size_t i = 0; i < neighbours.size(); i++){
                int neighbour_index = neighbours[i].first;
                int neighbour_weight = neighbours[i].second;
                if(!visited[neighbour_index] && dist[neighbour_index] > neighbour_weight){
                    dist[neighbour_index] = neighbour_weight;
                    pq.push(make_pair(dist[neighbour_index],neighbour_index));
                }
            }
        }


        for (size_t i = 0; i < dist.size(); i++){
            if(dist[i]==INF){
                cout << "No MST exists!" << endl;
                return;
            }
            else total_weight += dist[i];
        }

        cout << "The total weight of MST is " << total_weight << endl;
    }
};

int main(){
    int node_num, source_node, end_node;
    cin >> node_num >> source_node >> end_node;
    Graph g(node_num);
    g.readGraph();
    g.shortest_path(source_node, end_node);
    g.DAG();
    g.MST();
    return 0;
}
