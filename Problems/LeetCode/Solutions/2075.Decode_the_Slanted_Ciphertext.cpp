class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int len = s.length();
        int cols = len / rows;
        string ans = "";
        for( int j = 0 ; j < cols ; j++ )
            for( int i = 0 ; i < rows ; i++ ) {
                if(i+j >= cols)
                    break;
                ans.push_back(s[i*cols+i+j]);
            }
        int idx = 0 , last;
        while(idx < ans.length()) {
            if(ans[idx] != ' ')
                last = idx;
            idx++;
        }
        return ans.substr(0,last+1);
    }
};
