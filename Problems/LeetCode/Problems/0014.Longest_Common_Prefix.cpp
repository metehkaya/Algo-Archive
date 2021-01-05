class Solution {
public:
    string longestCommonPrefix(vector<string>& ar) {
        string ans = "";
        int n = ar.size();
        if(n == 0)
            return ans;
        int minLen = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            minLen = min(minLen,(int)ar[i].length());
        for( int j = 0 ; j < minLen ; j++ ) {
            char c = ar[0][j];
            for( int i = 0 ; i < n ; i++ )
                if(ar[i][j] != c) {
                    c = 0;
                    break;
                }
            if(!c)
                break;
            ans.push_back(c);
        }
        return ans;
    }
};