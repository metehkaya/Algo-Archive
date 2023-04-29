class Solution {
public:
    int minimumCost(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = n-1 ; i >= 0 ; i -= 3 ) {
            ans += ar[i];
            if(i-1 >= 0)
                ans += ar[i-1];
        }
        return ans;
    }
};
