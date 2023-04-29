class Solution {
public:
    void f(int num , int last , int d , int n , int k , vector<int>& ans) {
        if(d == n) {
            ans.push_back(num);
            return;
        }
        if(k == 0)
            f(10*num+last,last,d+1,n,k,ans);
        else {
            if(last >= k)
                f(10*num+last-k,last-k,d+1,n,k,ans);
            if(last+k < 10)
                f(10*num+last+k,last+k,d+1,n,k,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for( int i = 0 ; i <= 9 ; i++ )
            if(n == 1 || i > 0)
                f(i,i,1,n,k,ans);
        return ans;
    }
};