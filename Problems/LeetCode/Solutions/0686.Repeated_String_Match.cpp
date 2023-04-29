class Solution {
public:
    void preKmp(string& t, vector<int>& table) {
        int i = 1;
        int len = 0;
        int m = t.length();
        while(i < m) {
            if(t[i] == t[len])
                table[i++] = ++len;
            else {
                if(len != 0)
                    len = table[len-1];
                else
                    table[i++] = 0;
            }
        }
    }
    int solveKmp(string& s, string& t, vector<int>& table) {
        int i=0,j=0;
        int n = s.length();
        int m = t.length();
        while(i < n) {
            if(s[i] == t[j])
                i++,j++;
            if(j == m)
                return i-1;
            else if(i < n && s[i] != t[j]) {
                if(j != 0)
                    j = table[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
    int kmp(string& s, string& t) {
        vector<int>table(t.length(),0);
        preKmp(t,table);
        return solveKmp(s,t,table);
    }
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        int k = m/n+2;
        string s = "";
        while(k--)
            s += a;
        int idx = kmp(s,b);
        return idx == -1 ? -1 : idx/n+1;
    }
};
