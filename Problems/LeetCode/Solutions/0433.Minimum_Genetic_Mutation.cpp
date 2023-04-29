class Solution {
public:
    int n,s,e;
    int dist[(1<<16)];
    bool allowed[(1<<16)];
    const string ACGT = "ACGT";
    int getAcgtIndex(char c) {
        int idx = 0;
        while(ACGT[idx] != c)
            idx++;
        return idx;
    }
    int getHash(string& s) {
        int res = 0;
        for( int i = 0 ; i < 8 ; i++ ) {
            int k = getAcgtIndex(s[i]);
            res += (k << (2*i));
        }
        return res;
    }
    void getAdj(int x , vector<int>& adj) {
        int vals[8];
        int temp = x;
        for( int i = 0 ; i < 8 ; i++ ) {
            vals[i] = temp % 4;
            temp >>= 2;
        }
        for( int i = 0 ; i < 8 ; i++ )
            for( int j = 0 ; j < 4 ; j++ )
                if(vals[i] != j) {
                    temp = x;
                    temp -= (vals[i] << (2*i));
                    temp += (j << (2*i));
                    adj.push_back(temp);
                }
    }
    int minMutation(string start, string end, vector<string>& ar) {
        s = getHash(start);
        e = getHash(end);
        n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            allowed[getHash(ar[i])] = true;
        memset(dist,-1,sizeof(dist));
        dist[s] = 0;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            if(x == e)
                return dist[e];
            vector<int> adj;
            getAdj(x,adj);
            for( int i = 0 ; i < 24 ; i++ ) {
                int v = adj[i];
                if(dist[v] == -1 && allowed[v]) {
                    Q.push(v);
                    dist[v] = dist[x]+1;
                }
            }
        }
        return -1;
    }
};