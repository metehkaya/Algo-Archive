class TextEditor {
public:
    string s1,s2;
    TextEditor() {
        s1 = s2 = "";
    }
    void addText(string text) {
        s1 += text;
    }
    int deleteText(int k) {
        k = min(k, (int) s1.size());
        for( int i = 0 ; i < k ; i++ )
            s1.pop_back();
        return k;
    }
    string getLast10() {
        int n = s1.length();
        int idx = max(n-10,0);
        int len = n-idx;
        return s1.substr(idx,len);
    }
    string cursorLeft(int k) {
        k = min(k, (int) s1.size());
        for( int i = 0 ; i < k ; i++ ) {
            s2.push_back(s1.back());
            s1.pop_back();
        }
        return getLast10();
    }
    string cursorRight(int k) {
        k = min(k, (int) s2.size());
        for( int i = 0 ; i < k ; i++ ) {
            s1.push_back(s2.back());
            s2.pop_back();
        }
        return getLast10();
    }
};
