class Solution {
public:
    vector<int> targetIndices(vector<int>& ar, int target) {
        vector<int> ans;
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] == target)
                ans.push_back(i);
        return ans;
    }
};
