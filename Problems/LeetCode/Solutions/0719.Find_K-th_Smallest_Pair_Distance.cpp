class Solution {
public:
    int smallestDistancePair(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(),v.end());
        int l = 0 , r = v[n-1]-v[0] , ans = -1;
        while(l <= r) {
            int diff = (l+r) >> 1 , sum = 0;
            for( int i = 0 ; i < n ; i++ ) {
                auto it = upper_bound(v.begin(),v.end(),v[i]+diff);
                sum += (int)(it-v.begin()) - (i+1);
            }
            if(sum >= k)
                ans = diff , r = diff-1;
            else
                l = diff+1;
        }
        return ans;
    }
};
