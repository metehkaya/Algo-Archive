class Solution {
public:
    int ladderLength(string src, string dest, vector<string>& wordList) {
        queue<int> Q;
        map<string,int> mp;
        map<string,int>::iterator it;
        wordList.push_back(src);
        for( int i = 0 ; i < wordList.size() ; i++ ) {
            string s = wordList[i];
            it = mp.find(s);
            if(it == mp.end())
                mp[s] = i;
        }
        if(mp.find(dest) == mp.end())
            return 0;
        int s = mp[src];
        int e = mp[dest];
        int n = wordList.size();
        vector<int> dist(n,0);
        Q.push(s);
        dist[s] = 1;
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            if(x == e)
                return dist[e];
            string s = wordList[x];
            int len = s.length();
            for( int i = 0 ; i < len ; i++ )
                for( char c = 'a' ; c <= 'z' ; c++ )
                    if(s[i] != c) {
                        string t = s.substr(0,i) + c + s.substr(i+1,len-i-1);
                        it = mp.find(t);
                        if(it != mp.end()) {
                            int idx = it->second;
                            if(!dist[idx]) {
                                Q.push(idx);
                                dist[idx] = dist[x]+1;
                            }
                        }
                    }
        }
        return 0;
    }
};