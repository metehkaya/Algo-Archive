typedef pair<int,int> pi;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& ar) {
        int n = ar.size();
        double ans = INT_MAX;
        set<pi> s;
        for( int i = 0 ; i < n ; i++ )
            s.insert(pi(ar[i][0],ar[i][1]));
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                for( int k = 0 ; k < n ; k++ )
                    if(i != j && i != k && j != k) {
                        int x1 = ar[j][0] - ar[i][0];
                        int y1 = ar[j][1] - ar[i][1];
                        int x2 = ar[k][0] - ar[i][0];
                        int y2 = ar[k][1] - ar[i][1];
                        if(x1*x2 != -y1*y2)
                            continue;
                        int a = x1*x1+y1*y1;
                        int b = x2*x2+y2*y2;
                        double area = sqrt((double)a*b);
                        int x = ar[i][0] + x1 + x2;
                        int y = ar[i][1] + y1 + y2;
                        if(s.find(pi(x,y)) != s.end())
                            ans = min(ans,area);
                    }
        return (ans == INT_MAX) ? 0 : ans;
    }
};