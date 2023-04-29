class Solution {
public:
    int minDeletion(vector<int>& nums) {
        bool odd = false;
        int ans = 0 , last = -1;
        for(int x : nums) {
            if(last == x && odd)
                ans++;
            else
                last = x , odd = !odd;
        }
        ans += odd;
        return ans;
    }
};
