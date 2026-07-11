#include <bits/stdc++.h>
using namespace std;

class Trie {
    public:
        struct TrieNode {
            bool isEnd;
            TrieNode* children[26];
        };

        TrieNode* getNode() {
            TrieNode* newNode = new TrieNode();
            newNode->isEnd = false;
            for(int i = 0 ; i < 26 ; i++) {
                newNode->children[i] = NULL;
            }
            return newNode;
        }

        TrieNode* root;

        Trie() {
            root = getNode();
        }

        void insert(string word) {
            TrieNode* node = root;
            for(int i = 0 ; i < word.size() ; i++) {
                char ch = word[i];
                int idx = ch - 'a';
                if(node->children[idx] == NULL) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
        }

        bool search(string word) {
            TrieNode* node = root;
            for(int i = 0 ; i < word.size() ; i++) {
                char ch = word[i];
                int idx = ch - 'a';
                if(node->children[idx] == NULL) {
                    return false;
                }
                node = node->children[idx];
            }
            if(node != NULL && node->isEnd == true) return true;
            return false;
        }

        bool startsWith(string prefix) {
            TrieNode* node = root;
            int i = 0;
            for(; i < prefix.size() ; i++) {
                char ch = prefix[i];
                int idx = ch - 'a';
                if(node->children[idx] == NULL) {
                    return false;
                }
                node = node->children[idx];
            }
            if(i == prefix.length()) return true;
            return false;
        }
};