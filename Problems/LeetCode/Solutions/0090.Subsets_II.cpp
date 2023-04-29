class Solution {
public:
    vector<int> v,num,cnt;
    vector<vector<int>> ans;
    void f(int idx , int n) {
        if(idx == n) {
            ans.push_back(v);
            return;
        }
        f(idx+1,n);
        for( int i = 0 ; i < cnt[idx] ; i++ ) {
            v.push_back(num[idx]);
            f(idx+1,n);
        }
        for( int i = 0 ; i < cnt[idx] ; i++ )
            v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            num.push_back(ar[i]);
            cnt.push_back(j-i);
        }
        n = num.size();
        f(0,n);
        return ans;
    }
};