typedef long long LL;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potionss, LL success) {
        int m = potionss.size();
        vector<LL> potions;
        for( int i = 0 ; i < m ; i++ )
            potions.push_back(potionss[i]);
        sort(potions.begin(),potions.end());
        int n = spells.size();
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            LL req = success / spells[i] + ((success % spells[i]) > 0);
            int idx = lower_bound(potions.begin(),potions.end(),req) - potions.begin();
            ans.push_back(m-idx);
        }
        return ans;
    }
};
