#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& ar) {
        int n = ar.size();
        int sum = 0 , ans = INT_MIN;
        deque<pi> Q;
        Q.push_back(pi(0,-1));
        for( int i = 0 ; i < 2*n ; i++ ) {
            int val = ar[i%n];
            sum += val;
            while(!Q.empty() && i-Q.front().se > n)
                Q.pop_front();
            ans = max( ans , sum - Q.front().fi );
            while(!Q.empty() && sum <= Q.back().fi)
                Q.pop_back();
            Q.push_back(pi(sum,i));
        }
        return ans;
    }
};