class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        int k = max(n,m);
        int add = 0;
        string ans = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for( int i = 0 ; i < k ; i++ ) {
            int num = 0;
            if(i < n)
                num += a[i] - '0';
            if(i < m)
                num += b[i] - '0';
            num += add;
            add = num/2;
            num %= 2;
            ans.push_back('0'+num);
        }
        if(add)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};