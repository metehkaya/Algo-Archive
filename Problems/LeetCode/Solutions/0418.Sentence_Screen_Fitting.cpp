class Solution {
public:
    int wordsTyping(vector<string>& str, int rows, int cols) {
        int total = 0;
        for( int i = 0 ; i < str.size() ; i++ )
            total += str[i].length();
        total += str.size()-1;
        int r=0,c=0,ans=0,w=0;
        while(r < rows && c < cols) {
            if(w == 0) {
                int times = (cols+1-c) / (total+1);
                ans += times;
                c += (total+1)*times;
            }
            while( c+str[w].length() <= cols && r < rows ) {
                c += str[w++].length() + 1;
                if(c >= cols)
                    r++,c=0;
                if(w == str.size()) {
                    ans++,w=0;
                    break;
                }
            }
            if(c+str[w].length() > cols)
                r++,c=0;
        }
        return ans;
    }
};