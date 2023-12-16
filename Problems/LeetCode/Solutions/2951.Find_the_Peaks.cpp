class Solution {
public:
    vector<int> findPeaks(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        for( int i = 1 ; i < n-1 ; i++ )
            if(v[i] > max(v[i-1],v[i+1]))
                ans.push_back(i);
        return ans;
    }
};
