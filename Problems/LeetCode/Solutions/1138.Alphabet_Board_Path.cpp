class Solution {
public:
    string alphabetBoardPath(string s) {
        string ans = "";
        int n = s.length() , r=0 , c=0;
        for( int i = 0 ; i < n ; i++ ) {
            int val = s[i]-'a';
            int x = val/5;
            int y = val%5;
            if(x == 5) {
                while(c<y) c++,ans.push_back('R');
                while(c>y) c--,ans.push_back('L');
                while(r<x) r++,ans.push_back('D');
                while(r>x) r--,ans.push_back('U');
            }
            else {
                while(r<x) r++,ans.push_back('D');
                while(r>x) r--,ans.push_back('U');
                while(c<y) c++,ans.push_back('R');
                while(c>y) c--,ans.push_back('L');
            }
            ans.push_back('!');
        }
        return ans;
    }
};