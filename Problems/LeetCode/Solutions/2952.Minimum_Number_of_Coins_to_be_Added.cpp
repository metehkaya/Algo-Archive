class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int ans = 0;
        long long sum = 0;
        sort(coins.begin(),coins.end());
        coins.push_back(target+1);
        for(int x : coins) {
            while(sum+1 < x) {
                ans++;
                sum = 2*sum+1;
            }
            sum += x;
        }
        return ans;
    }
};
