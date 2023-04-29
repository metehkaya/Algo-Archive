class TrieNode {
public:
    bool var;
    TrieNode* nxt[26];
    TrieNode() {
        var = false;
        for( int i = 0 ; i < 26 ; i++ )
            nxt[i] = NULL;
    }
    void update(string& s , int idx) {
        if(idx == s.length()) {
            var = true;
            return;
        }
        int c = s[idx]-'a';
        if(nxt[c] == NULL)
            nxt[c] = new TrieNode();
        nxt[c]->update(s,idx+1);
    }
    bool query(string& s , int idx , bool used) {
        if(idx == s.length())
            return var && used;
        int c = s[idx]-'a';
        bool res;
        if(!used) {
            if(nxt[c] != NULL)
                res = nxt[c]->query(s,idx+1,false);
            for( int i = 0 ; i < 26 && !res ; i++ )
                if(i != c && nxt[i] != NULL)
                    res = nxt[i]->query(s,idx+1,true);
        }
        else {
            if(nxt[c] == NULL)
                res = false;
            else
                res = nxt[c]->query(s,idx+1,true);
        }
        return res;
    }
};

class MagicDictionary {
public:
    TrieNode* root;
    MagicDictionary() {
        root = new TrieNode();
    }
    void buildDict(vector<string> dict) {
        int n = dict.size();
        for( int i = 0 ; i < n ; i++ )
            root->update(dict[i],0);
    }
    bool search(string word) {
        return root->query(word,0,false);
    }
};