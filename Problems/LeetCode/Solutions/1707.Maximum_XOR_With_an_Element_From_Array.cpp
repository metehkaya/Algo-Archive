class TrieNode {
public:
    TrieNode* child[2];
    int minVal;
    TrieNode() {
        child[0] = NULL;
        child[1] = NULL;
        minVal = INT_MAX;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& ar, vector<vector<int>>& q) {
        int n = ar.size();
        TrieNode* root = new TrieNode();
        for( int i = 0 ; i < n ; i++ ) {
            TrieNode* curr = root;
            curr->minVal = min(curr->minVal,ar[i]);
            for( int j = 29 ; j >= 0 ; j-- ) {
                int way = (ar[i] & (1<<j)) > 0;
                if(curr->child[way] == NULL)
                    curr->child[way] = new TrieNode();
                curr = curr->child[way];
                curr->minVal = min(curr->minVal,ar[i]);
            }
        }
        vector<int> ans;
        n = q.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(root->minVal > q[i][1])
                ans.push_back(-1);
            else {
                int res = 0;
                TrieNode* curr = root;
                for( int j = 29 ; j >= 0 ; j-- ) {
                    int way = (q[i][0] & (1<<j)) == 0;
                    if(curr->child[way] == NULL || curr->child[way]->minVal > q[i][1])
                        way = !way;
                    else
                        res |= (1<<j);
                    curr = curr->child[way];
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};