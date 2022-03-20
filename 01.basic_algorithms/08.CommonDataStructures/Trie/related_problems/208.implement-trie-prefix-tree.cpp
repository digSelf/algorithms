#include <string>
using std::string;

class Trie {
    typedef struct TrieNode {
        int cnt = 0;
        struct TrieNode* chars[26] = {0};
    } t_node; 

    t_node *root;
public:
    Trie() {
        root = new t_node;
    }
    
    void insert(string word) {
        t_node* p = root;
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            int u = word[i] - 'a';
            if (!p->chars[u])
                p->chars[u] = new t_node;
            
            p = p->chars[u];
        }

        p->cnt ++;
    }
    
    bool search(string word) {
        t_node* p = root;
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            int u = word[i] - 'a';
            if (!p->chars[u])
                return false;
            p = p->chars[u];
        }

        return p->cnt != 0;
    }
    
    bool startsWith(string prefix) {
        t_node* p = root;
        int len = prefix.length();
        for (int i = 0; i < len; ++i) {
            int u = prefix[i] - 'a';
            if (!p->chars[u])
                return false;
            p = p->chars[u];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */