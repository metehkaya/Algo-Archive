class Solution {
public:
    int secondHighest(string s) {
        bool var[10];
        memset(var,0,sizeof(var));
        int n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c >= '0' && c <= '9')
                var[c-'0'] = true;
        }
        int cnt = 0;
        for( int i = 9 ; i >= 0 ; i-- )
            if(var[i])
                if(++cnt == 2)
                    return i;
        return -1;
    }
};