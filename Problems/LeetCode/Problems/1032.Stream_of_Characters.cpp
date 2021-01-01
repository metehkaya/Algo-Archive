class StreamChecker {
public:
    struct Node {
        Node* next[26];
        bool isWord;
        Node() {
            isWord = false;
            memset(next, 0, sizeof(next));
        }
    };
    int nq;
    Node* root;
    vector<char> vc;
    void init(int index, string& word, Node* node) {
        if(index == -1) {
            node->isWord = true;
            return;
        }
        int k = word[index]-'a';
        if(node->next[k] == NULL)
            node->next[k] = new Node();
        init(index-1,word,node->next[k]);
    }
    StreamChecker(vector<string>& words) {
        nq = 0;
        vc.clear();
        root = new Node();
        for( int i = 0 ; i < words.size() ; i++ )
            init(words[i].length()-1, words[i], root);
    }
    bool query(char letter) {
        nq++;
        vc.push_back(letter);
        Node* node = root;
        for( int i = nq-1 ; i >= 0 ; i-- ) {
            int k = vc[i]-'a';
            if(node->next[k] == NULL)
                return false;
            node = node->next[k];
            if(node->isWord)
                return true;
        }
        return false;
    }
};