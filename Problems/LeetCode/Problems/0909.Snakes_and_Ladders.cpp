class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& ar) {
        int n = ar.size();
        vector<int> dist(n*n,-1);
        queue<int> Q;
        Q.push(0);
        dist[0] = 0;
        while(!Q.empty()) {
            int s = Q.front();
            Q.pop();
            if(s == n*n-1)
                return dist[s];
            for( int i = s+1 ; i <= s+6 ; i++ ) {
                if(i == n*n)
                    break;
                int r=i/n,c=i%n;
                if(r%2)
                    c = n-1-c;
                r = n-1-r;
                int j = i;
                if(ar[r][c] != -1)
                    j = ar[r][c] - 1;
                if(dist[j] != -1)
                    continue;
                Q.push(j);
                dist[j] = dist[s] + 1;
            }
        }
        return -1;
    }
};