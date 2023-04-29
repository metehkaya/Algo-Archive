class Solution {
public:
    const int C = 26;
    const int N = (1 << C);
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        vector<int> cnt(N,0);
        for( int i = 0 ; i < n ; i++ ) {
            string word = words[i];
            int len = word.length();
            int bmask = 0;
            for( int j = 0 ; j < len ; j++ ) {
                int c = word[j] - 'a';
                bmask |= (1 << c);
            }
            cnt[bmask]++;
        }
        int m = puzzles.size();
        vector<int> ans;
        for( int t = 0 ; t < m ; t++ ) {
            string puzzle = puzzles[t];
            int res = 0;
            int first = puzzle[0] - 'a';
            for( int i = 0 ; i < 64 ; i++ ) {
                int bmask = (1 << first);
                for( int j = 0 ; j < 6 ; j++ )
                    if(i & (1<<j)) {
                        int c = puzzle[j+1] - 'a';
                        bmask |= (1 << c);
                    }
                res += cnt[bmask];
            }
            ans.push_back(res);
        }
        return ans;
    }
};