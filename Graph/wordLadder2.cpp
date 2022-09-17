#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     void getPath(vector<string> &wordList, string endWord, string curr, vector<string> &res, vector<vector<string>> &finalRes, unordered_set<string> st){
//         if(st.size() == 0) return;

//         if(curr == endWord){
//             finalRes.push_back(res);
//             return;
//         }

//         // cout<<curr<<"\n";
//         for(int i=0; i<curr.length(); i++){
//             char og = curr[i];
//             for(char ch='a'; ch <= 'z'; ch++){
//                 curr[i] = ch;
//                 if(st.find(curr) != st.end()){
//                     st.erase(curr);
//                     res.push_back(curr);
//                     getPath(wordList,endWord,curr,res,finalRes,st);
//                     res.pop_back();
//                 }
//                 curr[i] = og;
//             }
//         }

//         return;
//     }

//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       
//         vector<vector<string>> finalRes;
//         vector<string> res;
//         unordered_set<string> st(wordList.begin(), wordList.end());

//         res.push_back(beginWord);
//         st.erase(beginWord);

//         getPath(wordList,endWord,beginWord,res,finalRes,st);

//         int minSize = INT_MAX;
//         vector<vector<string>> anss;
//         for(int i=0; i<finalRes.size(); i++){
//             // cout<<finalRes[i].size()<<"\n";
//             if(finalRes[i].size() <= minSize){
//                 minSize = finalRes[i].size();
//             }
//         }
        
//         for(int i=0; i<finalRes.size(); i++){
//             if(finalRes[i].size() == minSize){
//                 anss.push_back(finalRes[i]);
//             }
//         }
            
//         return anss;
//     }
// };

class Solution {
public:
    unordered_map<string, unordered_set<string>> G;
    vector<vector<string>> ans;

    void dfs(string start, string end, vector<string> &resTemp, int depth, unordered_set<string> &st){
        resTemp.push_back(start);
        
        if(start == end){
            reverse(resTemp.begin(), resTemp.end());
            ans.push_back(resTemp);
            return;
        }

        if(depth == 1) return;
        
        st.insert(start);
        for(auto it: G[start]){
            if(!st.count(it)){
                dfs(it,end,resTemp,depth-1,st);
            }
        }
        st.erase(start);
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push(beginWord);
        int depth = 0;
        bool found = false;
        while(!q.empty()){
            int n = q.size();

            while(n--){
                string temp = q.front();
                if(temp == endWord) {
                    break;
                }
                q.pop();
                for(int i=0;i<temp.length(); i++){
                    char og = temp[i];
                    for(char ch='a'; ch<='z'; ch++){
                        string x = temp;
                        x[i] = ch;
                        if(st.find(x) != st.end() && G[x].count(temp) == 0 && x != temp){
                            G[x].insert(temp);
                            q.push(x);
                        }
                    }
                }
            }
            depth++;
        }    

        // now we will do reverse dfs
        vector<string> resTemp;
        unordered_set<string> sstt;
        dfs(beginWord,endWord,resTemp,depth,sstt);

        return ans;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string begin = "qa";
    string end = "sq";

    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};

    vector<vector<string>> ans = Solution().findLadders(begin, end, wordList);

    // we need to get the minsize one
    
    for(auto it: ans){
        for(int i=0; i<it.size(); i++){
            cout<<it[i]<<", ";
        } cout<<"\n";
    }

    return 0;
}