class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s="",t="";
        for( int i = 0 ; i < S.length() ; i++ )
            if( S[i] == '#' ) {
                if(s != "")
                    s.pop_back();
            }
            else
                s.push_back(S[i]);
        for( int i = 0 ; i < T.length() ; i++ )
            if( T[i] == '#' ) {
                if(t != "")
                    t.pop_back();
            }
            else
                t.push_back(T[i]);
        return s==t;
    }
};