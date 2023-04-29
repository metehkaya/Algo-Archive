class Solution {
public:
    int minAreaRect(vector<vector<int>>& ar) {
        int n = ar.size();
        set<pair<int,int>> points;
        for( int i = 0 ; i < n ; i++ )
            points.insert(make_pair(ar[i][0],ar[i][1]));
        int ans=0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if( ar[i][0] != ar[j][0] && ar[i][1] != ar[j][1] ) {
                    int x1 = ar[i][0];
                    int y1 = ar[i][1];
                    int x2 = ar[j][0];
                    int y2 = ar[j][1];
                    int area = abs(x1-x2)*abs(y1-y2);
                    if(ans > 0 && area > ans)
                        continue;
                    pair<int,int> p3 = make_pair(x2,y1);
                    pair<int,int> p4 = make_pair(x1,y2);
                    if(points.find(p3) != points.end() && points.find(p4) != points.end())
                        ans = area;
                }
        return ans;
    }
};