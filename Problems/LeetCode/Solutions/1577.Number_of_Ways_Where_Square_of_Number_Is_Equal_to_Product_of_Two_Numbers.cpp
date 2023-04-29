typedef long long LL;

class Solution {
public:
    int numTriplets(vector<int>& a, vector<int>& b) {
        int n = a.size() , m = b.size() , ans = 0;
        map<LL,int> cnt1,cnt2;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                cnt1[(LL)a[i]*a[j]]++;
        for( int i = 0 ; i < m ; i++ )
            for( int j = i+1 ; j < m ; j++ )
                cnt2[(LL)b[i]*b[j]]++;
        map<LL,int>::iterator it;
        for( int i = 0 ; i < m ; i++ ) {
            it = cnt1.find((LL)b[i]*b[i]);
            if(it != cnt1.end())
                ans += it->second;
        }
        for( int i = 0 ; i < n ; i++ ) {
            it = cnt2.find((LL)a[i]*a[i]);
            if(it != cnt2.end())
                ans += it->second;
        }
        return ans;
    }
};