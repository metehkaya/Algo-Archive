class Solution {
public:
    void dfs(int root, int node, vector<vector<bool>>& G, vector<vector<int>>& adj, vector<bool>& mark) {
        mark[node] = G[root][node] = true;
        for( int i = 0 ; i < adj[node].size() ; i++ )
            if(!mark[ adj[node][i]])
                dfs(root,adj[node][i],G,adj,mark);
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        int n = words1.size();
        int m = words2.size();
        if(n != m)
            return false;
        int N = 0;
        unordered_map<string,int>hashh;
        unordered_map<string,int>::iterator mit;
        vector<pair<int,int>> vec;
        for( int i = 0 ; i < (int) pairs.size() ; i++ ) {
            int id1=-1,id2=-1;
            mit = hashh.find(pairs[i][0]);
            if(mit != hashh.end())
                id1 = mit->second;
            else
                id1 = hashh[pairs[i][0]] = N++;
            mit = hashh.find(pairs[i][1]);
            if(mit != hashh.end())
                id2 = mit->second;
            else
                id2 = hashh[pairs[i][1]] = N++;
            vec.push_back(make_pair(id1,id2));
        }
        vector<vector<int>>adj(N);
        for( int i = 0 ; i < vec.size() ; i++ ) {
            int id1 = vec[i].first;
            int id2 = vec[i].second;
            adj[id1].push_back(id2);
            adj[id2].push_back(id1);
        }
        vector<vector<bool>>G(N,vector<bool>(N));
        for( int i = 0 ; i < N ; i++ ) {
            vector<bool> mark(N);
            dfs(i,i,G,adj,mark);
        }
        for( int i = 0 ; i < n ; i++ ) {
            if(words1[i] == words2[i])
                continue;
            int id1=-1,id2=-1;
            mit = hashh.find(words1[i]);
            if(mit == hashh.end())
                return false;
            else
                id1 = mit->second;
            mit = hashh.find(words2[i]);
            if(mit == hashh.end())
                return false;
            else
                id2 = mit->second;
            if(!G[id1][id2])
                return false;
        }
        return true;
    }
};