class Solution {
public:
    static const int maxs = 100001;
    bool ok_a[maxs];
    bool ok_b[maxs];
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int sa = 0 , sb = 0;
        int n = a.size() , m = b.size();
        for( int i = 0 ; i < n ; i++ )
            sa += a[i] , ok_a[a[i]] = true;
        for( int i = 0 ; i < m ; i++ )
            sb += b[i] , ok_b[b[i]] = true;
        for( int i = 1 ; i < maxs ; i++ )
            if(ok_a[i]) {
                int j = (sb-sa+2*i)/2;
                if(j < 1 || j >= maxs || !ok_b[j])
                    continue;
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        return ans;
    }
};