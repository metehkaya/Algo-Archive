class Bitset {
public:
    bool f;
    string s;
    int n,ones;
    Bitset(int size) {
        n = size;
        ones = 0;
        s = "";
        f = false;
        for( int i = 0 ; i < n ; i++ )
            s.push_back('0');
    }
    void fix(int idx) {
        if(!f) {
            if(s[idx] == '0')
                s[idx] = '1' , ones++;
        }
        else {
            if(s[idx] == '1')
                s[idx] = '0' , ones--;
        }
    }
    void unfix(int idx) {
        if(!f) {
            if(s[idx] == '1')
                s[idx] = '0' , ones--;
        }
        else {
            if(s[idx] == '0')
                s[idx] = '1' , ones++;
        }
    }
    void flip() {
        f = !f;
    }
    bool all() {
        int oness = (f ? n-ones : ones);
        return oness == n;
    }
    bool one() {
        int oness = (f ? n-ones : ones);
        return oness > 0;
    }
    int count() {
        int oness = (f ? n-ones : ones);
        return oness;
    }
    string toString() {
        if(!f)
            return s;
        string t = "";
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '0')
                t.push_back('1');
            else
                t.push_back('0');
        return t;
    }
};
