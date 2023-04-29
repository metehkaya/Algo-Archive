class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size() , nodes = 1;
        vector<int> cnt(1,0);
        vector<vector<int>> nxt(1,vector<int>(26,-1));
        for(string word : words) {
            int idx = 0;
            for(char cc : word) {
                int c = cc-'a';
                if(nxt[idx][c] == -1) {
                    nxt[idx][c] = nodes++;
                    cnt.push_back(0);
                    nxt.push_back(vector<int>(26,-1));
                }
                idx = nxt[idx][c];
                cnt[idx]++;
            }
        }
        vector<int> ans;
        for(string word : words) {
            int idx = 0 , sum = 0;
            for(char cc : word) {
                int c = cc-'a';
                idx = nxt[idx][c];
                sum += cnt[idx];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
