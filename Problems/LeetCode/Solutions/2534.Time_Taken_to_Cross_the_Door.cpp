class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = state.size() , curr = 0 , t = 0 , s = 1;
        queue<int> q[2];
        vector<int> ans(n);
        while(curr < n or !q[0].empty() or !q[1].empty()) {
            while(curr < n and arrival[curr] <= t) {
                q[state[curr]].push(curr);
                curr++;
            }
            if(q[0].empty())
                s = 1;
            else if(q[1].empty())
                s = 0;
            if(!q[s].empty()) {
                ans[q[s].front()] = t;
                q[s].pop();
            }
            t++;
        }
        return ans;
    }
};
