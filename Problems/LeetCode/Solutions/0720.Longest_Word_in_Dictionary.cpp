class TrieNode {
public:
    bool var;
    vector<TrieNode*> children;
    TrieNode() {
        var = false;
        children.resize(26,NULL);
    }
};

class Solution {
public:
    int n,maxdepth;
    string ans;
    void update(TrieNode* node , string& s , int lvl , int len) {
        if(lvl == len) {
            node->var = true;
            return;
        }
        int c = s[lvl]-'a';
        if(node->children[c] == NULL)
            node->children[c] = new TrieNode();
        update(node->children[c],s,lvl+1,len);
    }
    void query(TrieNode* node , string& curr , int lvl) {
        if(lvl > maxdepth) {
            maxdepth = lvl;
            ans = curr;
        }
        for( int i = 0 ; i < 26 ; i++ )
            if(node->children[i] != NULL && node->children[i]->var) {
                char c = 'a'+i;
                curr.push_back(c);
                query(node->children[i],curr,lvl+1);
                curr.pop_back();
            }
    }
    string longestWord(vector<string>& ar) {
        n = ar.size();
        TrieNode* root = new TrieNode();
        for( int i = 0 ; i < n ; i++ ) {
            string s = ar[i];
            int len = s.length();
            update(root,s,0,len);
        }
        string curr = "";
        query(root,curr,0);
        return ans;
    }
};