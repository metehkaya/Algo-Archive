class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        priority_queue<int> max_heap;
        priority_queue<int,vector<int>,greater<int>> min_heap;
        vector<long long> left(3*n) , right(3*n);
        long long sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += nums[i];
            max_heap.push(nums[i]);
        }
        left[n-1] = sum;
        for( int i = n ; i < 2*n ; i++ ) {
            if(max_heap.top() > nums[i]) {
                sum -= max_heap.top();
                sum += nums[i];
                max_heap.pop();
                max_heap.push(nums[i]);
            }
            left[i] = sum;
        }
        sum = 0;
        for( int i = 2*n ; i < 3*n ; i++ ) {
            sum += nums[i];
            min_heap.push(nums[i]);
        }
        right[2*n] = sum;
        for( int i = 2*n-1 ; i >= n ; i-- ) {
            if(min_heap.top() < nums[i]) {
                sum -= min_heap.top();
                sum += nums[i];
                min_heap.pop();
                min_heap.push(nums[i]);
            }
            right[i] = sum;
        }
        long long ans = LLONG_MAX;
        for( int i = n-1 ; i < 2*n ; i++ )
            ans = min(ans,left[i]-right[i+1]);
        return ans;
    }
};
