#include <bits/stdc++.h>
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ BELLMAN FORD ALGORITHM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Bellman Ford Algo is used to find the shortest path from  source to all other nodes
// It is better than djikstra when it comes to negative edges.
// In djikstra we dont do relaxation so we can just go in and in the djikstra
// In terms of time bellman is worse than djikstra but it solves the problem of negative edges
// If a graph has negative cycle then it will not work but it will detect it.
// If after doing N-1 relaxations, if at one more relaxation the distance array changes then it has a negative cycle.
// TC = O(N-1)*O(E);
// SC = O(N)

class Graph
{
public:
    map<int, vector<pair<int, int>>> adj;

    void addEdgeDirected(int u, int v, int wt)
    {
        adj[u].push_back({v, wt});
    }
};

class BellmanFord
{
public:
    vector<int> bellmanAlgo(map<int, vector<pair<int, int>>> &adj, int N)
    {
        int maxx = 1000000;
        vector<int> dist(N, maxx);
        dist[0] = 0;
        map<int, vector<pair<int, int>>>::iterator itr;
        // This does relaxations
        for (int i = 1; i <= N - 1; i++)
        {
            for (itr = adj.begin(); itr != adj.end(); itr++)
            {
                for (auto it : adj[itr->first])
                {
                    if (dist[itr->first] + it.second < dist[it.first])
                    {
                        dist[it.first] = dist[itr->first] + it.second;
                    }
                }
            }
        }

        // Checking for negative cycle
        bool flag = false;

        for (itr = adj.begin(); itr != adj.end(); itr++)
        {
            for (auto it : adj[itr->first])
            {
                if (dist[itr->first] + it.second < dist[it.first])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        if (flag)
        {
            cout << "GRAPH HAS A NEGATIVE CYCLE"
                 << "\n";
        }

        return dist;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph gh;
    gh.addEdgeDirected(0, 1, 5);
    gh.addEdgeDirected(1, 5, -3);
    gh.addEdgeDirected(1, 2, -2);
    gh.addEdgeDirected(5, 3, 1);
    gh.addEdgeDirected(3, 2, 6);
    gh.addEdgeDirected(3, 4, -2);
    gh.addEdgeDirected(2, 4, 3);

    BellmanFord bf;
    vector<int> res = bf.bellmanAlgo(gh.adj, 6);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}