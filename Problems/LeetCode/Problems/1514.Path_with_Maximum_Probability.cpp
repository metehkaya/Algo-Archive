typedef pair<double,int> pdi;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& p, int s, int e) {
        priority_queue<pdi> Q;
        vector<vector<pdi>> adj(n);
        for( int i = 0 ; i < (int) edges.size() ; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(pdi(p[i],v));
            adj[v].push_back(pdi(p[i],u));
        }
        Q.push(pdi(1,s));
        vector<bool> mark(n,false);
        while(!Q.empty()) {
            pdi temp = Q.top();
            Q.pop();
            int u = temp.second;
            double prob = temp.first;
            if(u == e)
                return prob;
            if(mark[u])
                continue;
            mark[u] = true;
            for( int i = 0 ; i < adj[u].size() ; i++ ) {
                int v = adj[u][i].second;
                double w = adj[u][i].first;
                if(!mark[v])
                    Q.push(pdi(prob*w,v));
            }
        }
        return 0;
    }
};