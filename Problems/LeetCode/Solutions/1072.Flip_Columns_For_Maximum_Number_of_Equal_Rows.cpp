class Node {
public:
    int cnt;
    Node* nxt[2];
    Node() {
        cnt = 0;
        nxt[0] = nxt[1] = NULL;
    }
};

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& ar) {
        Node* root = new Node();
        int n = ar.size() , m = ar[0].size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int k = 0 ; k < 2 ; k++ ) {
                Node* node = root;
                for( int j =  0 ; j < m ; j++ ) {
                    int w = (ar[i][j]^k);
                    if(node->nxt[w] == NULL)
                        node->nxt[w] = new Node();
                    node = node->nxt[w];
                }
                node->cnt++;
                ans = max(ans,node->cnt);
            }
        return ans;
    }
};