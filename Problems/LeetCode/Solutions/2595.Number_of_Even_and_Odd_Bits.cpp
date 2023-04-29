class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2,0);
        for( int i = 0 ; i < 10 ; i++ )
            if(n & (1<<i))
                ans[i%2]++;
        return ans;
    }
};
