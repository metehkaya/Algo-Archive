class Solution {
public:
    int semiOrderedPermutation(vector<int>& v) {
        int n = v.size() , idx1 , idx2;
        for( int i = 0 ; i < n ; i++ )
            if(v[i] == 1)
                idx1 = i;
            else if(v[i] == n)
                idx2 = i;
        int ans = idx1 + (n-1-idx2) - (idx1 > idx2);
        return ans;
    }
};
