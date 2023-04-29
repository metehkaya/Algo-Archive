class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> add(n+1,0);
        for( int i = 0 ; i < bookings.size() ; i++ ) {
            add[bookings[i][0]-1] += bookings[i][2];
            add[bookings[i][1]] -= bookings[i][2];
        }
        int curr = 0;
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            curr += add[i];
            ans.push_back(curr);
        }
        return ans;
    }
};