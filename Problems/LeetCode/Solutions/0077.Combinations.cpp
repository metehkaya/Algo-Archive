class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    void f(int x , int n , int k) {
        if(k == 0) {
            ans.push_back(v);
            return;
        }
        if(x+k <= n)
            f(x+1,n,k);
        v.push_back(x);
        f(x+1,n,k-1);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        f(1,n,k);
        return ans;
    }
};