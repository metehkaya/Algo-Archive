class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n = v.size() , mx = 0 , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && v[i] == v[j])
                j++;
            if(v[i] > mx) {
                mx = v[i];
                ans = j-i;
            }
            else if(v[i] == mx)
                ans = max(ans,j-i);
        }
        return ans;
    }
};
