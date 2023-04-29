typedef long long LL;

class Solution {
public:
    int minElements(vector<int>& ar, int limit, int goal) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        LL sum = 0;
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        LL diff = llabs(sum-goal);
        int ans = diff/limit + ((diff%limit) > 0);
        return ans;
    }
};