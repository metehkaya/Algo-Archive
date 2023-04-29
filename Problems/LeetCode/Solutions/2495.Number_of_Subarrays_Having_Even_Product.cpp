typedef long long LL;

class Solution {
public:
    LL evenProduct(vector<int>& v) {
        int n = v.size();
        LL ans = (LL)n*(n+1)/2;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n and v[i]%2 == v[j]%2)
                j++;
            if(v[i]%2) {
                LL len = j-i;
                ans -= len*(len+1)/2;
            }
        }
        return ans;
    }
};
