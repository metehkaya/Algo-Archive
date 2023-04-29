#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans({(int)-2e5,(int)2e5});
        vector<int> currid(n,1);
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        int mx = INT_MIN;
        for( int i = 0 ; i < n ; i++ ) {
            heap.push(pi(nums[i][0],i));
            mx = max(mx,nums[i][0]);
        }
        while(true) {
            pi temp = heap.top();
            heap.pop();
            int val = temp.fi;
            int id = temp.se;
            if(mx-val < ans[1]-ans[0])
                ans = {val,mx};
            if(currid[id] == nums[id].size())
                break;
            int newval = nums[id][currid[id]++];
            heap.push(pi(newval,id));
            mx = max(mx,newval);
        }
        return ans;
    }
};
