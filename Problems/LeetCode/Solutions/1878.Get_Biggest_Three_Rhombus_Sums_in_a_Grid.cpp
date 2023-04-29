class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int k = (min(n,m)-1) / 2;
        set<int> myset;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                myset.insert(ar[i][j]);
        for( int l = 1 ; l <= k ; l++ )
            for( int i = 0 ; i+2*l < n ; i++ )
                for( int j = l ; j < m-l ; j++ ) {
                    int sum = 0;
                    for( int t = 0 ; t < l ; t++ ) {
                        sum += ar[i+t][j+t];
                        sum += ar[i+l+t][j+l-t];
                        sum += ar[i+2*l-t][j-t];
                        sum += ar[i+l-t][j-l+t];
                    }
                    myset.insert(sum);
                }
        vector<int> total(myset.begin(), myset.end());
        reverse(total.begin(),total.end());
        vector<int> ans;
        n = min((int)total.size(),3);
        for( int i = 0 ; i < n ; i++ )
            ans.push_back(total[i]);
        return ans;
    }
};