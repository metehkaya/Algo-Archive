class Solution {
public:
    long long countSubarrays(vector<int>& v) {
        int n = v.size();
        long long ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            j = i+1;
            ans++;
            while(j < n and v[j-1] < v[j])
                ans += ++j - i;
        }
        return ans;
    }
};
