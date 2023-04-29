class Solution {
public:
    bool isDecomposable(string s) {
        int n = s.length();
        vector<int> cnt(3,0);
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n and s[i] == s[j])
                j++;
            cnt[(j-i)%3]++;
        }
        return cnt[1] == 0 and cnt[2] == 1;
    }
};
