class Solution {
public:
    int maxJump(vector<int>& v) {
        int n = v.size() , ans = 0;
        int last[2] = {v[0],v[0]};
        for( int i = 1 ; i < n-1 ; i++ ) {
            ans = max(ans,v[i]-last[i%2]);
            last[i%2] = v[i];
        }
        ans = max(ans,v[n-1]-min(last[0],last[1]));
        return ans;
    }
};
