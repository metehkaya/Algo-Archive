#define fi first
#define se second
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,LL> pii;

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<pii> v(n,pii(pi(-1,-1),0));
        vector<LL> ans(1,0);
        LL mx = 0;
        for( int i = n-1 ; i > 0 ; i-- ) {
            int idx = removeQueries[i];
            int l = idx , r = idx;
            LL sum = nums[idx];
            if(idx > 0 && v[idx-1].fi.fi != -1)
                l = v[idx-1].fi.fi , sum += v[idx-1].se;
            if(idx < n-1 && v[idx+1].fi.se != -1)
                r = v[idx+1].fi.se , sum += v[idx+1].se;
            v[l] = pii(pi(l,r),sum);
            v[r] = pii(pi(l,r),sum);
            mx = max(mx,sum);
            ans.push_back(mx);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
