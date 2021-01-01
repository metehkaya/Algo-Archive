int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int sum = 0;
        for( int i = 0 ; i < n ; i += 4 ) {
            int len = read4(buf);
            buf += len;
            sum += len;
            if(len < 4)
                break;
        }
        while(sum > n)
            buf[--sum] = '\0';
        return sum;
    }
};