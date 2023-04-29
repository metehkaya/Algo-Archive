class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size() , ans = 0;
        vector<int> mark(n,0);
        queue<int> Q;
        for( int i = 0 ; i < n ; i++ )
            if(status[i])
                mark[i] = (mark[i] | 2);
        for( int i = 0 ; i < initialBoxes.size() ; i++ ) {
            int box = initialBoxes[i];
            mark[box] = (mark[box] | 1);
            if(mark[box] == 3)
                Q.push(box);
        }
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ans += candies[u];
            for( int i = 0 ; i < containedBoxes[u].size() ; i++ ) {
                int box = containedBoxes[u][i];
                if(mark[box] < 3) {
                    mark[box] = (mark[box] | 1);
                    if(mark[box] == 3)
                        Q.push(box);
                }
            }
            for( int i = 0 ; i < keys[u].size() ; i++ ) {
                int box = keys[u][i];
                if(mark[box] < 3) {
                    mark[box] = (mark[box] | 2);
                    if(mark[box] == 3)
                        Q.push(box);
                }
            }
        }
        return ans;
    }
};