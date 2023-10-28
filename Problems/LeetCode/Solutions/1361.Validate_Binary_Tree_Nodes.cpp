class Solution {
public:
    bool dfs(int u , int& cnt , vector<int>& l , vector<int>& r , vector<bool>& mark) {
        if(mark[u])
            return false;
        cnt++;
        mark[u] = true;
        if(l[u] != -1 and !dfs(l[u],cnt,l,r,mark))
            return false;
        if(r[u] != -1 and !dfs(r[u],cnt,l,r,mark))
            return false;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int> cnt_dad(n,0);
        for(int x : l)
            if(x != -1)
                cnt_dad[x] += 1;
        for(int x : r)
            if(x != -1)
                cnt_dad[x] += 1;
        int root = -1;
        for( int i = 0 ; i < n ; i++ )
            if(cnt_dad[i] == 0) {
                if(root != -1)
                    return false;
                root = i;
            }
            else if(cnt_dad[i] == 2)
                return false;
        if(root == -1)
            return false;
        int cnt = 0;
        vector<bool> mark(n,false);
        if(!dfs(root,cnt,l,r,mark))
            return false;
        return cnt == n;
    }
};
