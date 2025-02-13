class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> col,cnt;
        cnt[0] = limit+1;
        vector<int> ans;
        int curr = 1;
        for(auto q : queries) {
            int x = q[0] , c = q[1];
            if(--cnt[col[x]] == 0)
                curr--;
            col[x] = c;
            if(++cnt[col[x]] == 1)
                curr++;
            ans.push_back(curr - (cnt[0] > 0));
        }
        return ans;
    }
};