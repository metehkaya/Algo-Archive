class Solution {
public:
    int f( int x , map<int,int>& dp ) {
        if(x == 1)
            return 0;
        map<int,int>::iterator mit = dp.find(x);
        if(mit != dp.end())
            return mit->second;
        int val;
        if(x % 2 == 0)
            val = f(x/2,dp) + 1;
        else
            val = f(3*x+1,dp) + 1;
        return dp[x] = val;
    }
    int getKth(int lo, int hi, int k) {
        map<int,int> dp;
        vector<pair<int,int>> ans;
        for( int i = lo ; i <= hi ; i++ )
            ans.push_back( make_pair( f(i,dp) , i ) );
        sort( ans.begin() , ans.end() );
        return ans[k-1].second;
    }
};