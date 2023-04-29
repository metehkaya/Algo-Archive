class Solution {
public:
    int calculateTime(string kb, string word) {
        int ind[256] = {0};
        for( int i = 0 ; i < 26 ; i++ )
            ind[kb[i]] = i;
        int ans=0,curr=0;
        int n = word.length();
        for( int i = 0 ; i < n ; i++ ) {
            ans += abs(ind[word[i]]-curr);
            curr = ind[word[i]];
        }
        return ans;
    }
};