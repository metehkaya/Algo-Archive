typedef long long LL;

class Solution {
public:
    LL largestEvenSum(vector<int>& nums, int k) {
        vector<int> odd,even;
        for(int x : nums) {
            if(x%2)
                odd.push_back(x);
            else
                even.push_back(x);
        }
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        reverse(even.begin(),even.end());
        vector<LL> sum_odd,sum_even;
        LL sum = 0;
        sum_odd.push_back(sum);
        for(int x : odd) {
            sum += x;
            sum_odd.push_back(sum);
        }
        sum = 0;
        sum_even.push_back(sum);
        for(int x : even) {
            sum += x;
            sum_even.push_back(sum);
        }
        LL ans = -1;
        int n_odd = odd.size();
        int n_even = even.size();
        for( int i = 0 ; i <= k ; i += 2 )
            if(i <= n_odd and k-i <= n_even)
                ans = max(ans,sum_odd[i]+sum_even[k-i]);
        return ans;
    }
};
