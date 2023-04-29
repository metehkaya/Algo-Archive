class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& ar1, vector<vector<int>>& ar2, int req) {
        sort(ar1.begin(),ar1.end());
        sort(ar2.begin(),ar2.end());
        int n = ar1.size();
        int m = ar2.size();
        vector<int> ans;
        for( int i = 0 , j = 0 ; i < n && j < m ; ) {
            while(i < n && ar1[i][1] < ar2[j][0])
                i++;
            if(i == n)
                break;
            while(j < m && ar1[j][1] < ar2[i][0])
                j++;
            if(j == m)
                break;
            int s = max( ar1[i][0] , ar2[j][0] );
            int e = min( ar1[i][1] , ar2[j][1] );
            if(e-s >= req) {
                ans.push_back(s);
                ans.push_back(s+req);
                break;
            }
            if(ar1[i][1] < ar2[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};