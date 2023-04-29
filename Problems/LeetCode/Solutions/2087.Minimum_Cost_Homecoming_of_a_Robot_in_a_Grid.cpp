class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sr = startPos[0];
        int sc = startPos[1];
        int er = homePos[0];
        int ec = homePos[1];
        int ans = 0;
        if(er > sr)
            for( int i = sr+1 ; i <= er ; i++ )
                ans += rowCosts[i];
        else
            for( int i = sr-1 ; i >= er ; i-- )
                ans += rowCosts[i];
        if(ec > sc)
            for( int i = sc+1 ; i <= ec ; i++ )
                ans += colCosts[i];
        else
            for( int i = sc-1 ; i >= ec ; i-- )
                ans += colCosts[i];
        return ans;
    }
};
