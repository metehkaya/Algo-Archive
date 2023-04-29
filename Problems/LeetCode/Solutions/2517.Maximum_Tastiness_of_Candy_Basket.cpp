class Solution {
public:
    int maximumTastiness(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(),v.end());
        int l = 1 , r = v[n-1]-v[0] , ans = 0;
        while(l <= r) {
            int diff = (l+r)>>1;
            int cnt = 1 , last = v[0];
            for( int i = 1 ; i < n ; i++ )
                if(v[i] >= last+diff)
                    last = v[i] , cnt++;
            if(cnt >= k)
                ans = diff , l = diff+1;
            else
                r = diff-1;
        }
        return ans;
    }
};
