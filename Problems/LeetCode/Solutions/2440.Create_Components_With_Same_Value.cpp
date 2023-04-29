#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    pi f(int u , int dad , int k , vector<int>& nums, vector<vector<int>>& adj) {
        pi temp = make_pair(nums[u],0);
        for(int v : adj[u])
            if(v != dad) {
                pi add = f(v,u,k,nums,adj);
                temp.fi += add.fi;
                temp.se += add.se;
            }
        if(temp.fi == (temp.se+1)*k)
            temp.se++;
        return temp;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size() , sum = 0;
        for(int x : nums)
            sum += x;
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for( int i = n ; i > 1 ; i-- )
            if(sum % i == 0 && f(0,-1,sum/i,nums,adj).se == i)
                return i-1;
        return 0;
    }
};
