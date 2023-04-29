#define mod (LL)(1e9+7)
typedef long long LL;

class Solution {
public:
    LL ans;
    queue<vector<int>> q;
    void proc(vector<int>& a) {
        int sz = q.size();
        while(sz--) {
            vector<int> t = q.front();
            q.pop();
            if(a[0]<=t[2] && a[2]>=t[0] && a[1]<=t[3] && a[3]>=t[1]) {
                if(a[0] > t[0])
                    q.push({t[0],t[1],a[0],t[3]});
                if(a[3] < t[3])
                    q.push({max(a[0],t[0]),a[3],t[2],t[3]});
                if(a[1] > t[1])
                    q.push({max(a[0],t[0]),t[1],t[2],a[1]});
                if(a[2] < t[2])
                    q.push({a[2],max(a[1],t[1]),t[2],min(t[3],a[3])});
            }
            else
                q.push(t);
        }
        q.push(a);
    }
    int rectangleArea(vector<vector<int>>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            proc(ar[i]);
        while(!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            LL w = v[2]-v[0];
            LL h = v[3]-v[1];
            ans = (ans + w*h%mod) % mod;
        }
        return (int)ans;
    }
};