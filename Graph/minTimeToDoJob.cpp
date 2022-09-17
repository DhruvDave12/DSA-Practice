#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int,vector<int>> adjList;
    map<int,bool> vis;

    void add(int u, int v){
        adjList[u].push_back(v);
    }
};

vector<int> minTime(Graph gh, int N){
    vector<int> indegrees(N,0);

    for(int i=0; i<N; i++){
        for(auto it: gh.adjList[i]){
            indegrees[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<N; i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }

    vector<int> vec(N, 1);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto it: gh.adjList[temp]){
            indegrees[it]--;
            if(indegrees[it] == 0){
                vec[it] = vec[temp]+1;
                q.push(it);
            }
        }
    }

    return vec;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;
    gh.add(1,3);
    gh.add(1,4);
    gh.add(1,5);
    gh.add(2,3);
    gh.add(2,9);
    gh.add(3,6);
    gh.add(4,6);
    gh.add(4,8);
    gh.add(5,8);
    gh.add(2,8);
    gh.add(6,7);
    gh.add(7,8);
    gh.add(8,10);

    vector<int> ans = minTime(gh,11);

    for(int i=1; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}