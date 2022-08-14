#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

class Trie {
    public:
    Trie* children[ALPHABET_SIZE];
    bool isEndOfWord;

    Trie(){
        for(int i=0; i<ALPHABET_SIZE; i++){
            this->children[i] = NULL;
        }
        this->isEndOfWord = false;
    }
};

void insert(Trie* root, string key){
    Trie* temp = root;

    for(int i=0; i<key.length(); i++){
        // expecting only lowercase letters in the string
        int idx = key[i] - 'a';
        if(!temp->children[idx]){
            temp->children[idx] = new Trie();
        }
        temp = temp->children[idx];
    }

    temp->isEndOfWord = true;
}


bool search(Trie* root, string key){
    Trie* temp = root;
    for(int i=0; i<key.length(); i++){
        int idx = key[i] - 'a';
        if(!temp->children[idx]) return false;

        temp = temp->children[idx];
    }
    return (temp->isEndOfWord);
}


// class TrieNode {
//         public:
//         TrieNode* children[26];
//         bool isEnd;
        
//         TrieNode(){
//             for(int i=0; i<26; i++){
//                 this->children[i] = NULL;
//             }
//             this->isEnd = false;
//         }
//     };

// class Trie {
// public:
//     TrieNode* root;
//     Trie() {
//         TrieNode* p = new TrieNode();
//         this->root = p;
//     }
    
//     void insert(string word) {
//         TrieNode* temp = root;
//         for(int i=0; i<word.length(); i++){
//             int idx = word[i] - 'a';
//             if(!temp->children[idx]){
//                 temp->children[idx] = new TrieNode();
//             }
//             temp = temp->children[idx];
//         }
        
//         temp->isEnd = true;
//     }
    
//     bool search(string word) {
//         TrieNode* temp = root;
//         for(int i=0; i<word.length(); i++){
//             int idx = word[i] - 'a';
//             if(!temp->children[idx]) return false;
//             temp = temp->children[idx];
//         }
        
//         return (temp->isEnd);
//     }
    
//     bool startsWith(string prefix) {
//         TrieNode* temp = root;
//         for(int i=0; i<prefix.length(); i++){
//             int idx = prefix[i] - 'a';
//             if(!temp->children[idx]) return false;
//             temp = temp->children[idx];
//         }
        
//         return true;
//     }
// };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<string> vec = {"hit", "hot", "dot", "dog", "cog"};
    Trie* root = new Trie();

    for(int i=0; i<vec.size(); i++){
        insert(root, vec[i]);
    }

    if(search(root, "cog")) cout<<"YES"<<"\n"; else cout<<"NO"<<"\n"; 
    return 0;
}