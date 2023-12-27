class Solution {
public:
    vector<int> numberGame(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i += 2 ) {
            ans.push_back(v[i+1]);
            ans.push_back(v[i]);
        }
        return ans;
    }
};
