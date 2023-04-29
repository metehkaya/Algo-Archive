class Solution {
public:
    const int N = (int) 1e5 + 1;
    int maxEqualFreq(vector<int>& ar) {
        int n = ar.size();
        vector<int> occ(N,0);
        vector<int> cnt(N,0);
        int mx = 0 , ans = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            int val = ar[i-1];
            cnt[occ[val]]--;
            cnt[++occ[val]]++;
            mx = max(mx,occ[val]);
            if(mx == 1)
                ans = i;
            else {
                if(cnt[1] == 1 && mx*cnt[mx]+1 == i)
                    ans = i;
                if(cnt[mx] == 1 && (mx-1)*cnt[mx-1]+mx == i)
                    ans = i;
            }
        }
        return ans;
    }
};