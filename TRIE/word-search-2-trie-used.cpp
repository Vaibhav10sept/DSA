#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isTerminal;
    char data;
    string endWord;
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

void insertTrieNode(string word, TrieNode* root) {
    TrieNode* currNode;
    currNode = root;
    string originalWord = word;

    for (char ch : word) {
        int index = ch - 'a'; //this is clear that all char are in lower case
        if (currNode->children[index] == NULL) {
            //create new node and insert
            TrieNode* newNode = new TrieNode(ch);
            currNode->children[index] = newNode;
        }
        currNode = currNode->children[index];
    }

    //mark the end node as terminal
    //and store the whole word(ye hm trie ki implementation me nhi krte the, WV, think, why we are saving the whole word at the last node of trie for that word(optimize kr dega))
    currNode->isTerminal = true;
    currNode->endWord = originalWord;
}

vector<string> wordSearch(vector<vector<char>> arr, vector<string> words) {
    //WV recommended
    TrieNode* root = new TrieNode();
    for (string word : words) {
        insertTrieNode(word, root);
    }

    vector<string> ans;
    return ans;
}



int main() {
    /*
    NOTE: for understanding trie please refer to the trie.cpp
    VIDEO LINK: https://www.youtube.com/watch?v=EmvsBM7o-5k
    LEETCODE LINK: https://leetcode.com/problems/word-search-ii/description/
    */
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> ans = wordSearch(board, words);
}
