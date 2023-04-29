typedef pair<int,int> pi;

class Solution {
public:
    set<pi> s;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    bool check(int x , int y) {
        pi p = pi(x,y);
        return s.find(p) != s.end();
    }
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        int dirid = 0 , ans = 0;
        int n = c.size();
        int m = o.size();
        for( int i = 0 ; i < m ; i++ )
            s.insert(pi(o[i][0],o[i][1]));
        int x = 0 , y = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(c[i] == -1)
                dirid = (dirid+1)%4;
            else if(c[i] == -2)
                dirid = (dirid+3)%4;
            else {
                while(c[i]--) {
                    int x2 = x + dir[dirid][0];
                    int y2 = y + dir[dirid][1];
                    if(check(x2,y2))
                        break;
                    x = x2;
                    y = y2;
                }
            }
            ans = max(ans,x*x+y*y);
        }
        return ans;
    }
};