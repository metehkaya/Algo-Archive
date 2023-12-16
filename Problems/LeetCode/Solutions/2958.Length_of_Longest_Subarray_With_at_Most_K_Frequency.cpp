class Solution {
public:
    int maxSubarrayLength(vector<int>& v, int k) {
        int n = v.size() , ans = 0;
        map<int,int> mp;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < n and mp[v[j]] < k)
                mp[v[j++]]++;
            ans = max(ans,j-i);
            mp[v[i]]--;
        }
        return ans;
    }
};
