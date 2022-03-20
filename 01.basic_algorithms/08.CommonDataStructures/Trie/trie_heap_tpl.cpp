#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

typedef struct TrieNode
{
    int cnt;
    struct TrieNode* chars[26];

    TrieNode()
        : cnt(0), chars{0} {}
} t_trie_node;

t_trie_node* root = nullptr;

void init() {
    root = new t_trie_node;
}

void insert(t_trie_node* root, const string& str) {
    t_trie_node* p = root;

    for (auto ch : str) {
        int u = ch - 'a';
        if (!p->chars[u]) {
            p->chars[u] = new t_trie_node;
        }

        p = p->chars[u];
    }

    p->cnt++;
}

int query(t_trie_node* root, const string& str) {
    t_trie_node* p = root;
    
    for (auto ch : str) {
        int u = ch - 'a';
        if (!p->chars[u]) {
            return 0;
        }
        p = p->chars[u];
    }

    return p->cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 别忘了初始化
    init();

    int n; cin >> n;
    while (n --) {
        char op; string str;
        cin >> op >> str;

        if (op == 'I') {
            insert(root, str);
        } else {
            cout << query(root, str) << endl;
        }
    }

    return 0;
}