class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        vector<bool> var(256,false);
        for( int i = 0 ; i < n ; i++ )
            if(var[s[i]])
                return s[i];
            else
                var[s[i]] = true;
        return '0';
    }
};
