class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> lens;
        int n = words.size();
        for( int i = 0 ; i < n ; i++ )
            lens.push_back(words[i].length());
        vector<string> ans;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            int w = lens[i];
            j++;
            while(j < n && w+lens[j]+(j-i) <= maxWidth) {
                w += lens[j];
                j++;
            }
            if(j == i+1) {
                string s = words[i];
                int spaces = maxWidth - s.length();
                while(spaces--)
                    s.push_back(' ');
                ans.push_back(s);
            }
            else if(j == n) {
                string s = words[i];
                for( int k = i+1 ; k < j ; k++ )
                    s += " " + words[k];
                int spaces = maxWidth - s.length();
                while(spaces--)
                    s.push_back(' ');
                ans.push_back(s);
            }
            else {
                int nwords = j-i;
                int nspaces = nwords-1;
                int left = maxWidth - w;
                int wspaces = left / nspaces;
                left -= wspaces*nspaces;
                string s = words[i];
                for( int k = i+1 ; k < j ; k++ ) {
                    int spaces = wspaces;
                    if(left) {
                        left--;
                        spaces++;
                    }
                    while(spaces--)
                        s.push_back(' ');
                    s += words[k];
                }
                ans.push_back(s);
            }
        }
        return ans;
    }
};
