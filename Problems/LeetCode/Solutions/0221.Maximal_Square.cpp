class Solution {
public:
    int maxAreaInHist(vector<int>& arr) {
        stack<int> S;
        int n = arr.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            while(!S.empty() && arr[i] < arr[S.top()]) {
                int val = arr[S.top()];
                S.pop();
                int index = S.empty() ? -1 : S.top();
                int minSide = min( val , i-1-index );
                ans = max( ans , minSide * minSide );
            }
            S.push(i);
        }
        while(!S.empty()) {
            int val = arr[S.top()];
            S.pop();
            int index = S.empty() ? -1 : S.top();
            int minSide = min( val , n-1-index );
            ans = max( ans , minSide * minSide );
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return 0;
        int m = matrix[0].size();
        if(m == 0)
            return 0;
        int ans = 0;
        vector<int> arr(m,0);
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if(matrix[i][j] == '1')
                    arr[j]++;
                else
                    arr[j] = 0;
            }
            ans = max( ans , maxAreaInHist(arr) );
        }
        return ans;
    }
};