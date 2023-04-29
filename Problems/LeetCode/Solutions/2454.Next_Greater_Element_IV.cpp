#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<pi> v;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(nums[i],i));
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int> ans(n,-1);
        set<int> s;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && v[i].fi == v[j].fi)
                j++;
            for( int k = i ; k < j ; k++ ) {
                int idx = v[k].se;
                auto it = s.upper_bound(idx);
                if(it != s.end()) {
                    it++;
                    if(it != s.end())
                        ans[idx] = nums[(*it)];
                }
            }
            for( int k = i ; k < j ; k++ )
                s.insert(v[k].se);
        }
        return ans;
    }
};
