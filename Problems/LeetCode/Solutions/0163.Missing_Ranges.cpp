class Solution {
public:
    pair<int,int> findIntersection(int s, int e, int l, int r) {
        return make_pair( max(s,l) , min(e,r) );
    }
    void dealRange(int s, int e, int l, int r, vector<vector<int>>& ans) {
        pair<int,int> p = findIntersection(s,e,l,r);
        if( p.first <= p.second )
            ans.push_back({p.first,p.second});
    }
    vector<vector<int>> findMissingRanges(vector<int>& ar, int lower, int upper) {
        int n = ar.size();
        vector<vector<int>> ans;
        if(n == 0)
            ans.push_back({lower,upper});
        else {
            if(ar[0] != INT_MIN)
                dealRange(INT_MIN, ar[0]-1, lower, upper, ans);
            for( int i = 0 ; i < n-1 ; i++ )
                if( ar[i] != ar[i+1] )
                    dealRange(ar[i]+1, ar[i+1]-1, lower, upper, ans);
            if(ar[n-1] != INT_MAX)
                dealRange(ar[n-1]+1, INT_MAX, lower, upper, ans);
        }
        return ans;
    }
};
