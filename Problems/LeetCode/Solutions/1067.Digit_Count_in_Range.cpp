class Solution {
public:
    vector<int> getDigs(int n) {
        vector<int> v;
        while(n) {
            v.push_back(n%10);
            n /= 10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
    int f(int idx , int num , int d , bool smaller , int lim , int n , vector<int>& v , vector<int>& pw) {
        int rem = n-idx;
        if(!rem)
            return 0;
        if(smaller) {
            int res = 0;
            if(!d && !num)
                for( int i = 1 ; i < rem ; i++ )
                    res += 9 * (rem-i) * pw[rem-i-1];
            else
                res = rem * pw[rem-1];
            return res;
        }
        int res = 0;
        for( int i = 0 ; i <= v[idx] ; i++ ) {
            if((i == d && d) || (!d && !i && num)) {
                if(i < v[idx])
                    res += pw[rem-1];
                else {
                    int t = 10*num+i;
                    t *= pw[rem-1];
                    res += lim-t+1;
                }
            }
            res += f(idx+1,10*num+i,d,i<v[idx],lim,n,v,pw);
        }
        return res;
    }
    int digitsCount(int d, int low, int high) {
        vector<int> pw(10,1);
        for( int i = 1 ; i < 10 ; i++ )
            pw[i] = 10 * pw[i-1];
        vector<int> v = getDigs(high);
        int ans = f(0,0,d,false,high,v.size(),v,pw);
        if(low > 1) {
            low--;
            v = getDigs(low);
            ans -= f(0,0,d,false,low,v.size(),v,pw);
        }
        return ans;
    }
};