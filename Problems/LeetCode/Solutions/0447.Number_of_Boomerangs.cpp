class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            map<int,int> mp;
            for( int j = 0 ; j < n ; j++ )
                if(i != j) {
                    int dx = ar[i][0]-ar[j][0];
                    int dy = ar[i][1]-ar[j][1];
                    ans += 2*mp[dx*dx+dy*dy]++;
                }
        }
        return ans;
    }
};