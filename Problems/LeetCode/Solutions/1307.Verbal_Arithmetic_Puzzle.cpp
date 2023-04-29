class Solution {
public:
    int n,m;
    int char_2_int[256];
    string int_2_char = "----------";
    vector<string> words;
    bool solve(int r, int c, int sum) {
        if(c == m) {
            if(sum == 0)
                cout << int_2_char << endl;
            return sum == 0;
        }
        if(r == n)
            return (sum % 10 == 0) and solve(0,c+1,sum/10);
        int len_word = words[r].length();
        if(c >= len_word)
            return solve(r+1,c,sum);
        char ch = words[r][len_word-1-c];
        int sign = (r == n-1) ? -1 : +1;
        if(char_2_int[ch] != -1) {
            if(char_2_int[ch] == 0 and len_word > 1 and c == len_word-1)
                return false;
            return solve(r+1,c,sum+sign*char_2_int[ch]);
        }
        for( int i = 0 ; i < 10 ; i++ )
            if(int_2_char[i] == '-') {
                if(i == 0 and len_word > 1 and c == len_word-1)
                    continue;
                char_2_int[ch] = i;
                int_2_char[i] = ch;
                if(solve(r+1,c,sum+sign*i))
                    return true;
                char_2_int[ch] = -1;
                int_2_char[i] = '-';
            }
        return false;
    }
    bool isSolvable(vector<string>& words, string target) {
        words.push_back(target);
        n = words.size();
        for(string word : words)
            m = max(m,(int)word.length());
        this->words = words;
        memset(char_2_int,-1,sizeof(char_2_int));
        return solve(0,0,0);
    }
};
