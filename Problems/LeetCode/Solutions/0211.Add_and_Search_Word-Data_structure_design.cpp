class Node {
public:
    bool isWord;
    vector<Node*> child;
    Node() {
        isWord = false;
        child.resize(26,NULL);
    }
}*root;

class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }
    void addWord(string word) {
        Node* node = root;
        int len = word.length();
        for( int i = 0 ; i < len ; i++ ) {
            int c = word[i]-'a';
            if(node->child[c] == NULL)
                node->child[c] = new Node();
            node = node->child[c];
        }
        node->isWord = true;
    }
    bool find(Node* node , int idx , int len , string& word) {
        if(idx == len)
            return node->isWord;
        if(word[idx] == '.') {
            for( int i = 0 ; i < 26 ; i++ )
                if(node->child[i] && find(node->child[i],idx+1,len,word))
                    return true;
        }
        else {
            int c = word[idx]-'a';
            if(node->child[c] && find(node->child[c],idx+1,len,word))
                return true;
        }
        return false;
    }
    bool search(string word) {
        int len = word.length();
        return find(root,0,len,word);
    }
};