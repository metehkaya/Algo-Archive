class Solution {
public:
    string decodeMessage(string key, string msg) {
        vector<char> decode(256,0);
        char curr = 'a';
        for( int i = 0 ; i < key.length() ; i++ ) {
            char c = key[i];
            if(c != ' ' && decode[c] == 0)
                decode[c] = curr++;
        }
        decode[' '] = ' ';
        string ans = "";
        for( int i = 0 ; i < msg.length() ; i++ ) {
            char c = msg[i];
            ans.push_back(decode[c]);
        }
        return ans;
    }
};
