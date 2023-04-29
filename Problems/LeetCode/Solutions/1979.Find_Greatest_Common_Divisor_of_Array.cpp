class Solution {
public:
    int g(int x , int y) {
        if(!y)
            return x;
        return g(y,x%y);
    }
    int findGCD(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        return g(ar[0],ar[n-1]);
    }
};