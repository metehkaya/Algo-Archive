typedef long long LL;

class Solution {
public:
    const LL mod = (int) 1e9+7;
    static const int maxs = (int) 1e6+1;
    vector<LL> pwr[maxs];
    int maxFrequencyScore(vector<int>& nums, int k) {
        int n = nums.size();
        for(int x : nums) {
            if(pwr[x].empty()) {
                pwr[x].push_back(0);
                pwr[x].push_back(x);
            }
            else
                pwr[x].push_back(pwr[x].back()*x%mod);
        }
        vector<int> cnt(maxs,0);
        int sum = 0;
        for( int i = 0 ; i < k ; i++ ) {
            int x = nums[i];
            sum = (sum-pwr[x][cnt[x]]+mod) % mod;
            cnt[x]++;
            sum = (sum+pwr[x][cnt[x]]) % mod;
        }
        int ans = sum;
        for( int i = k ; i < n ; i++ ) {
            int x = nums[i];
            int y = nums[i-k];
            sum = (sum-pwr[x][cnt[x]]+mod) % mod;
            cnt[x]++;
            sum = (sum+pwr[x][cnt[x]]) % mod;
            sum = (sum-pwr[y][cnt[y]]+mod) % mod;
            cnt[y]--;
            sum = (sum+pwr[y][cnt[y]]) % mod;
            ans = max(ans,sum);
        }
        return ans;
    }
};
