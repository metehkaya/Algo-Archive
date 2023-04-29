class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        vector<vector<int>> ans;
        vector<int> v(2);
        v[0] = ar[0] , v[1] = ar[1];
        ans.push_back(v);
        int best = ar[1] - ar[0];
        for( int i = 2 ; i < n ; i++ ) {
            v[0] = ar[i-1] , v[1] = ar[i];
            int diff = ar[i] - ar[i-1];
            if(diff < best) {
                best = diff;
                ans.clear();
                ans.push_back(v);
            }
            else if(diff == best)
                ans.push_back(v);
        }
        return ans;
    }
};