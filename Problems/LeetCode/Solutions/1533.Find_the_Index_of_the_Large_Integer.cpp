class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int l = 0 , r = n-1;
        while(l < r) {
            int m = (l+r)/2 , len = (r-l+1) , res;
            if(len % 2 == 0) {
                res = reader.compareSub(l,m,m+1,r);
                if(res == 1)
                    r = m;
                else
                    l = m+1;
            }
            else {
                res = reader.compareSub(l+1,m,m+1,r);
                if(res == 1)
                    l++ , r = m;
                else if(res == -1)
                    l = m+1;
                else
                    return l;
            }
        }
        return l;
    }
};
