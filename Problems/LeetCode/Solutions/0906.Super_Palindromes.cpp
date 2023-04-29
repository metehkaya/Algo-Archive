typedef long long LL;

class Solution {
public:
    bool check(int val , LL l , LL r) {
        LL num = (LL) val*val;
        if(num < l or num > r)
            return false;
        vector<int> digits;
        while(num) {
            digits.push_back(num%10);
            num /= 10;
        }
        int sz = digits.size();
        int last = sz / 2;
        for( int i = 0 ; i <= last ; i++ )
            if(digits[i] != digits[sz-i-1])
                return false;
        return true;
    }
    int f(int idxL , int idxR , int num , LL l , LL r , vector<int>& pw) {
        if(idxL > idxR)
            return check(num,l,r);
        int ans = 0;
        for( int i = 0 ; i <= 9 ; i++ )
            if(i > 0 or idxL > 0) {
                int val = num + i*pw[idxL];
                if(idxL < idxR)
                    val += i*pw[idxR];
                ans += f(idxL+1,idxR-1,val,l,r,pw);
            }
        return ans;
    }
    int superpalindromesInRange(string L, string R) {
        LL l = 0 , r = 0;
        for( int i = 0 ; i < L.size() ; i++ )
            l = 10 * l + L[i] - '0';
        for( int i = 0 ; i < R.size() ; i++ )
            r = 10 * r + R[i] - '0';
        vector<int> pw(9,1);
        for( int i = 1 ; i < 9 ; i++ )
            pw[i] = pw[i-1] * 10;
        int ans = 0;
        for( int i = 1 ; i <= 9 ; i++ )
            ans += f(0,i-1,0,l,r,pw);
        return ans;
    }
};