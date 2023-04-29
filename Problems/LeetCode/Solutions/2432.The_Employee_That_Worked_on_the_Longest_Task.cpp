class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int t = 0 , mx = -1 , ans = -1;
        for(vector<int>& v : logs) {
            int val = v[1]-t;
            if(val > mx || (val == mx && v[0] < ans)) {
                mx = val;
                ans = v[0];
            }
            t = v[1];
        }
        return ans;
    }
};
