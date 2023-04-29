class Solution {
public:
    int countHillValley(vector<int>& ar) {
        int n = ar.size();
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ ) {
            int l = i , r = i;
            while(l >= 0 && ar[l] == ar[i])
                l--;
            while(r < n && ar[r] == ar[i])
                r++;
            if(l < 0 || r >= n)
                continue;
            if(max(ar[l],ar[r]) < ar[i] || min(ar[l],ar[r]) > ar[i])
                mark[i] = true;
        }
        int ans = 0;
        for( int i = 1 ; i < n ; i++ )
            if(mark[i] && ar[i] != ar[i-1])
                ans++;
        return ans;
    }
};
