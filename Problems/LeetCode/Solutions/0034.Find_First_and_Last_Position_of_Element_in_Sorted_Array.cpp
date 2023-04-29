class Solution {
public:
    vector<int> searchRange(vector<int>& ar, int t) {
        vector<int> ans;
        int n = ar.size();
        int l = 0 , r = n-1 , idx = -1;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(ar[m] < t)
                l = m+1;
            else if(ar[m] == t)
                idx = m , r = m-1;
            else
                r = m-1;
        }
        ans.push_back(idx);
        l = 0 , r = n-1 , idx = -1;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(ar[m] < t)
                l = m+1;
            else if(ar[m] == t)
                idx = m , l = m+1;
            else
                r = m-1;
        }
        ans.push_back(idx);
        return ans;
    }
};