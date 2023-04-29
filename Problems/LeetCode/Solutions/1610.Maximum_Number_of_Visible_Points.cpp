class Solution {
public:
    int visiblePoints(vector<vector<int>>& ar, int angle, vector<int>& loc) {
        int add = 0;
        vector<double> v;
        for( int i = 0 ; i < ar.size() ; i++ ) {
            if(ar[i] == loc)
                add++;
            else
                v.push_back(atan2(ar[i][1]-loc[1],ar[i][0]-loc[0]) / M_PI * 180);
        }
        sort(v.begin(),v.end());
        int n = v.size();
        for( int i = 0 ; i < n ; i++ )
            v.push_back(v[i]+360);
        int ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < i+n && v[j]-v[i] <= angle)
                j++;
            ans = max(ans,j-i);
        }
        return ans+add;
    }
};
