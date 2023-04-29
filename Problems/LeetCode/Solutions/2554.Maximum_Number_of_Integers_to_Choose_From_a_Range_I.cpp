class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s(banned.begin(),banned.end());
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            if(s.count(i) == 0) {
                maxSum -= i;
                if(maxSum >= 0)
                    ans++;
                else
                    break;
            }
        return ans;
    }
};
