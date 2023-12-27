class Solution {
public:
    const int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        unordered_map<int,int> mp;
        n = h.size() , m = v.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                mp[h[j]-h[i]] |= 1;
        for( int i = 0 ; i < m ; i++ )
            for( int j = i+1 ; j < m ; j++ )
                mp[v[j]-v[i]] |= 2;
        int ans = -1;
        for(auto it : mp)
            if(it.second == 3)
                ans = max(ans,it.first);
        if(ans == -1)
            return -1;
        ans = (long long) ans * ans % mod;
        return ans;
    }
};
