class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        vector<int> v(n);
        for( int i = 0 ; i < n ; i++ )
            v[i] = i;
        vector<int> idx;
        idx.push_back(0);
        v.erase(v.begin());
        for( int i = 1 ; i < n ; i++ ) {
            int val = v[0];
            v.erase(v.begin());
            v.push_back(val);
            idx.push_back(v[0]);
            v.erase(v.begin());
        }
        vector<int> ans(n);
        for( int i = 0 ; i < n ; i++ )
            ans[idx[i]] = ar[i];
        return ans;
    }
};