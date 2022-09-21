#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9+10

vector<long long> solver(vector<int> &del_order, vector<vector<long long>> &graph){
    int N = graph.size();
    vector<long long> ans(N);

    for(int k=0; k<del_order.size(); k++){
        int k_v = del_order[k];
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                long long newDist = graph[i][k_v] + graph[k_v][j];
                graph[i][j] = min(graph[i][j], newDist);
            }
        }

        long long sum = 0;
        // now we will get the minimum sum of all precious ones
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                sum += graph[del_order[i]][del_order[j]];
                ans.push_back(sum);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin>>n;

    vector<vector<long long>> graph(n,vector<long long>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    vector<int> del_order(n);
    for(int i=0; i<n; i++) cin>>del_order[i];

    reverse(del_order.begin(), del_order.end());

    vector<long long> ans = solver(del_order, graph);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}