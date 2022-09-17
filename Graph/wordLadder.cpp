#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // we are going to do a BFS Traversal and check all possibilities
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            // else we check for all possibilities
            for(int i=0; i<word.length(); i++){
                char og = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        // if this word exists push it in our queue
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }

                word[i] = og;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string begin = "qa";
    string end = "sq";

    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};

    int ans = Solution().ladderLength(begin, end, wordList);

    cout << "ANS: " << ans << "\n";
    return 0;
}