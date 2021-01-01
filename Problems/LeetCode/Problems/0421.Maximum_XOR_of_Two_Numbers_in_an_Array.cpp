class Node {
public:
    Node* next[2];
    Node() {
        next[0] = NULL;
        next[1] = NULL;
    }
}*root;

class Solution {
public:
    int query(Node* node , int val , int k) {
        if(k == -1)
            return 0;
        int way = (val & (1<<k)) > 0 ? 1 : 0;
        if(node->next[!way])
            return query(node->next[!way],val,k-1) + (1<<k);
        else
            return query(node->next[way],val,k-1);
        return INT_MIN;
    }
    void update(Node* node , int val , int k) {
        if(k == -1)
            return;
        int way = (val & (1<<k)) > 0 ? 1 : 0;
        if(node->next[way] == NULL)
            node->next[way] = new Node();
        update(node->next[way],val,k-1);
    }
    int findMaximumXOR(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        root = new Node();
        for( int i = 0 ; i < n ; i++ ) {
            if(i)
                ans = max( ans , query(root,ar[i],30) );
            update(root,ar[i],30);
        }
        return ans;
    }
};