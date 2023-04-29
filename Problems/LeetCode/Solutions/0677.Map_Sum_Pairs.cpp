class MapSum {
public:
    int n;
    int word[2501];
    int total[2501];
    int nxt[2501][26];
    MapSum() {
        n = 0;
        memset(nxt,-1,sizeof(nxt));
        memset(word,0,sizeof(word));
        memset(total,0,sizeof(total));
    }
    int add(string& s , int i , int idx , int val) {
        if(i == s.length()) {
            int diff = val-word[idx];
            word[idx] = val;
            total[idx] += diff;
            return diff;
        }
        int c = s[i]-'a';
        if(nxt[idx][c] == -1)
            nxt[idx][c] = ++n;
        int diff = add(s,i+1,nxt[idx][c],val);
        total[idx] += diff;
        return diff;
    }
    void insert(string s, int val) {
        add(s,0,0,val);
    }
    int sum(string s) {
        int idx = 0;
        int len = s.length();
        for( int i = 0 ; i < len ; i++ ) {
            int c = s[i]-'a';
            if(nxt[idx][c] == -1)
                return 0;
            idx = nxt[idx][c];
        }
        return total[idx];
    }
};