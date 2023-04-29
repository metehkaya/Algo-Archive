class RLEIterator {
public:
    int n,idx;
    vector<int> ar;
    RLEIterator(vector<int>& A) {
        ar = A;
        idx = 0;
        n = ar.size();
    }
    int next(int move) {
        int ans = -1;
        while(idx < n && move) {
            if(ar[idx] == 0)
                idx += 2;
            else if(move <= ar[idx]) {
                ar[idx] -= move;
                ans = ar[idx+1];
                move = 0;
            }
            else {
                move -= ar[idx];
                ans = ar[idx+1];
                idx += 2;
            }
        }
        if(move)
            ans = -1;
        return ans;
    }
};