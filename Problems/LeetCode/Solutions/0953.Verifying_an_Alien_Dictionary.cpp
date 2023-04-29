class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int idx[256];
        for( int i = 0 ; i < 26 ; i++ )
            idx[order[i]] = i;
        int n = words.size();
        for( int i = 0 ; i < n-1 ; i++ ) {
            string a = words[i];
            string b = words[i+1];
            int lena = a.length();
            int lenb = b.length();
            bool isSmaller = false;
            for( int i = 0 ; i < min(lena,lenb) && !isSmaller ; i++ )
                if(idx[a[i]] < idx[b[i]])
                    isSmaller = true;
                else if(idx[a[i]] > idx[b[i]])
                    return false;
            if(!isSmaller && lena > lenb)
                return false;
        }
        return true;
    }
};