class Solution {
public:
    int closestToTarget(vector<int>& ar, int t) {
        int n = ar.size();
        int ans = INT_MAX;
        set<int> old;
        for( int i = 0 ; i < n ; i++ ) {
            set<int> curr;
            curr.insert(ar[i]);
            for(auto x : old)
                curr.insert(ar[i]&x);
            for(auto x : curr)
                ans = min( ans , abs(x-t) );
            old = curr;
        }
        return ans;
    }
};