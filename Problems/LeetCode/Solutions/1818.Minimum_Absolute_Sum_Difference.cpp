typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> vals;
        vector<int> costs;
        int n = nums1.size();
        LL ans = 0 , total = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int c = abs(nums1[i]-nums2[i]);
            total += c;
            costs.push_back(c);
            vals.insert(nums1[i]);
        }
        ans = total;
        set<int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            it = vals.upper_bound(nums2[i]);
            if(it != vals.end()) {
                int newcost = abs((*it)-nums2[i]);
                LL newtotal = total - costs[i] + newcost;
                ans = min(ans,newtotal);
            }
            if(it != vals.begin()) {
                it--;
                int newcost = abs((*it)-nums2[i]);
                LL newtotal = total - costs[i] + newcost;
                ans = min(ans,newtotal);
            }
        }
        return ans % mod;
    }
};