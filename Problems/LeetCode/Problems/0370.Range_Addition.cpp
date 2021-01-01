class Solution {
public:
    vector<int> getModifiedArray(int n, vector<vector<int>>& updates) {
        vector<int> ar(n,0);
        int m = updates.size();
        for( int i = 0 ; i < m ; i++ ) {
            int l = updates[i][0];
            int r = updates[i][1];
            int val = updates[i][2];
            ar[l] += val;
            if(r != n-1)
                ar[r+1] -= val;
        }
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            ar[i] = sum;
        }
        return ar;
    }
};