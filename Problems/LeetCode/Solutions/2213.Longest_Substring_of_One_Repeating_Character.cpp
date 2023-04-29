struct range {
    int l,r,best;
};

class Solution {
public:
    static const int maxn = 100003;
    string s;
    range tree[4*maxn];
    void merge(int l , int r , int m , int id) {
        int lenl = m-l+1;
        int lenr = r-m;
        tree[id].l = tree[2*id].l;
        if(tree[2*id].best == lenl && s[m] == s[m+1])
            tree[id].l += tree[2*id+1].l;
        tree[id].r = tree[2*id+1].r;
        if(tree[2*id+1].best == lenr && s[m] == s[m+1])
            tree[id].r += tree[2*id].r;
        tree[id].best = max(tree[2*id].best,tree[2*id+1].best);
        if(s[m] == s[m+1])
            tree[id].best = max(tree[id].best,tree[2*id].r+tree[2*id+1].l);
    }
    void update(int l , int r , int q , int id) {
        if(r < q || q < l)
            return;
        if(l == r)
            return;
        int m = (l+r) >> 1;
        update(l,m,q,2*id);
        update(m+1,r,q,2*id+1);
        merge(l,r,m,id);
    }
    void build(int l , int r , int id) {
        if(l == r) {
            tree[id].l = tree[id].r = tree[id].best = 1;
            return;
        }
        int m = (l+r) >> 1;
        build(l,m,2*id);
        build(m+1,r,2*id+1);
        merge(l,r,m,id);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.length();
        int m = queryIndices.size();
        build(0,n-1,1);
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            this->s[queryIndices[i]] = queryCharacters[i];
            update(0,n-1,queryIndices[i],1);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};
