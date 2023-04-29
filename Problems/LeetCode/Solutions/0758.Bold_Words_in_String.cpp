class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.length();
        vector<bool> mark(n,false);
        for(string word : words) {
            int len = word.length();
            for( int i = 0 ; i <= n-len ; i++ )
                if(s.substr(i,len) == word)
                    for( int j = i ; j < i+len ; j++ )
                        mark[j] = true;
        }
        string ans = "";
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n and mark[i] == mark[j])
                j++;
            if(mark[i])
                ans += "<b>";
            ans += s.substr(i,j-i);
            if(mark[i])
                ans += "</b>";
        }
        return ans;
    }
};
