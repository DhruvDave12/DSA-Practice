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

    Node* dfs(Node* node, map<Node*,Node*> &mp){
        vector<Node*>neighbours;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto it: node->neighbors){
            // if we find that entry in map so means we have already traversed and set it so just push in the vector
            if(mp.find(it) != mp.end()){
                neighbours.push_back(mp[it]);
            } else {
                // else we visit
                neighbours.push_back(dfs(it, mp));
            }
        }

        clone->neighbors = neighbours;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        // We are going to create a node and then assign it the value of original
        // now we are going to traverse the whole original using dfs and then assign neighbours
        if(!node) return NULL;
        if(node->neighbors.size() == 0){
            Node* res = new Node(node->val);
            return res;
        }

        map<Node*, Node*> mp;
        Node* res = dfs(node,mp);

        return res;    
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}