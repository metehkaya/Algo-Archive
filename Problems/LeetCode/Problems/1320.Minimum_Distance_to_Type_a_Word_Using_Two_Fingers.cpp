class Solution {
public:
    int getDist(int &x0, int &y0, int &x1, int& y1) {
        return abs(x0-x1) + abs(y0-y1);
    }
    pair<int,int> getLettersCoor(int letter) {
        return make_pair((letter-1)/6,(letter-1)%6);
    }
    pair<int,int> getFingersCoor(int& letter, int& index, string& word) {
        int k = word[index]-'A';
        if(letter == 0)
            return make_pair(k/6,k%6);
        else
            return make_pair((letter-1)/6,(letter-1)%6);
    }
    int f(int index, int letter1, int& n, string& word, vector<vector<int>>& dp) {
        if(index == n)
            return 0;
        if(dp[index][letter1] != -1)
            return dp[index][letter1];
        int letter0 = (index == 0) ? 0 : word[index-1]-'A'+1;
        pair<int,int> pos0 = getFingersCoor(letter0, index, word);
        pair<int,int> pos1 = getFingersCoor(letter1, index, word);
        pair<int,int> posLetter = getLettersCoor(word[index]-'A'+1);
        int x0 = pos0.first;
        int y0 = pos0.second;
        int x1 = pos1.first;
        int y1 = pos1.second;
        int xLetter = posLetter.first;
        int yLetter = posLetter.second;
        int cost0 = getDist(x0,y0,xLetter,yLetter);
        int cost1 = getDist(x1,y1,xLetter,yLetter);
        return dp[index][letter1] = min( f(index+1,letter1,n,word,dp)+cost0 , f(index+1,letter0,n,word,dp)+cost1 );
    }
    int minimumDistance(string word) {
        int n = word.length();
        vector<vector<int>> dp(n,vector<int>(27,-1));
        return f(0,0,n,word,dp);
    }
};