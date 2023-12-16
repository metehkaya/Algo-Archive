class Solution {
public:
    int divisibleTripletCount(vector<int>& v, int d) {
        int n = v.size() , ans = 0;
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ ) {
            int rem = (d - v[i]%d) % d;
            ans += mp[rem];
            for( int j = 0 ; j < i ; j++ )
                mp[(v[i]+v[j])%d]++;
        }
        return ans;
    }
};
