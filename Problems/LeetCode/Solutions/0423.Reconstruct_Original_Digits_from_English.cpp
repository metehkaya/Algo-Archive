class Solution {
public:
    int cnt[26];
    int freq[10];
    string words[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    void f(int d , char c) {
        int times = cnt[c-'a'];
        int len = words[d].length();
        for( int i = 0 ; i < len ; i++ )
            cnt[words[d][i]-'a'] -= times;
        freq[d] = times;
    }
    string originalDigits(string s) {
        int n = s.length();
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        f(0,'z');
        f(6,'x');
        f(2,'w');
        f(4,'u');
        f(3,'r');
        f(1,'o');
        f(5,'f');
        f(7,'s');
        f(8,'h');
        f(9,'e');
        string ans = "";
        for( int i = 0 ; i < 10 ; i++ )
            for( int j = 0 ; j < freq[i] ; j++ )
                ans.push_back('0'+i);
        return ans;
    }
};
