#include <bits/stdc++.h>
using namespace std;

/*
 * Trie
 * Supports two main operations:
 * - Insert: Adds a word to the trie.
 * - Search: Determines if a word exists in the trie.
 * Time Complexity: O(m) for insert and search, where m is the length of the word.
*/


struct Node {
    Node* links[26];
    bool isEnd = false;
    bool containsKey(char ch) {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node* get(char ch) {
        return links[ch-'a'];
    }
    void setEnd() {
        isEnd = true;
    }
    bool isEnd() {
        return isEnd;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for(auto ch: word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node* node = root;
        for(auto ch: word) {
            if(!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }
};

int main() {
    Trie t; 
    t.insert("hello");
    cout << t.search("hello");
    cout << t.search("world");
    return 0;   
}
