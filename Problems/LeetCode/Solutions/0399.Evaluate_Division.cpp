typedef pair<int,int> pi;
typedef pair<int,double> pd;
typedef pair<pi,double> pid;

class Solution {
public:
    void dfs(int root, int node, double ratio, vector<vector<pd>>& adj, vector<vector<double>>& G, vector<bool>& mark) {
        G[node][root] = ratio;
        if(ratio != 0)
            G[root][node] = 1.0 / ratio;
        mark[node] = true;
        for( int i = 0 ; i < adj[node].size() ; i++ ) {
            int to = adj[node][i].first;
            double r = adj[node][i].second;
            if(!mark[to])
                dfs(root,to,ratio*r,adj,G,mark);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& ques) {
        int n = 0;
        unordered_map<string,int> hashh;
        unordered_map<string,int>::iterator mit;
        vector<pid> edges;
        for( int i = 0 ; i < eqs.size() ; i++ ) {
            int id1=-1,id2=-1;
            mit = hashh.find(eqs[i][0]);
            if(mit == hashh.end())
                id1 = hashh[eqs[i][0]] = n++;
            else
                id1 = mit->second;
            mit = hashh.find(eqs[i][1]);
            if(mit == hashh.end())
                id2 = hashh[eqs[i][1]] = n++;
            else
                id2 = mit->second;
            edges.push_back( pid( pi(id2,id1) , vals[i] ) );
        }
        vector<vector<pd>> adj(n);
        for( int i = 0 ; i < edges.size() ; i++ ) {
            int s = edges[i].first.first;
            int e = edges[i].first.second;
            double d = edges[i].second;
            adj[s].push_back(pd(e,d));
            if(d != 0)
                adj[e].push_back(pd(s,1.0/d));
        }
        vector<vector<double>> G(n, vector<double>(n,-1));
        for( int i = 0 ; i < n ; i++ ) {
            vector<bool> mark(n);
            dfs(i,i,1.0,adj,G,mark);
        }
        vector<double> ans;
        for( int i = 0 ; i < ques.size() ; i++ ) {
            int id1=-1,id2=-1;
            mit = hashh.find(ques[i][0]);
            if(mit != hashh.end())
                id1 = mit->second;
            mit = hashh.find(ques[i][1]);
            if(mit != hashh.end())
                id2 = mit->second;
            if(id1 == -1 || id2 == -1)
                ans.push_back(-1);
            else
                ans.push_back(G[id1][id2]);
        }
        return ans;
    }
};