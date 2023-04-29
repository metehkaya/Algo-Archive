class Solution {
public:
    vector<string> findRestaurant(vector<string>& ar1, vector<string>& ar2) {
        int n = ar1.size();
        int m = ar2.size();
        map<string,int> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[ar1[i]] = i;
        vector<string> ans;
        int bestscore = INT_MAX;
        for( int i = 0 ; i < m ; i++ ) {
            map<string,int>::iterator mit = mp.find(ar2[i]);
            if(mit != mp.end()) {
                int score = i + (*mit).second;
                if(score < bestscore) {
                    bestscore = score;
                    ans.clear();
                    ans.push_back(ar2[i]);
                }
                else if(score == bestscore)
                    ans.push_back(ar2[i]);
            }
        }
        return ans;
    }
};