typedef long long LL;

class Solution {
public:
    LL get_cost(int n, int alleys, vector<int>& composition, vector<int>& stock, vector<int>& cost) {
        long long sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            LL item_n = (LL) alleys * composition[i];
            LL req_item_n = max(item_n-stock[i],0LL);
            sum += (LL) req_item_n * cost[i];
        }
        return sum;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        for( int i = 0 ; i < k ; i++ ) {
            int l = 0 , r = 2e8;
            while(l <= r) {
                int mid = (l+r) >> 1;
                if(get_cost(n,mid,composition[i],stock,cost) <= budget) {
                    ans = max(ans,mid);
                    l = mid+1;
                }
                else
                    r = mid-1;
            }
        }
        return ans;
    }
};
