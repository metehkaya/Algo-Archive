class Solution {
public:
    bool check(string& s, string& t) {
        int lens = s.length(), lent = t.length();
        if(lens > lent)
            return false;
        string prefix = t.substr(0, lens);
        string suffix = t.substr(lent-lens);
        return s == prefix and s == suffix;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(check(words[i],words[j]))
                    ans++;
        return ans;
    }
};