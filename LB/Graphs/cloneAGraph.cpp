#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map<Node*, bool> visited;

    Node* createGraph(Node* node, map<Node*, Node*> &mp){
        vector<Node*>  neighbours;
        Node* clonedGraph = new Node(node->val);
        mp[node] = clonedGraph;

        for(int i=0; i<node->neighbors.size(); i++){
            if(mp.count(node->neighbors[i]) != 0){
                // already cloned
                neighbours.push_back(mp[node->neighbors[i]]);
            }
             else {
                // here we call dfs again for the new node
                neighbours.push_back(createGraph(node, mp));
             }
        }

        clonedGraph->neighbors = neighbours;
        return clonedGraph;
    }
    Node* cloneGraph(Node* node) {
        // we have to traverse on each node of the node using dfs
        if(!node) return NULL;
        if(node->neighbors.size() == 0) {
            Node* newNode = new Node(node->val);
            return newNode;
        }
        map<Node*, Node*> mp;
        Node* ans = createGraph(node, mp);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}