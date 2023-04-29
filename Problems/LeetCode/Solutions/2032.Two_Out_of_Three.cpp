class Solution {
public:
    int cnt[101];
    void f(vector<int>& v) {
        bool var[101];
        memset(var,false,sizeof(var));
        int n = v.size();
        for( int i = 0 ; i < n ; i++ )
            var[v[i]] = true;
        for( int i = 1 ; i <= 100 ; i++ )
            cnt[i] += var[i];
    }
    vector<int> twoOutOfThree(vector<int>& a, vector<int>& b, vector<int>& c) {
        f(a);
        f(b);
        f(c);
        vector<int> ans;
        for( int i = 1 ; i <= 100 ; i++ )
            if(cnt[i] >= 2)
                ans.push_back(i);
        return ans;
    }
};