#include <bits/stdc++.h>
using namespace std;

// class WordDictionary
// {
// public:
//     map<string, int> mp;
//     WordDictionary()
//     {

//     }

//     void addWord(string word)
//     {
//         mp[word]++;
//     }

//     bool search(string word)
//     {
//         if(mp.count(word) != 0) return true;
        
//         int count = 0;
//         for(auto it: mp){
//             if(it.first.length() != word.length()) continue;
//             count = 0;
//             for(int i=0; i<it.first.length(); i++){
//                 if(word[i] == '.') continue;
//                 if(word[i] != it.first[i]) break;
//                 count++;
//             }

//             if(count == word.length()) return true;
//         }

//         return false;
//     }
// };

class TrieNode {
    public:
    char ch;
    unordered_map<char, TrieNode*> next;
    bool isEnd;

    TrieNode(char ch){
        this->ch = ch;
        this->isEnd = false;
    }
    bool hasNextLetter(char chr) {
    return next.find(chr) != next.end();
  }
};

class WordDictionary
{
public:
    TrieNode* root;
    WordDictionary()
    {
        root = new TrieNode(0);
    }

    void addWord(string word)
    {
        TrieNode* ptr = root;
        for(int i=0; i<word.length(); i++){
            if(!ptr->hasNextLetter(word[i])){
                ptr->next[word[i]] = new TrieNode(word[i]);
            }
            ptr = ptr->next[word[i]];
        }

        ptr->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode* tempTrie = root;
        return helper(word, tempTrie, 0);
    }

    bool helper(string word, TrieNode* root, int idx){
        TrieNode* ptr = root;

        for(int i=idx; i<word.length(); i++){
            if(word[i] == '.'){
                // then we will explore all the possibilities (a - z)
                unordered_map<char, TrieNode*>* tempMap = &ptr->next;
                for(auto it: *tempMap){
                    if(helper(word, it.second, i+1)) return true;
                }
                return false;
            } else {
                if(!ptr->hasNextLetter(word[i])) return false;
                ptr = ptr->next[word[i]];
            }
        }

        return ptr->isEnd;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    WordDictionary wd;

    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("pad");
    wd.addWord("pqw");

    return 0;
}