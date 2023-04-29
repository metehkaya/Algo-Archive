class Solution {
public:
    int findTheWinner(int n, int k) {
        int nxt[n];
        int prv[n];
        for( int i = 0 ; i < n ; i++ ) {
            int j = (i+1) % n;
            nxt[i] = j;
            prv[j] = i;
        }
        int curr = 0;
        while(n > 1) {
            n--;
            for( int i = 1 ; i < k ; i++ )
                curr = nxt[curr];
            int prvNode = prv[curr];
            int nxtNode = nxt[curr];
            nxt[prvNode] = nxtNode;
            prv[nxtNode] = prvNode;
            curr = nxtNode;
        }
        return curr+1;
    }
};