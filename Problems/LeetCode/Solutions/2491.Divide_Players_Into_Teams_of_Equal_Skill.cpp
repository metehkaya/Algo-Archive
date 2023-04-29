class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        int n = v.size();
        long long ans = 0;
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n/2 ; i++ ) {
            if(v[i]+v[n-1-i] != v[0]+v[n-1])
                return -1;
            ans += v[i]*v[n-1-i];
        }
        return ans;
    }
};
