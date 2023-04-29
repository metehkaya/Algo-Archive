struct TrieNode {
    int cnt;
    TrieNode *left;
    TrieNode *right;
    TrieNode() {
        cnt = 0;
        left = right = NULL;
    }
};

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& ar, int k) {
        int n = ar.size();
        int m = ar[0].size();
        TrieNode* root = new TrieNode();
        vector<TrieNode*> rows;
        vector<int> cntR(n,0);
        vector<int> cntC(m,0);
        for( int i = 0 ; i < n ; i++ ) {
            TrieNode* node = root;
            for( int j = 0 ; j < m ; j++ ) {
                if(ar[i][j] == 'B') {
                    cntR[i]++,cntC[j]++;
                    if(node->right == NULL)
                        node->right = new TrieNode();
                    node = node->right;
                }
                else {
                    if(node->left == NULL)
                        node->left = new TrieNode();
                    node = node->left;
                }
            }
            node->cnt++;
            rows.push_back(node);
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                if(ar[i][j] == 'B' && cntR[i] == k && cntC[j] == k && rows[i]->cnt == k)
                    ans++;
        return ans;
    }
};