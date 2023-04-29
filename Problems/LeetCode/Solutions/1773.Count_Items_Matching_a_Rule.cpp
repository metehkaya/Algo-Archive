class Solution {
public:
    int countMatches(vector<vector<string>>& ar, string ruleKey, string ruleValue) {
        int id = -1;
        if(ruleKey == "type")
            id = 0;
        else if(ruleKey == "color")
            id = 1;
        else
            id = 2;
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i][id] == ruleValue)
                ans++;
        return ans;
    }
};