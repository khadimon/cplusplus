/*

Name: <Khadichabonu Valieva>

NetID: <w10118633>

Program Description: < The runtime analysis of Linked List vs Trie data structure >

*/


#ifndef Tries_h
#define Tries_h

#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
class TrieNode {
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode *root;
    int count;

public:
    Trie() {
        root = nullptr;
        count = 0;
    }

    void insert(string word) {
        if(root == nullptr){
            root = new TrieNode();
        }

        TrieNode *node = root;
        if (node == nullptr)
            return;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
       if (node != nullptr)
           node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode *node = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index])
                return false;

            node = node->children[index];
        }

        return node->isEndOfWord;
    }
};



#endif /* Tries_h */
