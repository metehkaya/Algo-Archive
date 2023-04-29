class Solution {
public:
    int numTeams(vector<int>& ar) {
        int n = ar.size();
        vector<int> ls(n,0);
        vector<int> lb(n,0);
        vector<int> rs(n,0);
        vector<int> rb(n,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                if( ar[i] < ar[j] )
                    rb[i]++ , ls[j]++;
                else
                    rs[i]++ , lb[j]++;
            }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += ls[i] * rb[i] + lb[i] * rs[i];
        return ans;
    }
};