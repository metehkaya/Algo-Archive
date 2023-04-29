typedef long long LL;

class Solution {
public:
    LL putMarbles(vector<int>& v, int k) {
        int n = v.size();
        vector<LL> score;
        for( int i = 1 ; i < n ; i++ )
            score.push_back(v[i]+v[i-1]);
        sort(score.begin(),score.end());
        LL sum1 = 0 , sum2 = 0;
        for( int i = 0 ; i < k-1 ; i++ )
            sum1 += score[i] , sum2 += score[n-2-i];
        return sum2-sum1;
    }
};
