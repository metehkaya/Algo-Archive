class Solution {
public:
    long long f(vector<int>& v , bool same) {
        if(v.empty())
            return 0;
        int sz = v.size();
        if(same)
            return (long long) sz*(sz+1)/2;
        vector<int> cnt(2,0);
        long long sum = 0;
        for( int i = 0 , j = 0 ; i < sz ; i++ ) {
            j = max(i,j);
            while(j < sz && (cnt[0] == 0 || cnt[1] == 0)) {
                if(v[j] != -1)
                    cnt[v[j]]++;
                j++;
            }
            if(cnt[0] == 0 || cnt[1] == 0)
                break;
            sum += sz-j+1;
            if(i < j && v[i] != -1)
                cnt[v[i]]--;
        }
        return sum;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        vector<int> v;
        for( int i = 0 ; i < n ; i++ ) {
            if(nums[i] < minK || nums[i] > maxK) {
                ans += f(v,minK==maxK);
                v.clear();
            }
            else if(nums[i] == minK)
                v.push_back(0);
            else if(nums[i] == maxK)
                v.push_back(1);
            else
                v.push_back(-1);
        }
        ans += f(v,minK==maxK);
        return ans;
    }
};
