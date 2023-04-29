class Solution {
public:
    static const int maxn = 1000;
    int dad[maxn];
    int rank[maxn];
    int findPar(int u) {
        if(dad[u] == -1)
            return u;
        return dad[u] = findPar(dad[u]);
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        memset(dad,-1,sizeof(dad));
        vector<bool> ans;
        for( int i = 0 ; i < requests.size() ; i++ ) {
            int a = findPar(requests[i][0]);
            int b = findPar(requests[i][1]);
            if(a == b) {
                ans.push_back(true);
                continue;
            }
            bool ok = true;
            for( int j = 0 ; ok && j < restrictions.size() ; j++ ) {
                int x = findPar(restrictions[j][0]);
                int y = findPar(restrictions[j][1]);
                if(a == x && b == y)
                    ok = false;
                else if(a == y && b == x)
                    ok = false;
            }
            if(ok) {
                if(rank[a] < rank[b])
                    swap(a,b);
                dad[b] = a;
                if(rank[a] == rank[b])
                    rank[a]++;
            }
            ans.push_back(ok);
        }
        return ans;
    }
};
