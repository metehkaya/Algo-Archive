class Solution {
public:
    int maximumProduct(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        int a = ar[0] , b = ar[1];
        int x = ar[n-1] , y = ar[n-2] , z = ar[n-3];
        return max(a*b*x,x*y*z);
    }
};