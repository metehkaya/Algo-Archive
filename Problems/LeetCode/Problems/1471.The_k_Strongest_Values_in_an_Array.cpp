class Solution {
public:
    vector<int> getStrongest(vector<int>& ar, int k) {
        int n = ar.size();
        sort( ar.begin() , ar.end() );
        int m = ar[(n-1)/2];
        vector<int> ans;
        int l = 0 , r = n-1;
        for( int i = 0 ; i < k ; i++ ) {
            int lval = abs(ar[l]-m);
            int rval = abs(ar[r]-m);
            if(rval >= lval)
                ans.push_back(ar[r--]);
            else
                ans.push_back(ar[l++]);
        }
        return ans;
    }
};