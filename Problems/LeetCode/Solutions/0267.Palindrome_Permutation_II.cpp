class Solution {
public:
    vector<char> v;
    vector<string> ans;
    void f(int l , int r , vector<int>& cnt , string& str) {
        if(l >= r) {
            ans.push_back(str);
            return;
        }
        for( int j = 0 ; j < v.size() ; j++ ) {
            int i = v[j];
            if(cnt[i]) {
                cnt[i]--;
                str[l] = (char) i;
                str[r] = (char) i;
                f(l+1,r-1,cnt,str);
                cnt[i]++;
            }
        }
    }
    vector<string> generatePalindromes(string s) {
        string str = "";
        int n = s.length();
        vector<int> cnt(256,0);
        for( int i = 0 ; i < n ; i++ ) {
            cnt[s[i]]++;
            str.push_back(' ');
        }
        for( int i = 0 ; i < 256 ; i++ ) {
            if(cnt[i]%2) {
                if(str[n/2] != ' ')
                    return ans;
                str[n/2] = (char) i;
            }
            cnt[i] /= 2;
            if(cnt[i])
                v.push_back((char)i);
        }
        f(0,n-1,cnt,str);
        return ans;
    }
};