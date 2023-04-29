class StringIterator {
public:
    int idx,len;
    int times,timeslen;
    string s;
    void getTimes() {
        times = 0;
        timeslen = 0;
        for( int i = 0 ; idx+1+i < len && s[idx+1+i] >= '0' && s[idx+1+i] <= '9' ; i++ ) {
            timeslen++;
            times = times*10 + (s[idx+1+i]-'0');
        }
    }
    StringIterator(string str) {
        s = str;
        idx = 0;
        len = str.length();
        getTimes();
    }
    char next() {
        if(idx < len) {
            char c = s[idx];
            times--;
            if(times == 0) {
                idx += timeslen+1;
                getTimes();
            }
            return c;
        }
        return ' ';
    }
    bool hasNext() {
        return idx < len;
    }
};