#include <bits/stdc++.h>
using namespace std;

class TrieNode {
        public:
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode(){
            for(int i=0; i<26; i++){
                this->children[i] = NULL;
            }
            this->isEnd = false;
        }
    };

class Trie {
public:
    TrieNode* root;
    Trie() {
        TrieNode* p = new TrieNode();
        this->root = p;
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if(!temp->children[idx]){
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if(!temp->children[idx]) return false;
            temp = temp->children[idx];
        }
        
        return (temp->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0; i<prefix.length(); i++){
            int idx = prefix[i] - 'a';
            if(!temp->children[idx]) return false;
            temp = temp->children[idx];
        }
        
        return true;
    }

    void maxMatch(string key){
        TrieNode* temp = root;
        int counter = 0;
        string s = "";
        for(int i=0; i<26; i++){
            if(temp->children[i]){
                cout<<i;
                temp = temp->children[i];
            }
        }
    }
};

class Solution {
public:
    void findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1 form a trie for all the words in the word list
        Trie* tr = new Trie();
        for(int i=0; i<wordList.size(); i++){
            tr->insert(wordList[i]);
        }

        tr->maxMatch("abcd");
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    vector<string> vec = {"HE", "SHE"};
    s.findLadders("", "", vec);

    return 0;
}