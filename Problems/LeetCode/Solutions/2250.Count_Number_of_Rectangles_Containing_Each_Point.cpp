class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rects, vector<vector<int>>& points) {
        int n = points.size();
        int m = rects.size();
        for( int i = 0 ; i < n ; i++ )
            points[i].push_back(i);
        sort(rects.begin(),rects.end());
        sort(points.begin(),points.end());
        vector<int> ans(n);
        int cnt[101];
        memset(cnt,0,sizeof(cnt));
        for( int i = n-1 , idx = m-1 ; i >= 0 ; i-- ) {
            while(idx >= 0 && rects[idx][0] >= points[i][0])
                cnt[rects[idx--][1]]++;
            for( int j = points[i][1] ; j <= 100 ; j++ )
                ans[points[i][2]] += cnt[j];
        }
        return ans;
    }
};
