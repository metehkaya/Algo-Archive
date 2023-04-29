class Solution {
public:
    int nwords;
    map<string,int> mp;
    map<string,int>::iterator it;
    void func(string& s , vector<int>& v) {
        string w = "";
        int n = s.length();
        for( int i = 0 ; i <= n ; i++ ) {
            if(i == n || s[i] == ' ') {
                int k = mp[w];
                if(!k)
                    k = mp[w] = ++nwords;
                v.push_back(k);
                w = "";
            }
            else
                w.push_back(s[i]);
        }
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<int> v1,v2;
        func(sentence1,v1);
        func(sentence2,v2);
        int n = v1.size();
        int m = v2.size();
        if(m > n) {
            swap(n,m);
            swap(v1,v2);
        }
        for( int prefix = 0 ; prefix <= m ; prefix++ ) {
            bool ok = true;
            int suffix = m-prefix;
            for( int i = 0 ; i < prefix ; i++ )
                if(v2[i] != v1[i])
                    ok = false;
            for( int i = 0 ; i < suffix ; i++ )
                if(v2[m-1-i] != v1[n-1-i])
                    ok = false;
            if(ok)
                return true;
        }
        return false;
    }
};