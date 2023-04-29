class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans = 0 , n = nums.size();
        queue<int> q;
        vector<bool> mark(1001,false);
        q.push(start);
        mark[start] = true;
        while(!q.empty()) {
            queue<int> qnext;
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                if(x == goal)
                    return ans;
                if(x < 0 || x > 1000)
                    continue;
                for( int i = 0 ; i < n ; i++ ) {
                    vector<int> v({x+nums[i],x-nums[i],x^nums[i]});
                    for( int y : v ) {
                        if(0 <= y && y <= 1000) {
                            if(!mark[y]) {
                                qnext.push(y);
                                mark[y] = true;
                            }
                        }
                        else if(y == goal)
                            qnext.push(y);
                    }
                }
            }
            q = qnext;
            ans++;
        }
        return -1;
    }
};
