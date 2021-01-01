class Solution {
public:
    vector<string> commonChars(vector<string>& ar) {
        int n = ar.size();
        vector<int> minCnt(26,100);
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> cnt(26,0);
            int len = ar[i].length();
            for( int j = 0 ; j < len ; j++ )
                cnt[ar[i][j]-'a']++;
            for( int k = 0 ; k < 26 ; k++ )
                minCnt[k] = min( minCnt[k] , cnt[k] );
        }
        vector<string> ans;
        for( int i = 0 ; i < 26 ; i++ ) {
            string s = "";
            s.push_back('a'+i);
            for( int j = 0 ; j < minCnt[i] ; j++ )
                ans.push_back(s);
        }
        return ans;
    }
};