class Solution {
public:
    int n,k,ans;
    int sum[8];
    vector<int> ar;
    void getMax(int g) {
        int mx = INT_MIN;
        for( int i = 0 ; i < g ; i++ )
            mx = max(mx,sum[i]);
        ans = min(ans,mx);
    }
    void f(int id , int g) {
        if(id == n) {
            getMax(g);
            return;
        }
        for( int i = 0 ; i < g ; i++ ) {
            sum[i] += ar[id];
            f(id+1,g);
            sum[i] -= ar[id];
        }
        if(g < k) {
            sum[g] += ar[id];
            f(id+1,g+1);
            sum[g] -= ar[id];
        }
    }
    int distributeCookies(vector<int>& ar, int k) {
        this->k = k;
        this->ar = ar;
        ans = INT_MAX;
        n = ar.size();
        f(0,0);
        return ans;
    }
};
