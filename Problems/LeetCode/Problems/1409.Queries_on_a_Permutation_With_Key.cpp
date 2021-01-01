class Solution {
public:
    vector<int> processQueries(vector<int>& q, int n) {
        vector<int> ans;
        int m = q.size();
        vector<int> curr(n);
        for( int i = 0 ; i < n ; i++ )
            curr[i] = i+1;
        for( int k = 0 ; k < m ; k++ ) {
            vector<int> v;
            v.push_back(q[k]);
            for( int i = 0 ; i < n ; i++ ) {
                if( curr[i] != q[k] )
                    v.push_back(curr[i]);
                else
                    ans.push_back(i);
            }
            curr = v;
        }
        return ans;
    }
};