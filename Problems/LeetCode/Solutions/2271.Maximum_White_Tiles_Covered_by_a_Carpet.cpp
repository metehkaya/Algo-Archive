class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& ar, int carpetLen) {
        sort(ar.begin() , ar.end() , [&](vector<int>& a , vector<int>& b) {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int n = ar.size();
        vector<int> sum_range;
        int curr_sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            curr_sum += ar[i][1]-ar[i][0]+1;
            sum_range.push_back(curr_sum);
        }
        int ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            j = max(i,j);
            while(j+1 < n && ar[j+1][0]-ar[i][0]+1 <= carpetLen)
                j++;
            if(i == j) {
                ans = max(ans, min(carpetLen, ar[i][1]-ar[i][0]+1));
            }
            else {
                int sum = sum_range[j-1];
                if(i > 0)
                    sum -= sum_range[i-1];
                int right_most = ar[i][0] + carpetLen-1;
                right_most = min(right_most, ar[j][1]);
                sum += right_most - ar[j][0] + 1;
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};
