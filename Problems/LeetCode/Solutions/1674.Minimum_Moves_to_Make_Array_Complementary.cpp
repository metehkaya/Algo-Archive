class Solution {
public:
    int minMoves(vector<int>& ar, int limit) {
        int n = ar.size();
        vector<int> add(2*limit+2,0);
        for( int i = 0 ; i < n/2 ; i++ ) {
            int x = ar[i];
            int y = ar[n-1-i];
            if(x > y)
                swap(x,y);
            int sum = x+y;
            int l = x+1;
            int r = y+limit;
            add[2] += 2 , add[2*limit+1] -= 2;
            add[l] -= 1 , add[r+1] += 1;
            add[sum] -= 1 , add[sum+1] += 1;
        }
        int ans = INT_MAX;
        for( int i = 2 ; i <= 2*limit ; i++ ) {
            add[i] += add[i-1];
            ans = min(ans,add[i]);
        }
        return ans;
    }
};
