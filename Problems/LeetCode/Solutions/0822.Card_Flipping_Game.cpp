class Solution {
public:
    int flipgame(vector<int>& a, vector<int>& b) {
        set<int> same;
        int n = a.size();
        for( int i = 0 ; i < n ; i++ )
            if(a[i] == b[i])
                same.insert(a[i]);
        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            if(a[i] != b[i]) {
                int x = min(a[i],b[i]);
                int y = max(a[i],b[i]);
                if(same.find(x) == same.end())
                    ans = min(ans,x);
                if(same.find(y) == same.end())
                    ans = min(ans,y);
            }
        return (ans == INT_MAX) ? 0 : ans;
    }
};