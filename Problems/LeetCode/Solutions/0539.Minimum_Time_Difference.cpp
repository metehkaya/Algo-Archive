class Solution {
public:
    int findMinDifference(vector<string>& ar) {
        vector<int> v;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            string s = ar[i];
            int h = 10*(s[0]-'0') + (s[1]-'0');
            int m = 10*(s[3]-'0') + (s[4]-'0');
            v.push_back(60*h+m);
        }
        int ans = INT_MAX;
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i++ ) {
            int j = (i+1) % n;
            int diff = abs(v[i]-v[j]);
            diff = min(diff,1440-diff);
            ans = min(ans,diff);
        }
        return ans;
    }
};