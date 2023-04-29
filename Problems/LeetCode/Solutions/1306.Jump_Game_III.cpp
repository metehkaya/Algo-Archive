class Solution {
public:
    bool canReach(vector<int>& ar, int s) {
        int n = ar.size();
        queue<int> Q;
        vector<bool> mark(n,false);
        Q.push(s);
        mark[s] = true;
        while(!Q.empty()) {
            int i = Q.front();
            Q.pop();
            if(ar[i] == 0)
                return true;
            if(i-ar[i] >= 0 && !mark[i-ar[i]]) {
                Q.push(i-ar[i]);
                mark[i-ar[i]] = true;
            }
            if(i+ar[i] < n && !mark[i+ar[i]]) {
                Q.push(i+ar[i]);
                mark[i+ar[i]] = true;
            }
        }
        return false;
    }
};