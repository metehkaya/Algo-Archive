#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& ar, int k) {
        int n = ar.size();
        if(ar[n-1] == -1)
            return {};
        vector<int> dp(n,-1);
        vector<int> pre(n,-1);
        dp[n-1] = ar[n-1];
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        heap.push(pi(dp[n-1],n-1));
        for( int i = n-2 ; i >= 0 ; i-- )
            if(ar[i] != -1) {
                while(!heap.empty() && heap.top().se-k > i)
                    heap.pop();
                if(!heap.empty()) {
                    pre[i] = heap.top().se;
                    dp[i] = heap.top().fi + ar[i];
                    heap.push(pi(dp[i],i));
                }
            }
        if(pre[0] == -1 and n > 1)
            return {};
        vector<int> ans;
        int curr = 0;
        while(curr != n-1) {
            ans.push_back(curr+1);
            curr = pre[curr];
        }
        ans.push_back(n);
        return ans;
    }
};
