class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                string si = to_string(nums[i]);
                string sj = to_string(nums[j]);
                int x = si[0]-'0';
                int len = sj.length();
                int y = sj[len-1]-'0';
                if(__gcd(x,y) == 1)
                    ans++;
            }
        return ans;
    }
};
