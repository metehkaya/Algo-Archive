class Solution {
public:
    int minSwaps(vector<vector<int>>& ar) {
        int n = ar.size();
        int ans = 0;
        for( int row = 0 ; row < n-1 ; row++ ) {
            int cnt0 = n-1-row , chosen = -1;
            for( int i = row ; i < n ; i++ ) {
                chosen = i;
                for( int j = n-cnt0 ; j < n ; j++ )
                    if(ar[i][j] == 1) {
                        chosen = -1;
                        break;
                    }
                if(chosen != -1)
                    break;
            }
            if(chosen == -1)
                return -1;
            for( int i = chosen-1 ; i >= row ; i-- )
                swap(ar[i],ar[i+1]);
            ans += chosen-row;
        }
        return ans;
    }
};