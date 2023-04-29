class Solution {
public:
    int minimizeMax(vector<int>& v, int p) {
        sort(v.begin(),v.end());
        int n = v.size() , l = 0 , r = *max_element(v.begin(),v.end()) , ans = INT_MAX;
        while(l <= r) {
            int cnt = 0 , m = (l+r) >> 1;
            for( int i = 1 ; i < n ; i++ )
                if(abs(v[i]-v[i-1]) <= m)
                    cnt++ , i++;
            if(cnt >= p)
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};
