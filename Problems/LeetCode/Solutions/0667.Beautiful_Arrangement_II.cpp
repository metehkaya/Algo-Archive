class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int val = 1;
        ans.push_back(val);
        for( int diff = k , mult = 1 ; diff >= 1 ; diff-- , mult *= -1 ) {
            val += diff*mult;
            ans.push_back(val);
        }
        for( int i = k+2 ; i <= n ; i++ )
            ans.push_back(i);
        return ans;
    }
};