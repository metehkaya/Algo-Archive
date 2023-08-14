class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char c) {
        vector<string> ans;
        for(string s : words) {
            int len = s.length(), idx = 0;
            while(idx < len) {
                int nxt_idx = s.find(c, idx);
                if(nxt_idx == -1) {
                    ans.push_back(s.substr(idx));
                    break;
                }
                else {
                    if(idx < nxt_idx)
                        ans.push_back(s.substr(idx,nxt_idx-idx));
                    idx = nxt_idx+1;
                }
            }
        }
        return ans;
    }
};
