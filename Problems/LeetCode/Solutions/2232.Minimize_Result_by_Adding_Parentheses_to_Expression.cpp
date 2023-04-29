class Solution {
public:
    string s;
    int getint(int l , int r) {
        if(l > r)
            return 1;
        int num = 0;
        for( int i = l ; i <= r ; i++ )
            num = 10*num+s[i]-'0';
        return num;
    }
    string minimizeResult(string s) {
        this->s = s;
        string ans = "";
        int n = s.length() , best = INT_MAX , idx = s.find('+');
        for( int i = 0 ; i < idx ; i++ ) {
            int a = getint(0,i-1);
            int x = getint(i,idx-1);
            for( int j = idx+1 ; j < n ; j++ ) {
                int y = getint(idx+1,j);
                int b = getint(j+1,n-1);
                int res = a*(x+y)*b;
                if(res <= best) {
                    best = res;
                    ans = s.substr(0,i) + "(" + s.substr(i,j+1-i) + ")" + s.substr(j+1,n-j-1);
                }
            }
        }
        return ans;
    }
};
