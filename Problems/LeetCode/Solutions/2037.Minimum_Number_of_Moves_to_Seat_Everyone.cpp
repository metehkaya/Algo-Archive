class Solution {
public:
    int minMovesToSeat(vector<int>& a, vector<int>& b) {
        int n = a.size() , ans = 0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for( int i = 0 ; i < n ; i++ )
            ans += abs(a[i]-b[i]);
        return ans;
    }
};
