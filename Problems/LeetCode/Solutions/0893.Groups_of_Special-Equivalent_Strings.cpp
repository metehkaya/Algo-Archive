class Solution {
public:
    int numSpecialEquivGroups(vector<string>& ar) {
        set<pair<vector<int>,vector<int>>> s;
        int n = ar.size();
        int m = ar[0].length();
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> cnt1(26,0);
            vector<int> cnt2(26,0);
            for( int j = 0 ; j < m ; j += 2 )
                cnt1[ar[i][j]-'a']++;
            for( int j = 1 ; j < m ; j += 2 )
                cnt2[ar[i][j]-'a']++;
            s.insert(make_pair(cnt1,cnt2));
        }
        return (int) s.size();
    }
};