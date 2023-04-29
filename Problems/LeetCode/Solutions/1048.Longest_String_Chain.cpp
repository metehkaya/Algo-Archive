static bool comp(string& a , string& b) {
    return a.length() < b.length();
}

class Solution {
public:
    bool check(string& a , string& b) {
        int n = a.length();
        int m = b.length();
        for( int i = 0 , j = 0 ; i < n ; i++ , j++ ) {
            while(j < m && a[i] != b[j])
                j++;
            if(j == m)
                return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin() , words.end() , comp);
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if( words[j].length() == words[i].length()+1 && dp[j] <= dp[i] && check(words[i],words[j]) ) {
                    dp[j] = dp[i] + 1;
                    ans = max( ans , dp[j] );
                }
        return ans;
    }
};