class Solution {
public:
    int minArrayLength(vector<int>& v, int k) {
        for(int x : v)
            if(x == 0)
                return 1;
        int n = v.size() , curr = v[0] , ans = n;
        for( int i = 1 ; i < n ; i++ )
            if(curr <= k / v[i]) {
                ans--;
                curr *= v[i];
            }
            else
                curr = v[i];
        return ans;
    }
};
