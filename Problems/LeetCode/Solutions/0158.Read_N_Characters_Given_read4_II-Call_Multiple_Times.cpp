class Solution {
public:
    char buf4[4];
    int i4 = 0 , n4 = 0;
    int read(char *buf, int n) {
        int idx = 0;
        while(idx < n) {
            if(i4 < n4)
                buf[idx++] = buf4[i4++];
            else {
                i4 = 0 , n4 = read4(buf4);
                if(i4 < n4)
                    buf[idx++] = buf4[i4++];
                else
                    break;
            }
        }
        return idx;
    }
};
