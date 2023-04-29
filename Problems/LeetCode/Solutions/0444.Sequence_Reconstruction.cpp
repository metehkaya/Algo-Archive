class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& seqs) {
        int n = nums.size();
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto v : seqs) {
            int len = v.size();
            for( int i = 1 ; i < len ; i++ ) {
                indeg[v[i]-1]++;
                adj[v[i-1]-1].push_back(v[i]-1);
            }
        }
        int next_u = -1;
        for( int i = 0 ; i < n ; i++ )
            if(indeg[i] == 0) {
                if(next_u == -1)
                    next_u = i;
                else
                    return false;
            }
        while(next_u != -1) {
            int u = next_u;
            next_u = -1;
            for(int v : adj[u])
                if(--indeg[v] == 0) {
                    if(next_u == -1)
                        next_u = v;
                    else
                        return false;
                }
        }
        return true;
    }
};
