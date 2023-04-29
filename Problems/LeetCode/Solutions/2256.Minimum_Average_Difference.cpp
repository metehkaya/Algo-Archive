typedef long long LL;

class Solution {
public:
    int minimumAverageDifference(vector<int>& ar) {
        int n = ar.size();
        LL sum = 0 , total = 0 , ans = (1LL << 60);
        for( int i = 0 ; i < n ; i++ )
            total += ar[i];
        int best = -1;
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            LL avg1 = sum / (i+1);
            LL avg2 = (total-sum) / max(n-i-1,1);
            LL diff = abs(avg1-avg2);
            if(diff < ans) {
                ans = diff;
                best = i;
            }
        }
        return best;
    }
};
