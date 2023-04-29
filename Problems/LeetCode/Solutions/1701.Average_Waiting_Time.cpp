class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& ar) {
        int n = ar.size();
        double avg = ar[0][1];
        double t = ar[0][0] + ar[0][1];
        for( int i = 1 ; i < n ; i++ ) {
            t = max(t,(double)ar[i][0]);
            t += ar[i][1];
            avg += t - ar[i][0];
        }
        return avg/n;
    }
};