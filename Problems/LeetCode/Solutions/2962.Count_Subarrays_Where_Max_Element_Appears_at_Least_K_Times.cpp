class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        int n = v.size();
        int mx = *max_element(std::begin(v), std::end(v));
        long long ans = (long long) n*(n+1)/2;
        for( int i = 0 , j = 0 , val = 0 ; i < n ; i++ ) {
            j = max(i,j);
            while(j < n and val+(v[j]==mx) < k)
                val += (v[j++]==mx);
            ans -= j-i;
            if(i < j)
                val -= (v[i]==mx);
        }
        return ans;
    }
};
