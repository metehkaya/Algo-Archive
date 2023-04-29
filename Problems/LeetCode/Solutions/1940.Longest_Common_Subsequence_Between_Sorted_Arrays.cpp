class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> ans;
        vector<int> cnt(101,0);
        for(auto outer : v)
            for(auto inner : outer)
                if(++cnt[inner] == n)
                    ans.push_back(inner);
        return ans;
    }
};
