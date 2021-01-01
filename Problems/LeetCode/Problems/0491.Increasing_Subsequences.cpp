class Solution {
public:
    int n;
    vector<int> v,ar;
    vector<vector<int>> ans;
    void f(int idx , int cnt , int last) {
        if(cnt >= 2)
            ans.push_back(v);
        set<int> s;
        for( int i = idx ; i < n ; i++ )
            if(ar[i] >= last && s.find(ar[i]) == s.end()) {
                s.insert(ar[i]);
                v.push_back(ar[i]);
                f(i+1,cnt+1,ar[i]);
                v.pop_back();
            }
    }
    vector<vector<int>> findSubsequences(vector<int>& ar) {
        this->ar = ar;
        n = ar.size();
        f(0,0,-100);
        return ans;
    }
};