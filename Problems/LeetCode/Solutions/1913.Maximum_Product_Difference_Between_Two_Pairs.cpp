class Solution {
public:
    int maxProductDifference(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        return ar[n-1]*ar[n-2]-ar[0]*ar[1];
    }
};