class Solution {
public:
    long long numberOfWeeks(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        long long sum = 0;
        for( int i = 0 ; i < n-1 ; i++ )
            sum += ar[i];
        if(sum+1 < ar[n-1])
            return 2*sum+1;
        return sum+ar[n-1];
    }
};