class Solution {
public:
    vector<int> findBall(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int r = 0 , c = i;
            while(r != n) {
                if(ar[r][c] == 1) {
                    if(c == m-1 || ar[r][c+1] == -1)
                        break;
                    c++;
                }
                else {
                    if(c == 0 || ar[r][c-1] == 1)
                        break;
                    c--;
                }
                r++;
            }
            if(r == n)
                ans.push_back(c);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};