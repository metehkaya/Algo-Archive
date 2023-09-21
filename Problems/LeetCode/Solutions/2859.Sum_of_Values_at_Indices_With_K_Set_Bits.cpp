class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& v, int k) {
        int n = v.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int idx = i , cnt = 0;
            while(idx) {
                cnt++;
                idx -= (idx & (-idx));
            }
            if(cnt == k)
                ans += v[i];
        }
        return ans;
    }
};
