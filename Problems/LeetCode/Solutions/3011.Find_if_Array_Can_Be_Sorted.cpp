class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int n = v.size();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n and __builtin_popcount(v[i]) == __builtin_popcount(v[j]))
                j++;
            sort(v.begin()+i,v.begin()+j);
        }
        return is_sorted(v.begin(),v.end());
    }
};
