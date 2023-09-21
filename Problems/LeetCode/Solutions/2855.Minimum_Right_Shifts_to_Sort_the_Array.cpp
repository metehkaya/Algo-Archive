class Solution {
public:
    int minimumRightShifts(vector<int>& v) {
        int n = v.size() , idx = 0;
        for( int i = 1 ; i < n ; i++ )
            if(v[i] > v[idx])
                idx = i;
        vector<int> v_cpy(n);
        int shift = n-1-idx;
        for( int i = 0 ; i < n ; i++ )
            v_cpy[(i+shift)%n] = v[i];
        for( int i = 1 ; i < n ; i++ )
            if(v_cpy[i] < v_cpy[i-1])
                return -1;
        return shift;
    }
};
