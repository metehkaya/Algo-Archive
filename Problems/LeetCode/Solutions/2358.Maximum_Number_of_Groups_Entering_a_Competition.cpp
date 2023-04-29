class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size() , ans = 0;
        for( int k = 1 ; k*(k+1)/2 <= n ; k++ )
            ans = k;
        return ans;
    }
};
