class Solution {
public:
    char findKthBit(int n, int k) {
        string res = "0";
        for( int i = 2 ; i <= n ; i++ ) {
            string a = res,b="";
            int len = a.length();
            for( int j = len-1 ; j >= 0 ; j-- )
                if(a[j] == '0')
                    b.push_back('1');
                else
                    b.push_back('0');
            res = a+"1"+b;
        }
        return res[k-1];
    }
};