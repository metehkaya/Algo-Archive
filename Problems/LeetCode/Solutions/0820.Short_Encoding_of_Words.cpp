class TrieNode {
public:
    TrieNode* nxt[26];
    TrieNode() {
        for( int i = 0 ; i < 26 ; i++ )
            nxt[i] = NULL;
    }
};

class Solution {
public:
    void solve(TrieNode* node , int& ans , int lvl) {
        bool isLeaf = true;
        for( int i = 0 ; i < 26 ; i++ )
            if(node->nxt[i]) {
                isLeaf = false;
                solve(node->nxt[i],ans,lvl+1);
            }
        if(isLeaf)
            ans += lvl+1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode();
        for( int i = 0 ; i < n ; i++ ) {
            TrieNode* curr = root;
            int len = words[i].length();
            for( int j = len-1 ; j >= 0 ; j-- ) {
                int c = words[i][j]-'a';
                if(curr->nxt[c] == NULL)
                    curr->nxt[c] = new TrieNode();
                curr = curr->nxt[c];
            }
        }
        int ans = 0;
        solve(root,ans,0);
        return ans;
    }
};