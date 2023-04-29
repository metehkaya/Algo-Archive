class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans = 0;
        for( int i = 0 , j = 0 ; i < n && j < m ; i++ , j++ ) {
            while(j < m && a[i] > b[j])
                j++;
            if(j < m)
                ans++;
        }
        return ans;
    }
};
