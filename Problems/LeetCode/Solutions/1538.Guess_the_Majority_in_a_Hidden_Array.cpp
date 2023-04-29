class ArrayReader {
    public:
        int query(int a, int b, int c, int d);
        int length();
};

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int ar[n];
        memset(ar,-1,sizeof(ar));
        ar[3] = 0;
        int last = reader.query(0,1,2,3);
        for( int i = 4 ; i < n ; i++ ) {
            int q = reader.query(0,1,2,i);
            if(last == q)
                ar[i] = ar[i-1];
            else
                ar[i] = !ar[i-1];
            last = q;
        }
        if(reader.query(0,1,3,4) == reader.query(0,1,2,4))
            ar[2] = ar[3];
        else
            ar[2] = !ar[3];
        if(reader.query(0,2,3,4) == reader.query(0,1,3,4))
            ar[1] = ar[2];
        else
            ar[1] = !ar[2];
        if(reader.query(1,2,3,4) == reader.query(0,2,3,4))
            ar[0] = ar[1];
        else
            ar[0] = !ar[1];
        int f[2] = {0,0};
        for( int i = 0 ; i < n ; i++ )
            f[ar[i]]++;
        if(f[0] == f[1])
            return -1;
        int maxf = (f[0] < f[1]) ? 1 : 0;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] == maxf)
                return i;
        return -2;
    }
};