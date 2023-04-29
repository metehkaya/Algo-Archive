class Solution {
public:
    const static int maxv = 10001;
    bool var[maxv];
    int maximumUniqueSubarray(vector<int>& ar) {
        int n = ar.size();
        memset(var,false,sizeof(var));
        int l = 0 , r = 0 , sum = 0 , ans = 0;
        while(r < n) {
            if(!var[ar[r]]) {
                sum += ar[r];
                var[ar[r++]] = true;
                ans = max(ans,sum);
            }
            else {
                sum -= ar[l];
                var[ar[l++]] = false;
            }
        }
        return ans;
    }
};