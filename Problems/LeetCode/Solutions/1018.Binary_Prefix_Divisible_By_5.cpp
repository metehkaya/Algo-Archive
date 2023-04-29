class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& ar) {
        int n = ar.size();
        vector<bool> ans;
        for( int i = 0 , val = 0 ; i < n ; i++ ) {
            val = 2*val + ar[i];
            val %= 5;
            ans.push_back(val == 0);
        }
        return ans;
    }
};