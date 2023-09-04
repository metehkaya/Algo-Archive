class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int n = heroes.size() , m = monsters.size();
        vector<vector<int>> v_heroes, v_monsters;
        for( int i = 0 ; i < n ; i++ )
            v_heroes.push_back({heroes[i],i});
        for( int i = 0 ; i < m ; i++ )
            v_monsters.push_back({monsters[i],coins[i]});
        sort(v_heroes.begin(), v_heroes.end());
        sort(v_monsters.begin(), v_monsters.end());
        long long sum = 0;
        vector<long long> ans(n);
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < m and v_monsters[j][0] <= v_heroes[i][0])
                sum += v_monsters[j++][1];
            ans[v_heroes[i][1]] = sum;
        }
        return ans;
    }
};
