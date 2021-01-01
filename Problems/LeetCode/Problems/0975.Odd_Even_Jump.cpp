class Solution {
public:
    int oddEvenJumps(vector<int>& ar) {
        int n = ar.size();
        vector<pair<bool,bool>>dp(n);
        map<int,int> hashh;
        hashh[ar[n-1]] = n-1;
        dp[n-1] = make_pair(true,true);
        map<int,int>::iterator mit;
        int ans = 1;
        for( int i = n-2 ; i >= 0 ; i-- ) {
            mit = hashh.lower_bound(ar[i]);
            if(mit != hashh.end()) {
                int index = mit->second;
                ans += dp[i].first = dp[index].second;
            }
            mit = hashh.upper_bound(ar[i]);
            if(mit != hashh.begin()) {
                mit--;
                int index = mit->second;
                dp[i].second = dp[index].first;
            }
            hashh[ar[i]] = i;
        }
        return ans;
    }
};