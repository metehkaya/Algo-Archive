class Trie {
public:
    bool isEnd;
    bool isVisited;
    vector<Trie*> children;
    Trie() {
        isEnd = false;
        isVisited = false;
        children.resize(26, NULL);
    }
    void insert(string word) {
        Trie* curr = this;
        int len = word.length();
        for( int i = 0 ; i < len ; i++ ) {
            curr->isVisited = true;
            int way = word[i] - 'a';
            if(!curr->children[way])
                curr->children[way] = new Trie();
            curr = curr->children[way];
        }
        curr->isVisited = curr->isEnd = true;
    }
    Trie* searchString(string& word) {
        Trie* curr = this;
        int len = word.length();
        for( int i = 0 ; i < len && curr ; i++ ) {
            int way = word[i] - 'a';
            curr = curr->children[way];
        }
        return curr;
    }
    bool search(string word) {
        Trie* node = searchString(word);
        return node && node->isEnd;
    }
    bool startsWith(string prefix) {
        Trie* node = searchString(prefix);
        return node && node->isVisited;
    }
};