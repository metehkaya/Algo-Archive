class Codec {
public:
    const char c = '#';
    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs) {
            ans += to_string(s.length());
            ans.push_back('#');
            ans += s;
        }
        return ans;
    }
    vector<string> decode(string s) {
        int idx = 0 , len = s.length();
        vector<string> ans;
        while(idx < len) {
            int idx_c = s.find_first_of(c, idx);
            int len = stoi(s.substr(idx,idx_c-idx));
            ans.push_back(s.substr(idx_c+1,len));
            idx = idx_c+1+len;
        }
        return ans;
    }
};
