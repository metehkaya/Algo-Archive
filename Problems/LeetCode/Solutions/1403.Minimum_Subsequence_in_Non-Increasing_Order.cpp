class Solution {
public:
    vector<int> minSubsequence(vector<int>& ar) {
        int n = ar.size();
        int sum = 0;
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        sort( ar.begin() , ar.end() );
        vector<int> ans;
        int curr = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            curr += ar[i];
            ans.push_back(ar[i]);
            if(curr > sum-curr)
                break;
        }
        return ans;
    }
};