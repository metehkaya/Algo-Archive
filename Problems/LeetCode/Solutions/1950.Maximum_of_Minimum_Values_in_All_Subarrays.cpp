class Solution {
public:
    int find(int u , vector<int>& dad) {
        if(u == dad[u])
            return u;
        return dad[u] = find(dad[u],dad);
    }
    int merge(int u , int v , vector<int>& cnt , vector<int>& dad , vector<int>& rank) {
        u = find(u,dad);
        v = find(v,dad);
        if(rank[u] < rank[v])
            swap(u,v);
        dad[v] = u;
        cnt[u] += cnt[v];
        if(rank[u] == rank[v])
            rank[u]++;
        return cnt[u];
    }
    vector<int> findMaximums(vector<int>& v) {
        int n = v.size();
        vector<int> cnt(n,0),dad(n,-1),rank(n,-1);
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[v[i]].push_back(i);
        vector<int> ans(n);
        int last_len = 0;
        for( auto it = mp.rbegin() ; it != mp.rend() ; it++ ) {
            int len = max(last_len,1);
            for(int idx : it->second) {
                cnt[idx] = 1;
                dad[idx] = idx;
                rank[idx] = 0;
                if(idx-1 >= 0 and cnt[idx-1])
                    len = max(len,merge(idx,idx-1,cnt,dad,rank));
                if(idx+1 < n and cnt[idx+1])
                    len = max(len,merge(idx,idx+1,cnt,dad,rank));
            }
            for( int i = last_len+1 ; i <= len ; i++ )
                ans[i-1] = it->first;
            last_len = len;
        }
        return ans;
    }
};
