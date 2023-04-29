class Solution {
public:
    unordered_map<string,int> bfs(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int& root, int& level, int& n) {
        queue<pair<int,int>> Q;
        vector<bool> mark(n,false);
        unordered_map<string,int> hashh;
        Q.push(make_pair(root,level));
        mark[root] = true;
        while(!Q.empty()) {
            pair<int,int> p = Q.front();
            Q.pop();
            int u = p.first;
            int d = p.second;
            if(d == 0) {
                for( int i = 0 ; i < (int) watchedVideos[u].size() ; i++ )
                    hashh[watchedVideos[u][i]]++;
                continue;
            }
            for( int i = 0 ; i < (int) friends[u].size() ; i++ ) {
                int v = friends[u][i];
                if(mark[v])
                    continue;
                mark[v] = true;
                Q.push(make_pair(v,d-1));
            }
        }
        return hashh;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int root, int level) {
        int n = (int) friends.size();
        unordered_map<string,int> hashh = bfs(watchedVideos,friends,root,level,n);
        vector<pair<int,string>> res;
        unordered_map<string,int>::iterator it = hashh.begin();
        while(it != hashh.end()) {
            res.push_back(make_pair(it->second, it->first));
            it++;
        }
        sort(res.begin(), res.end());
        vector<string> ans;
        for( int i = 0 ; i < (int) res.size() ; i++ )
            ans.push_back(res[i].second);
        return ans;
    }
};