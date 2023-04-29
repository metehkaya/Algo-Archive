class Solution {
public:
    int cnt[26];
    bool exists[26];
    int edge[26][26];
    bool f(int s , int e , int k , vector<string>& words) {
        int idx = s;
        while(idx <= e and words[idx].length() == k)
            idx++;
        if(idx > e)
            return false;
        int idx_first = idx;
        while(idx <= e) {
            if(words[idx].length() == k)
                return true;
            if(words[idx][k] != words[idx_first][k]) {
                edge[words[idx_first][k]-'a'][words[idx][k]-'a'] = true;
                if(f(idx_first,idx-1,k+1,words))
                    return true;
                idx_first = idx;
            }
            idx++;
        }
        if(f(idx_first,idx-1,k+1,words))
            return true;
        return false;
    }
    string alienOrder(vector<string>& words) {
        memset(edge,0,sizeof(edge));
        memset(exists,false,sizeof(exists));
        for(string s : words)
            for(char c : s)
                exists[c-'a'] = true;
        int n = words.size();
        if(f(0,n-1,0,words))
            return "";
        memset(cnt,0,sizeof(cnt));
        for( int i = 0 ; i < 26 ; i++ )
            for( int j = 0 ; j < 26 ; j++ )
                cnt[j] += edge[i][j];
        queue<int> q;
        string ans = "";
        for( int i = 0 ; i < 26 ; i++ )
            if(exists[i] and cnt[i] == 0)
                q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back('a'+u);
            for( int v = 0 ; v < 26 ; v++ )
                if(edge[u][v])
                    if(--cnt[v] == 0)
                        q.push(v);
        }
        for(int x : cnt)
            if(x > 0)
                return "";
        return ans;
    }
};
