typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    void f(int i , int n , vi& ar , vi& v , vii& ans) {
        if(i == n) {
            ans.push_back(v);
            return;
        }
        f(i+1,n,ar,v,ans);
        v.push_back(ar[i]);
        f(i+1,n,ar,v,ans);
        v.pop_back();
    }
    vii subsets(vi& ar) {
        int n = ar.size();
        vii ans;
        vi v;
        sort(ar.begin(),ar.end());
        f(0,n,ar,v,ans);
        return ans;
    }
};