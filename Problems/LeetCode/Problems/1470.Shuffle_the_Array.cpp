class Solution {
public:
    vector<int> shuffle(vector<int>& ar, int n) {
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            ans.push_back(ar[i]);
            ans.push_back(ar[i+n]);
        }
        return ans;
    }
};