class AuthenticationManager {
public:
    int t;
    map<string,int> mp;
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime+t;
    }
    void renew(string tokenId, int currentTime) {
        map<string,int>::iterator it = mp.find(tokenId);
        if(it != mp.end() && currentTime < it->second)
            mp[tokenId] = currentTime+t;
    }
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for(auto it : mp)
            if(currentTime < it.second)
                ans++;
        return ans;
    }
};