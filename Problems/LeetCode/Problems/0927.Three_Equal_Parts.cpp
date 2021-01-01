class Solution {
public:
    vector<int> threeEqualParts(vector<int>& ar) {
        int n = ar.size();
        vector<int> v , ans(2,-1);
        for( int i = 0 ; i < n ; i++ )
            if(ar[i])
                v.push_back(i);
        int cnt1 = v.size();
        if(cnt1 == 0) {
            ans[0] = 0 , ans[1] = n-1;
            return ans;
        }
        if(cnt1 % 3)
            return ans;
        int k = cnt1 / 3;
        int cnt0 = n-1 - v[cnt1-1];
        if( min( v[k]-v[k-1]-1 , v[2*k]-v[2*k-1]-1 ) < cnt0 )
            return ans;
        for( int i = k ; i < 2*k-1 ; i++ )
            if(v[i+1] - v[i] != v[i+1-k] - v[i-k])
                return ans;
        for( int i = 2*k ; i < cnt1-1 ; i++ )
            if(v[i+1] - v[i] != v[i+1-2*k] - v[i-2*k])
                return ans;
        ans[0] = v[k-1] + cnt0;
        ans[1] = v[2*k-1] + cnt0 + 1;
        return ans;
    }
};