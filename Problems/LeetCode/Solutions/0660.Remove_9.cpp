class Solution {
public:
    vector<int> p9;
    int check(int n) {
        string s = to_string(n);
        int len = s.length();
        for( int i = 0 ; i < len ; i++ )
            if(s[i] == '9') {
                for( int j = i ; j < len ; j++ )
                    s[j] = '8';
                break;
            }
        int sum = 0;
        for( int i = 0 ; i < len ; i++ )
            sum += p9[len-i-1] * (s[i]-'0');
        return sum;
    }
    int newInteger(int n) {        
        p9.push_back(1);
        for( int i = 1 ; i <= 9 ; i++ )
            p9.push_back(9*p9.back());
        int l = 1 , r = INT_MAX , ans = -1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(check(m) >= n)
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};
