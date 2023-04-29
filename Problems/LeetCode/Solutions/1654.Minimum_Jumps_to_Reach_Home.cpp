#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int minimumJumps(vector<int>& forb, int a, int b, int x) {
        int n = max(x+4*(a+b),2000);
        int dist[n+1][2];
        memset(dist,-1,sizeof(dist));
        dist[0][1] = 0;
        queue<pi> Q;
        Q.push(pi(0,1));
        bool f[n+1];
        memset(f,false,sizeof(f));
        for( int i = 0 ; i < forb.size() ; i++ )
            f[forb[i]] = true;
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int idx = temp.fi;
            int k = temp.se;
            int d = dist[idx][k];
            if(idx == x)
                return d;
            if(k && idx >= b && !f[idx-b] && dist[idx-b][0] == -1) {
                dist[idx-b][0] = d+1;
                Q.push(pi(idx-b,0));
            }
            if(idx+a <= n && !f[idx+a] && dist[idx+a][1] == -1) {
                dist[idx+a][1] = d+1;
                Q.push(pi(idx+a,1));
            }
        }
        return -1;
    }
};