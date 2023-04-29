class Solution {
public:
    int minimumTime(vector<int>& a, vector<int>& b) {
        int n = a.size() , m = b.size();
        int l = 0 , r = (int) 1e9 , ans = INT_MAX;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(l <= r) {
            int diff = l + (r-l)/2;
            int idx = 0;
            for( int i = 0 ; i < n and idx < m ; i++ ) {
                int l_cost = max(a[i]-b[idx],0);
                if(l_cost > diff)
                    break;
                while(idx < m and b[idx] <= a[i])
                    idx++;
                while(idx < m) {
                    int r_cost = b[idx]-a[i];
                    if(l_cost+r_cost+min(l_cost,r_cost) <= diff)
                        idx++;
                    else
                        break;
                }
            }
            if(idx == m)
                ans = diff , r = diff-1;
            else
                l = diff+1;
        }
        return ans;
    }
};
