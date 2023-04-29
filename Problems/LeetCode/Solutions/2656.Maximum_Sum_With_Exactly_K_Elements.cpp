class Solution {
public:
    int maximizeSum(vector<int>& v, int k) {
        int l = *max_element(v.begin(), v.end());
        int r = l+k-1;
        return (l+r)*k/2;
    }
};
