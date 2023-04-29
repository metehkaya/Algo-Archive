typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(e[i],s[i]));
        sort( v.begin() , v.end() );
        int sz = 0;
        LL ans = 0 , sum = 0;
        priority_queue<int,vector<int>,greater<int>> heap;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            int eval = v[i].first;
            int sval = v[i].second;
            if(sz < k) {
                sz++;
                sum += sval;
                heap.push(sval);
            }
            else if(heap.top() < sval) {
                sum += sval - heap.top();
                heap.pop();
                heap.push(sval);
            }
            ans = max( ans , sum * eval );
        }
        return ans % MOD;
    }
};