class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int i = 0;
        string ans = "";
        while(a+b) {
            if(a and !b)
                a--,ans.push_back('a');
            else if(b and !a)
                b--,ans.push_back('b');
            else {
                if(a >= b) {
                    if(i >= 2 and ans[i-1] == 'a' and ans[i-2] == 'a')
                        b--,ans.push_back('b');
                    else
                        a--,ans.push_back('a');
                }
                else {
                    if(i >= 2 and ans[i-1] == 'b' and ans[i-2] == 'b')
                        a--,ans.push_back('a');
                    else
                        b--,ans.push_back('b');
                }
            }
            i++;
        }
        return ans;
    }
};