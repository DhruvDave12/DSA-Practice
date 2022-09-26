#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<char> parent;
    vector<int> rank;

    DSU(){
        for(int ch='a'; ch<= 'z'; ch++){
            parent.push_back(ch);
            rank.push_back(0);
        }
    }

    char findParent(char u){
        if(u == parent[u-'a']) return u;
        return parent[u-'a'] = findParent(parent[u-'a']); 
    }

    void doUnion(char u, char v){
        char x = findParent(u);
        char y = findParent(v);

        if(rank[x-'a'] > rank[y-'a']){
            parent[y] = x;
        } else if(rank[x-'a'] < rank[y-'a']){
            parent[x] = y;
        } else{
            parent[x] = y;
            rank[y-'a']++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // put equal ones in one group and check if not equal in equal group
        DSU ds;
        for(auto it: equations){
            if(it[1] == '=') ds.doUnion(it[0], it[3]);
        }

        
        for(auto it: equations){
            if(it[1] == '!') {
                char x = ds.findParent(it[0]);
                char y = ds.findParent(it[3]);
                if(x == y) return false;
            }
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}