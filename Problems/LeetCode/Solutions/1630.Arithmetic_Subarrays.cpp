class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& ar, vector<int>& l, vector<int>& r) {
        int n = ar.size();
        int m = l.size();
        vector<bool> ans(m,true);
        for( int i = 0 ; i < m ; i++ ) {
            int x = l[i];
            int y = r[i];
            vector<int> v;
            for( int j = x ; j <= y ; j++ )
                v.push_back(ar[j]);
            sort(v.begin(),v.end());
            int len = v.size();
            int diff = v[1]-v[0];
            for( int j = 2 ; j < len ; j++ )
                if(v[j]-v[j-1] != diff)
                    ans[i] = false;
        }
        return ans;
    }
};