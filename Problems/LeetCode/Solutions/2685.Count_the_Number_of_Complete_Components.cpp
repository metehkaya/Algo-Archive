class Solution {
public:
    int find(int x , vector<int>& dad) {
        if(dad[x] == -1)
            return x;
        return dad[x] = find(dad[x],dad);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> dad(n,-1) , rank(n,0) , cnt(n,1) , sum(n,0);
        for(auto& e : edges)
            sum[e[0]]++ , sum[e[1]]++;
        for(auto& e : edges) {
            int x = e[0] , y = e[1];
            x = find(x,dad);
            y = find(y,dad);
            if(x == y)
                continue;
            if(rank[x] < rank[y])
                swap(x,y);
            else if(rank[x] == rank[y])
                rank[x]++;
            dad[y] = x;
            cnt[x] += cnt[y];
            sum[x] += sum[y];
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(dad[i] == -1 and cnt[i]*(cnt[i]-1) == sum[i])
                ans++;
        return ans;
    }
};
