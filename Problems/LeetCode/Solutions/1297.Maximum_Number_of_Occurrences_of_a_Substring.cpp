class Solution {
public:
    bool check(string& s , int mx) {
        int cnt = 0;
        vector<bool> var(26,false);
        for( int i = 0 ; i < s.length() ; i++ ) {
            int x = s[i]-'a';
            cnt += !var[x];
            var[x] = true;
        }
        return cnt <= mx;
    }
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<string,int> cnts;
        int n = s.length() , ans = 0;
        for( int i = 0 ; i <= n-minSize ; i++ ) {
            string t = s.substr(i,minSize);
            if(check(t,maxLetters))
                ans = max( ans , ++cnts[t] );
        }
        return ans;
    }
};