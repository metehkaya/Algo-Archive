class Solution {
public:
    int maxIceCream(vector<int>& ar, int rem) {
        int n = ar.size() , ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            if(rem >= ar[i])
                ans++ , rem -= ar[i];
        return ans;
    }
};