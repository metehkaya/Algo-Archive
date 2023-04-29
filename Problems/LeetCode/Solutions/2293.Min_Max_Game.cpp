class Solution {
public:
    int f(int l , int r , vector<int>& ar , bool isMin) {
        if(l == r)
            return ar[l];
        int m = (l+r)/2;
        int x = f(l,m,ar,true);
        int y = f(m+1,r,ar,false);
        if(isMin)
            return min(x,y);
        return max(x,y);
    }
    int minMaxGame(vector<int>& ar) {
        int n = ar.size();
        return f(0,n-1,ar,true);
    }
};
