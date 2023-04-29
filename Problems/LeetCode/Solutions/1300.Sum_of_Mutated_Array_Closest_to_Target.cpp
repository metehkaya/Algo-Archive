class Solution {
public:
    int findBestValue(vector<int>& ar, int target) {
        int n = ar.size();
        sort( ar.begin() , ar.end() );
        int best = INT_MAX , minDiff = INT_MAX;
        for( int i = 0 , sum = 0 ; i < n && sum < target ; i++ ) {
            int a = (target - sum) / (n-i);
            int b = a+1;
            if(a <= ar[i] && (i == 0 || a >= ar[i-1])) {
                int cost = abs( sum + (n-i) * a - target );
                if(cost < minDiff) {
                    minDiff = cost;
                    best = a;
                }
            }
            if(b <= ar[i] && (i == 0 || b >= ar[i-1])) {
                int cost = abs( sum + (n-i) * b - target );
                if(cost < minDiff) {
                    minDiff = cost;
                    best = b;
                }
            }
            sum += ar[i];
        }
        if(best == INT_MAX)
            best = ar[n-1];
        return best;
    }
};
