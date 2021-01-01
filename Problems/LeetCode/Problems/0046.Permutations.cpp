class Solution {
public:
    vector<vector<int>> permute(vector<int>& ar) {
        int n = ar.size();
        vector<vector<int>> ans;
        sort(ar.begin(),ar.end());
        do {
            ans.push_back(ar);
        }while(next_permutation(ar.begin(),ar.end()));
        return ans;
    }
};