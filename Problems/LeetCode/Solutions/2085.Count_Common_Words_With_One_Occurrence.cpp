class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int> mp[2];
        for( int i = 0 ; i < words1.size() ; i++ )
            mp[0][words1[i]]++;
        for( int i = 0 ; i < words2.size() ; i++ )
            mp[1][words2[i]]++;
        int ans = 0;
        for( int i = 0 ; i < words1.size() ; i++ ) {
            string s = words1[i];
            if(mp[0][s] * mp[1][s] == 1)
                ans++;
        }
        return ans;
    }
};
