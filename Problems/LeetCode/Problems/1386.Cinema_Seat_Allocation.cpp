class Solution {
public:
    int f(int l, int r) {
        int len = r-l+1;
        if(len < 4)
            return 0;
        if(l <= 2 && r >= 9)
            return 2;
        if(l <= 4 && r >= 7)
            return 1;
        if(l <= 2 && r >= 5)
            return 1;
        if(l <= 6 && r >= 9)
            return 1;
        return 0;
    }
    int maxNumberOfFamilies(int m, vector<vector<int>>& ar) {
        int n = ar.size();
        sort( ar.begin() , ar.end() );
        int ans = 0;
        int rem = m;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            rem--;
            while(j < n && ar[i][0] == ar[j][0])
                j++;
            for( int k = i ; k < j-1 ; k++ )
                ans += f( ar[k][1] + 1 , ar[k+1][1] - 1 );
            ans += f( 1 , ar[i][1] - 1 );
            ans += f( ar[j-1][1] + 1 , 10 );
        }
        ans += 2 * rem;
        return ans;
    }
};