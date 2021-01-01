typedef pair<int,int> pi;

class Solution {
public:
    const int DIR[4][2] = { {0,-1} , {0,+1} , {-1,0} , {+1,0} };
    pi findRoot(pi pos, map<pi,pi>& dad) {
        pi par = dad[pos];
        if(pos == par)
            return pos;
        return dad[pos] = findRoot(dad[pos],dad);
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& arr) {
        swap(n,m);
        map<pi,pi> dad;
        map<pi,int> rank;
        vector<int> ans;
        int res = 0;
        for( int p = 0 ; p < arr.size() ; p++ ) {
            int r = arr[p][0];
            int c = arr[p][1];
            if(dad.find(pi(r,c)) != dad.end()) {
                ans.push_back(res);
                continue;
            }
            dad[pi(r,c)] = pi(r,c);
            rank[pi(r,c)] = 1;
            res++;
            for( int i = 0 ; i < 4 ; i++ ) {
                int x = r+DIR[i][0];
                int y = c+DIR[i][1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(dad.find(pi(x,y)) == dad.end())
                    continue;
                pi rootRC = findRoot(pi(r,c),dad);
                pi rootXY = findRoot(pi(x,y),dad);
                if(rootRC == rootXY)
                    continue;
                if(rank[rootRC] > rank[rootXY])
                    dad[rootXY] = rootRC;
                else if(rank[rootXY] > rank[rootRC])
                    dad[rootRC] = rootXY;
                else {
                    rank[rootRC]++;
                    dad[rootXY] = rootRC;
                }
                res--;
            }
            ans.push_back(res);
        }
        return ans;
    }
};