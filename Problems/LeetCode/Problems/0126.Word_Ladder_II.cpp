class Solution {
public:
    void f(int x , int src , vector<string>& wordList , map<int,vector<int>>& prev , vector<string>& curr , vector<vector<string>>& ans) {
        curr.push_back(wordList[x]);
        if(x == src) {
            vector<string> add = curr;
            reverse(add.begin(),add.end());
            ans.push_back(add);
        }
        else {
            vector<int> bef = prev[x];
            for( int i = 0 ; i < bef.size() ; i++ )
                f(bef[i],src,wordList,prev,curr,ans);
        }
        curr.pop_back();
    }
    vector<vector<string>> findLadders(string src, string dest, vector<string>& wordList) {
        queue<int> Q;
        vector<vector<string>> ans;
        map<string,int> mp;
        map<int,vector<int>> prev;
        map<string,int>::iterator it;
        wordList.push_back(src);
        for( int i = 0 ; i < wordList.size() ; i++ ) {
            string s = wordList[i];
            it = mp.find(s);
            if(it == mp.end())
                mp[s] = i;
        }
        if(mp.find(dest) == mp.end())
            return ans;
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
                break;
            string s = wordList[x];
            int len = s.length();
            for( int i = 0 ; i < len ; i++ )
                for( char c = 'a' ; c <= 'z' ; c++ )
                    if(s[i] != c) {
                        string t = s.substr(0,i) + c + s.substr(i+1,len-i-1);
                        it = mp.find(t);
                        if(it != mp.end()) {
                            int idx = it->second;
                            if(dist[idx] == 0) {
                                Q.push(idx);
                                dist[idx] = dist[x]+1;
                                prev[idx].push_back(x);
                            }
                            else if(dist[idx] == dist[x]+1)
                                prev[idx].push_back(x);
                        }
                    }
        }
        if(dist[e] == 0)
            return ans;
        vector<string> curr;
        f(e,s,wordList,prev,curr,ans);
        return ans;
    }
};