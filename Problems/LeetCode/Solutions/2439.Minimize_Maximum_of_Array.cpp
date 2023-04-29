class Solution {
public:
    int minimizeArrayValue(vector<int>& v) {
        int n = v.size() , ans = 0;
        long long sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += v[i];
            int x = (sum + i) / (i+1);
            ans = max(ans,x);
        }
        return ans;
    }
};
