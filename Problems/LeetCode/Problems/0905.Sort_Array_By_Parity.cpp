class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans,odd;
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i]%2)
                odd.push_back(ar[i]);
            else
                ans.push_back(ar[i]);
        }
        ans.insert(ans.end(),odd.begin(),odd.end());
        return ans;
    }
};