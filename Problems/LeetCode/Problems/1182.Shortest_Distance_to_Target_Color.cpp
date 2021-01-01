class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& ar, vector<vector<int>>& q) {
        int n = ar.size();
        int m = q.size();
        set<int> ind[3];
        for( int i = 0 ; i < n ; i++ )
            ind[ar[i]-1].insert(i);
        vector<int> ans(m,-1);
        set<int>::iterator sit;
        for( int i = 0 ; i < m ; i++ ) {
            int pos = q[i][0];
            int val = q[i][1]-1;
            sit = ind[val].lower_bound(pos);
            if(sit != ind[val].end())
                ans[i] = (*sit)-pos;
            sit = ind[val].upper_bound(pos);
            if(sit != ind[val].begin()) {
                sit--;
                if( ans[i] == -1 || pos-(*sit) < ans[i] )
                    ans[i] = pos-(*sit);
            }
        }
        return ans;
    }
};