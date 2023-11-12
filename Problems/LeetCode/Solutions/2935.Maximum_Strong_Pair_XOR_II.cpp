class TrieNode {
public:
    int cnt;
    TrieNode *child[2];
    TrieNode() {
        cnt = 0;
        child[0] = child[1] = NULL;
    }
}*root;

void update(int val , int add) {
    TrieNode* node = root;
    node->cnt += add;
    for( int k = 19 ; k >= 0 ; k-- ) {
        int way = ((val & (1<<k)) > 0);
        if(node->child[way] == NULL)
            node->child[way] = new TrieNode();
        node = node->child[way];
        node->cnt += add;
    }
}

int query(int val) {
    int res = 0;
    TrieNode* node = root;
    for( int k = 19 ; k >= 0 ; k-- ) {
        int way = ((val & (1<<k)) > 0);
        if(node->child[!way] != NULL and node->child[!way]->cnt > 0) {
            res += (1<<k);
            node = node->child[!way];
        }
        else
            node = node->child[way];
    }
    return res;
}

class Solution {
public:
    int maximumStrongPairXor(vector<int>& v) {
        root = new TrieNode();
        int n = v.size() , ans = 0;
        sort(v.begin(),v.end());
        for( int l = 0 , r = 0 ; l < n ; l++ ) {
            while(r < n and v[r] <= 2*v[l])
                update(v[r++],+1);
            ans = max(ans,query(v[l]));
            update(v[l],-1);
        }
        return ans;
    }
};
