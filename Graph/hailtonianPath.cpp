#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int,vector<int>> adjList;

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
};

vector<vector<int>> getAllPermutations(int n){
    vector<int> vec(n);
    vector<vector<int>> res;

    for(int i=1; i<=n; i++) vec[i-1] = i;

    do{
        res.push_back(vec);
    } while(next_permutation(vec.begin(), vec.end()));

    return res;
}

vector<vector<int>> getHamiltonianPaths(Graph gh, int N){
    vector<vector<int>> permutes = getAllPermutations(N);
    vector<vector<int>> res;
    bool isHamil = false;

    for(auto it: permutes){
        isHamil = true;
        for(int i=0; i<it.size()-1; i++){
            int currNode = it[i];
            int nextNode = it[i+1];
            if(find(gh.adjList[currNode].begin(), gh.adjList[currNode].end(), nextNode) == gh.adjList[currNode].end()){
                isHamil = false;
                break;
            }
        }
        if(isHamil){
            res.push_back(it);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // we have the adjcency graph with N nodes and we will generate different paths in N! ways.
    // now we will check wether if any path exists
    // so TC: O(N!)

    Graph gh;
    gh.addEdge(1,2);
    gh.addEdge(1,4);
    gh.addEdge(2,1);
    gh.addEdge(2,3);
    gh.addEdge(2,4);
    gh.addEdge(3,2);
    gh.addEdge(4,1);
    gh.addEdge(4,2);

    int N = 4;


    vector<vector<int>> res = getHamiltonianPaths(gh,N);

    for(auto it: res){
        for(int i=0; i<it.size(); i++){
            cout<<it[i]<<" ";
        }cout<<endl;
    }

    // Now in travelling sales man problem we are supposed to find the min weight hamiltonian path
    return 0;
}