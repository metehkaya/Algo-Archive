class Solution {
public:
    void f(int num , int sum , int sz , vector<int>& curr , vector<vector<int>>& ans) {
        if(sz < 0 || sum < 0)
            return;
        if(sum == 0) {
            if(sz == 0)
                ans.push_back(curr);
            return;
        }
        if(num == 10 || sum < num)
            return;
        f(num+1,sum,sz,curr,ans);
        curr.push_back(num);
        f(num+1,sum-num,sz-1,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        f(1,n,k,curr,ans);
        return ans;
    }
};