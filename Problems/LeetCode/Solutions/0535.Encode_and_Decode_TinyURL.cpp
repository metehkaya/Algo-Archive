class Solution {
public:
    map<string,string> long2short;
    map<string,string> short2long;
    const string chs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string encode(string longUrl) {
        map<string,string>::iterator it = long2short.find(longUrl);
        if(it != long2short.end())
            return it->second;
        string key = "";
        for( int i = 0 ; i < 6 ; i++ ) {
            char c = chs[rand()%52];
            key.push_back(c);
        }
        string shortUrl = "http://tinyurl.com/" + key;
        long2short[longUrl] = shortUrl;
        short2long[shortUrl] = longUrl;
        return shortUrl;
    }
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }
};