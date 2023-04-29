class Solution {
public:
    int triangularSum(vector<int>& curr) {
        int n = curr.size();
        while(n > 1) {
            n--;
            vector<int> nxt(n);
            for( int i = 0 ; i < n ; i++ )
                nxt[i] = (curr[i] + curr[i+1]) % 10;
            curr = nxt;
        }
        return curr[0];
    }
};
