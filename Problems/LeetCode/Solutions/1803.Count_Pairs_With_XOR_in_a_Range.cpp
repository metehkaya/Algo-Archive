struct TrieNode {
    int cnt;
    TrieNode* nxt[2];
    TrieNode() {
        cnt = 0;
        nxt[0] = nxt[1] = NULL;
    }
}*root;

class Solution {
public:
    void update(TrieNode* node , int val , int k) {
        node->cnt++;
        if(k == -1)
            return;
        int way = ((val & (1<<k)) > 0);
        if(node->nxt[way] == NULL)
            node->nxt[way] = new TrieNode();
        update(node->nxt[way],val,k-1);
    }
    int query(TrieNode* node , int val , int sum , int mx , int k) {
        if(node == NULL)
            return 0;
        if(node->cnt == 0)
            return 0;
        if(k == -1)
            return node->cnt;
        if(sum + 2*(1<<k)-1 <= mx)
            return node->cnt;
        int way = ((val & (1<<k)) > 0);
        int res = 0;
        if(mx < sum+(1<<k))
            res = query(node->nxt[way],val,sum,mx,k-1);
        else {
            if(node->nxt[way] != NULL)
                res += node->nxt[way]->cnt;
            res += query(node->nxt[!way],val,sum+(1<<k),mx,k-1);
        }
        return res;
    }
    int countPairs(vector<int>& ar, int low, int high) {
        int ans = 0;
        int n = ar.size();
        root = new TrieNode();
        for( int i = 0 ; i < n ; i++ ) {
            ans += query(root,ar[i],0,high,14);
            if(low)
                ans -= query(root,ar[i],0,low-1,14);
            update(root,ar[i],14);
        }
        return ans;
    }
};