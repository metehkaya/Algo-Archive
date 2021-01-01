class Solution {
public:
    int threeSumSmaller(vector<int>& ar, int target) {
        int n = ar.size() , ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ ) {
            int k = n-1;
            for( int j = i+1 ; j < n ; j++ ) {
                while(k > j && ar[i]+ar[j]+ar[k] >= target)
                    k--;
                if(k <= j)
                    break;
                ans += k-j;
            }
        }
        return ans;
    }
};