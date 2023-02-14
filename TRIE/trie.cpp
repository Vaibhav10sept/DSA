#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isTerminal;
    char data;
    vector<TrieNode*> children;

    TrieNode(char ch) {
        data = ch;
        children.resize(26, NULL);
        isTerminal = false;
    }

    TrieNode() {
        children.resize(26, NULL);
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insertUtil(TrieNode* node, string word) {
        //base case
        if (word.size() == 0) {
            node->isTerminal = true;
            return;
        }

        //assuming the word is in caps
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if (node->children[index] != NULL) {
            child = node->children[index];
        }
        else { //absent
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* node, string word) {
        //base case
        if (word.size() == 0) {
            return node->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (node->children[index] != NULL) { //present
            child = node->children[index];
        }
        else { //absent
            return false;
        }

        //recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};



int main() {
    /*
    TIME COMPLEXITY:
    --> insert = length of word
    --> search = length of word
    --> remove = length of word

    WHY NOT MAP
    --> coz map me space jyada lgti h, baki time complexity map ki average case me same as trie.

    BENEFIT OF TRIE DS:
    --> space optimization
    --> help in suggestion algo

    NOTE: this is the implementation class of trie data structure
    VIDEO LINK: https://www.youtube.com/watch?v=Y6dOuGjwsxU
    LEETCODE LINK:
    */
    Trie obj;
    obj.insertWord("abcd");
    obj.insertWord("time");
    obj.insertWord("vaibhav");

    bool ans = obj.searchWord("time");
    if (ans) cout << "true";
    else cout << "false";
}
