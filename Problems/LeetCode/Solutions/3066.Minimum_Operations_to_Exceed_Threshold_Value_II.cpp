typedef long long LL;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<LL,vector<LL>,greater<LL>> pq;
        for(int x : nums)
            pq.push(x);
        int ans = 0;
        while(pq.top() < k) {
            ans++;
            LL x = pq.top();
            pq.pop();
            LL y = pq.top();
            pq.pop();
            pq.push(2*x+y);
        }
        return ans;
    }
};