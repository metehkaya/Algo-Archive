#define fi first
#define se second
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<LL,pi> pii;

class Solution {
public:
    long long maxSpending(vector<vector<int>>& v) {
        int m = v.size() , n = v[0].size();
        priority_queue<pii,vector<pii>,greater<pii>> heap;
        for( int i = 0 ; i < m ; i++ )
            heap.push(pii(v[i][n-1],pi(i,n-1)));
        long long ans = 0;
        for( int t = 1 ; t <= n*m ; t++ ) {
            pii temp = heap.top();
            heap.pop();
            long long val = temp.fi;
            int id = temp.se.fi , k = temp.se.se;
            ans += val * t;
            if(k > 0)
                heap.push(pii(v[id][k-1],pi(id,k-1)));
        }
        return ans;
    }
};
