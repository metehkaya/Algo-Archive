class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s != "1") {
            int len = s.length();
            if(s[len-1] == '0')
                s = s.substr(0,len-1);
            else {
                int index = len-1;
                while(index >= 0 && s[index] == '1')
                    index--;
                string t = "";
                if(index == -1) {
                    t = "1";
                    for( int i = 0 ; i < len ; i++ )
                        t.push_back('0');
                }
                else {
                    t = s.substr(0,index);
                    t.push_back('1');
                    for( int i = index + 1 ; i < len ; i++ )
                        t.push_back('0');
                }
                s = t;
            }
            ans++;
        }
        return ans;
    }
};