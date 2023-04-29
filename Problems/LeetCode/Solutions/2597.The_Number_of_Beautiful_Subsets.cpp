class Solution {
public:
    int forbidden[20];
    void f(int idx , int bmask , int& ans , vector<int>& v) {
        if(idx == -1) {
            ans++;
            return;
        }
        f(idx-1,bmask,ans,v);
        if((bmask & forbidden[idx]) == 0)
            f(idx-1,(bmask | (1<<idx)),ans,v);
    }
    int beautifulSubsets(vector<int>& v, int k) {
        int n = v.size() , ans = 0;
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(v[i]+k == v[j])
                    forbidden[i] |= (1<<j);
        f(n-1,0,ans,v);
        return ans-1;
    }
};
