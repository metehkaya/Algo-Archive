class Solution {
public:
    static const int maxn = 10001;
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> d(maxn,-1);
        d[x] = 0;
        queue<int> q({x});
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(x-1 >= 0 and d[x-1] == -1) {
                q.push(x-1);
                d[x-1] = d[x]+1;
            }
            if(x+1 < maxn and d[x+1] == -1) {
                q.push(x+1);
                d[x+1] = d[x]+1;
            }
            if(x%5 == 0 and d[x/5] == -1) {
                q.push(x/5);
                d[x/5] = d[x]+1;
            }
            if(x%11 == 0 and d[x/11] == -1) {
                q.push(x/11);
                d[x/11] = d[x]+1;
            }
        }
        return d[y];
    }
};
