class Solution {
public:
    int heightChecker(vector<int>& ar) {
        int n = ar.size();
        vector<int> cnt(101,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        int ans = 0;
        int curr = 1;
        for( int i = 0 ; i < n ; i++ ) {
            while(curr < 101 && cnt[curr] == 0)
                curr++;
            ans += ar[i] != curr;
            cnt[curr]--;
        }
        return ans;
    }
};