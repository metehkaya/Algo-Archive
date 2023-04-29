class Solution {
public:
    int maxProduct(vector<string>& s) {
        int n = s.size();
        vector<int> bmasks;
        for( int i = 0 ; i < n ; i++ ) {
            int bmask = 0;
            int len = s[i].length();
            for( int j = 0 ; j < len ; j++ )
                bmask |= (1 << (s[i][j]-'a'));
            bmasks.push_back(bmask);
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if((bmasks[i] & bmasks[j]) == 0)
                    ans = max(ans,(int)s[i].length()*(int)s[j].length());
        return ans;
    }
};