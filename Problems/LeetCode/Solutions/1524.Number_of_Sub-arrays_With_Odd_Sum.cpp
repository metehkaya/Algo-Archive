class Solution {
public:
    const int mod = (int) 1e9+7;
    int numOfSubarrays(vector<int>& ar) {
        int e=1,o=0,sum=0,ans=0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            sum += ar[i];
            if(sum%2)
                ans = (ans+e)%mod , o++;
            else
                ans = (ans+o)%mod , e++;
        }
        return ans;
    }
};