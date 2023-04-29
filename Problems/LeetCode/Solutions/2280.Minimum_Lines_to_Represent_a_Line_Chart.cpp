typedef long long LL;

class Solution {
public:
    int minimumLines(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = 0 , j ; i < n-1 ; i = j-1 ) {
            ans++;
            j = i+1;
            int dx1 = ar[j][0]-ar[i][0];
            int dy1 = ar[j][1]-ar[i][1];
            j++;
            while(j < n) {
                int dx2 = ar[j][0]-ar[i][0];
                int dy2 = ar[j][1]-ar[i][1];
                if((LL)dy1*dx2 != (LL)dy2*dx1)
                    break;
                j++;
            }
        }
        return ans;
    }
};
