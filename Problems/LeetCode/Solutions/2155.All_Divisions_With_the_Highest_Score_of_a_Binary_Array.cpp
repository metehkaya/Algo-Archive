class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& ar) {
        int n = ar.size();
        vector<int> sum(n+1,0);
        for( int i = 0 ; i < n ; i++ )
            sum[i+1] = sum[i]+ar[i];
        int best = -1;
        vector<int> ans;
        for( int i = 0 ; i <= n ; i++ ) {
            int score = i-sum[i] + sum[n]-sum[i];
            if(score > best) {
                best = score;
                ans.clear();
                ans.push_back(i);
            }
            else if(score == best)
                ans.push_back(i);
        }
        return ans;
    }
};
