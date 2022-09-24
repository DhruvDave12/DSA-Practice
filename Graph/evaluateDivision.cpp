#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<string, vector<pair<string, double>>> adj;
    map<string, bool> vis;

    void createGraph(vector<vector<string>> &equations, vector<double> &values)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i] * 1.00000});
            adj[equations[i][1]].push_back({equations[i][0], (double)(1 / values[i]) * 1.00000});
        }
    }

    bool dfs(string curr, string needed, double &res, double toMul)
    {
        vis[curr] = true;
        res = res * (toMul);
        if (curr == needed)
        {
            return true;
        }

        for (auto it : adj[curr])
        {
            if (!vis[it.first])
            {
                if (dfs(it.first, needed, res, it.second))
                    return true;
            }
        }

        res = res / (toMul);
        return false;
    }

    void print()
    {
        for (auto it : adj)
        {
            cout << it.first << " -> { ";
            for (auto itr : adj[it.first])
            {
                cout << itr.first << " " << itr.second << ", ";
            }
            cout << " }\n";
        }
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        createGraph(equations, values);

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            if (adj.count(queries[i][0]) == 0 || adj.count(queries[i][1]) == 0)
            {
                ans.push_back(-1 * 1.00000);
                continue;
            }
            bool flag = false;
            for (auto it : adj[queries[i][0]])
            {
                if (it.first == queries[i][1])
                {
                    flag = true;
                    ans.push_back(it.second);
                }
            }

            if (!flag)
            {
                double res = 1.00000;
                double toMul = 1.00000;
                vis.clear();
                if (dfs(queries[i][0], queries[i][1], res, toMul))
                {
                    ans.push_back(res);
                }
                else
                {
                    ans.push_back(-1 * 1.00000);
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}