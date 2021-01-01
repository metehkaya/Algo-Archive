class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b) {
        for( int i = 0 ; i < 26 ; i++ )
            if( a[i] != b[i] )
                return a[i] > b[i];
        return a[26] < b[26];
    }
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int len = votes[0].size();
        vector<vector<int>> ar(26,vector<int>(27,0));
        for( int i = 0 ; i < 26 ; i++ )
            ar[i][26] = i;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < len ; j++ )
                ar[ votes[i][j]-'A' ][j]++;
        sort(ar.begin() , ar.end() , comp);
        string ans = "";
        for( int i = 0 ; i < 26 ; i++ ) {
            int sum = 0;
            for( int j = 0 ; j < 26 ; j++ )
                sum += ar[i][j];
            if(sum == 0)
                break;
            char c = 'A' + ar[i][26];
            ans.push_back(c);
        }
        return ans;
    }
};