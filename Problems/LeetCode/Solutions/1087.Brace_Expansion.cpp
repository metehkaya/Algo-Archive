class Solution {
public:
    void f(int index, int len, string& curr, string& s, vector<string>& ans) {
        printf("%d %s\n",index,curr.c_str());
        if(index == len) {
            ans.push_back(curr);
            return;
        }
        int cnt = 0;
        while(index < len) {
            if(s[index] == '{') {
                vector<char> vc;
                int index2 = ++index;
                while(s[index2] != '}')
                    index2++;
                while(index<index2) {
                    if(s[index] != ',')
                        vc.push_back(s[index]);
                    index++;
                }
                sort(vc.begin(), vc.end());
                for( int i = 0 ; i < vc.size() ; i++ ) {
                    curr.push_back(vc[i]);
                    f(index2+1,len,curr,s,ans);
                    curr.pop_back();
                }
                break;
            }
            else {
                cnt++;
                curr.push_back(s[index++]);
            }
        }
        if(index == len)
            ans.push_back(curr);
        while(cnt > 0)
            cnt--, curr.pop_back();
    }
    vector<string> expand(string s) {
        int len = s.length();
        vector<string> ans;
        string curr = "";
        f(0,len,curr,s,ans);
        return ans;
    }
};