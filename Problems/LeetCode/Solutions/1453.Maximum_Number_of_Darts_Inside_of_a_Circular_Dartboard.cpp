typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<double,double> pd;
typedef pair<pd,pd> ppd;

class Solution {
public:
    const double eps = 1e-6;
    const ppd INVALID = ppd( pd(0,0) , pd(0,0) );
    ppd getCenters(vector<int>& p1, vector<int>& p2, int r) {
        double dx = p2[0] - p1[0];
        double dy = p2[1] - p1[1];
        double d = sqrt(dx*dx + dy*dy);
        if(d > r*2.0)
            return INVALID;
        double dist = sqrt(r*r - d*d/4.0);
        double midX = (p1[0] + p2[0]) / 2.0;
        double midY = (p1[1] + p2[1]) / 2.0;
        pd c1 = pd( midX + dist * dy / d , midY - dist * dx / d );
        pd c2 = pd( midX - dist * dy / d , midY + dist * dx / d );
        return ppd(c1,c2);
    }
    int f(pd center, vvi& ar, double r) {
        int cnt = 0;
        double cx = center.first;
        double cy = center.second;
        for( int i = 0 ; i < ar.size() ; i++ ) {
            double dx = ar[i][0] - cx;
            double dy = ar[i][1] - cy;
            cnt += dx*dx+dy*dy <= r*r + eps;
        }
        return cnt;
    }
    int numPoints(vvi& ar, int r) {
        int n = ar.size();
        if(n == 1)
            return 1;
        int ans = 1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                ppd centers = getCenters(ar[i], ar[j], r);
                if( centers == INVALID )
                    continue;
                ans = max( ans , f(centers.first, ar, r) );
                ans = max( ans , f(centers.second, ar, r) );
            }
        return ans;
    }
};