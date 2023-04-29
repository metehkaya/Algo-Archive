class Solution {
public:
    int threeSumClosest(vector<int>& ar, int t) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        int best = INT_MAX , ans;
        for( int i = 0 ; i < n-2 ; i++ )
            for( int j = i+1 , k = n-1 ; j < n-1 ; j++ ) {
                k = max(k,j+1);
                while(k > j && ar[i]+ar[j]+ar[k] > t)
                    k--;
                if(k > j) {
                    int diff = abs(t-ar[i]-ar[j]-ar[k]);
                    if(diff < best) {
                        best = diff;
                        ans = ar[i]+ar[j]+ar[k];
                    }
                }
                if(k < n-1) {
                    int diff = abs(t-ar[i]-ar[j]-ar[k+1]);
                    if(diff < best) {
                        best = diff;
                        ans = ar[i]+ar[j]+ar[k+1];
                    }
                }
            }
        return ans;
    }
};