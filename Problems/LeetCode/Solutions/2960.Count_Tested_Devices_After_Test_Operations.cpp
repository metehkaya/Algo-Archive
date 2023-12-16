class Solution {
public:
    int countTestedDevices(vector<int>& v) {
        int n = v.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(v[i]) {
                ans++;
                for( int j = i+1 ; j < n ; j++ )
                    v[j] = max(v[j]-1,0);
            }
        return ans;
    }
};
