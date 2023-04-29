class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> n(2,0);
        vector<vector<int>> cnt(2,vector<int>(26,0));
        for(char c : word1)
            cnt[0][c-'a']++;
        for(char c : word2)
            cnt[1][c-'a']++;
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 0 ; j < 26 ; j++ )
                n[i] += (cnt[i][j] > 0);
        if(abs(n[0]-n[1]) > 2)
            return false;
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[0][i])
                for( int j = 0 ; j < 26 ; j++ )
                    if(cnt[1][j]) {
                        if(i == j) {
                            if(n[0] == n[1])
                                return true;
                        }
                        else {
                            int n0 = n[0] - (cnt[0][i]==1) + (cnt[0][j]==0);
                            int n1 = n[1] - (cnt[1][j]==1) + (cnt[1][i]==0);
                            if(n0 == n1)
                                return true;
                        }
                    }
        return false;
    }
};
