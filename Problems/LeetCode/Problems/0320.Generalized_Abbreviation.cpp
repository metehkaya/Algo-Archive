class Solution {
public:
    string int2str(int num) {
        string s = "";
        while(num) {
            s.push_back('0'+(num%10));
            num /= 10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    void f(int idx , int& n , bool st , string& str , string& s , vector<string>& ans) {
        if(idx == n) {
            ans.push_back(str);
            return;
        }
        str.push_back(s[idx]);
        f(idx+1,n,true,str,s,ans);
        str.pop_back();
        if(st) {
            int rem = n-idx;
            for( int i = 1 ; i <= rem ; i++ ) {
                string add = int2str(i);
                int len = add.length();
                for( int j = 0 ; j < len ; j++ )
                    str.push_back(add[j]);
                f(idx+i,n,false,str,s,ans);
                for( int j = 0 ; j < len ; j++ )
                    str.pop_back();
            }
        }
    }
    vector<string> generateAbbreviations(string word) {
        int n = word.length();
        vector<string> ans;
        string str = "";
        f(0,n,true,str,word,ans);
        return ans;
    }
};