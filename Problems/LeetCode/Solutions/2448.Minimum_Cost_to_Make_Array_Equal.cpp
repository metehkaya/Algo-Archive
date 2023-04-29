#define fi first
#define se second
typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long sum1 = 0 , sum2 = 0 , curr = 0 , ans;
        vector<pi> v;
        for( int i = 0 ; i < n ; i++ ) {
            sum1 += cost[i];
            v.push_back(pi(nums[i],cost[i]));
        }
        sort(v.begin(),v.end());
        for( int i = 1 ; i < n ; i++ )
            curr += (LL) (v[i].fi - v[0].fi) * v[i].se;
        ans = curr;
        for( int i = v[0].fi+1 , idx = 0 ; i <= v[n-1].fi ; i++ ) {
            while(idx < n && v[idx].fi < i) {
                sum1 -= v[idx].se;
                sum2 += v[idx].se;
                idx++;
            }
            curr += sum2-sum1;
            ans = min(ans,curr);
        }
        return ans;
    }
};
