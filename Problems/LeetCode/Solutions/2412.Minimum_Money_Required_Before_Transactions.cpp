#define pb push_back

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& ar) {
        vector<vector<int>> neg;
        int posmax = 0;
        long long negsum = 0;
        for(vector<int>& v : ar) {
            if(v[0] > v[1]) {
                neg.pb(v);
                negsum += v[0]-v[1];
            }
            else
                posmax = max(posmax,v[0]);
        }
        long long ans = 0;
        for(vector<int>& v : neg) {
            int diff = v[0]-v[1];
            ans = max(ans,negsum-diff+v[0]);
        }
        ans += max(0LL,posmax-(ans-negsum));
        return ans;
    }
};
