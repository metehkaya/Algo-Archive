class Encrypter {
public:
    map<string,int> cnt;
    map<char,string> enc;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int sz = keys.size();
        for( int i = 0 ; i < sz ; i++ )
            enc[keys[i]] = values[i];
        for(string s : dictionary) {
            string t = encrypt(s);
            cnt[t]++;
        }
    }
    string encrypt(string word1) {
        string s = "";
        for(char c : word1) {
            if(enc.find(c) != enc.end())
                s += enc[c];
            else
                return "";
        }
        return s;
    }
    int decrypt(string word2) {
        return cnt[word2];
    }
};
