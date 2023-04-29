typedef pair<int,int> pi;

class Solution {
public:
    int n,ans;
    map<pi,int> mp;
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    int maxPoints(vector<vector<int>>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            mp.clear();
            int most = 0;
            for( int j = 0 ; j < n ; j++ )
                if(i != j) {
                    int dx = ar[j][0]-ar[i][0];
                    int dy = ar[j][1]-ar[i][1];
                    if(dy < 0)
                        dx *= -1 , dy *= -1;
                    int g = gcd(abs(dx),abs(dy));
                    dx /= g , dy /= g;
                    most = max(most,++mp[pi(dx,dy)]);
                }
            ans = max(ans,most+1);
        }
        return ans;
    }
};