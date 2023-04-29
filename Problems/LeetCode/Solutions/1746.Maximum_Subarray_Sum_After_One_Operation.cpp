class Solution {
public:
    int maxSumAfterOperation(vector<int>& v) {
        int n = v.size();
        int curr0 = 0 , curr1 = 0;
        int ans0 = INT_MIN , ans1 = INT_MIN;
        for(int x : v) {
            curr1 = max(curr1+x,curr0+x*x);
            ans1 = max(ans1,curr1);
            curr0 += x;
            ans0 = max(ans0,curr0);
            curr1 = max(curr1,0);
            curr0 = max(curr0,0);
        }
        return ans1;
    }
};
