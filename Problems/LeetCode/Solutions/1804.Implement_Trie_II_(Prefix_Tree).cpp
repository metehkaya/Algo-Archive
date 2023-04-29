class Node {
public:
    int cnt_prefix,cnt_word;
    map<char,Node*> next;
    Node() {
        cnt_prefix = cnt_word = 0;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        Node* node = root;
        for(char c : s) {
            node->cnt_prefix++;
            if(node->next.find(c) == node->next.end())
                node->next[c] = new Node();
            node = node->next[c];
        }
        node->cnt_prefix++;
        node->cnt_word++;
    }
    int countWordsEqualTo(string s) {
        Node* node = root;
        for(char c : s) {
            if(node->next.find(c) == node->next.end())
                return 0;
            node = node->next[c];
        }
        return node->cnt_word;
    }
    int countWordsStartingWith(string s) {
        Node* node = root;
        for(char c : s) {
            if(node->next.find(c) == node->next.end())
                return 0;
            node = node->next[c];
        }
        return node->cnt_prefix;
    }
    void erase(string s) {
        Node* node = root;
        for(char c : s) {
            node->cnt_prefix--;
            node = node->next[c];
        }
        node->cnt_prefix--;
        node->cnt_word--;
    }
};
