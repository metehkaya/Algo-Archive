class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        priority_queue<int,vector<int>,greater<int>> heap;
        for(int x : nums) {
            sum += x;
            heap.push(x);
            while(sum < 0) {
                ans++;
                sum -= heap.top();
                heap.pop();
            }
        }
        return ans;
    }
};
