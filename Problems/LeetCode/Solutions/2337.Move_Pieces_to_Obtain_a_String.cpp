class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        string s="",t="";
        vector<int> sl,sr,tl,tr;
        for( int i = 0 ; i < n ; i++ ) {
            if(start[i] == 'L')
                sl.push_back(i),s.push_back('L');
            else if(start[i] == 'R')
                sr.push_back(i),s.push_back('R');
            if(target[i] == 'L')
                tl.push_back(i),t.push_back('L');
            else if(target[i] == 'R')
                tr.push_back(i),t.push_back('R');
        }
        if(s != t)
            return false;
        for( int i = 0 ; i < sl.size() ; i++ )
            if(sl[i] < tl[i])
                return false;
        for( int i = 0 ; i < sr.size() ; i++ )
            if(sr[i] > tr[i])
                return false;
        return true;
    }
};
