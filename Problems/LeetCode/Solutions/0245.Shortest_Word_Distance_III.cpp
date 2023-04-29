class Solution {
public:
    void f(vector<int>& a , vector<int>& b , int& ans) {
        int n = a.size() , m = b.size();
        for( int i = 0 , j = 0 ; i < n and j < m ; i++ ) {
            while(j < m and a[i] >= b[j])
                j++;
            if(j < m)
                ans = min(ans,b[j]-a[i]);
        }
    }
    int shortestWordDistance(vector<string>& words, string s, string t) {
        map<string,vector<int>> mp;
        int n = words.size();
        for( int i = 0 ; i < n ; i++ )
            mp[words[i]].push_back(i);
        vector<int> a = mp[s];
        vector<int> b = mp[t];
        int ans = INT_MAX;
        f(a,b,ans);
        f(b,a,ans);
        return ans;
    }
};
