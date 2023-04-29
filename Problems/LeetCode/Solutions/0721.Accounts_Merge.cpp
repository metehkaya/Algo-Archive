class Solution {
public:
    static const int maxn = 10000;
    int nNames,nEmails;
    vector<string> names,emails;
    map<string,int> name_ids,email_ids;
    vector<int> adj[maxn];
    bool mark[maxn];
    int email_id_name_id[maxn];
    int add(string& s , map<string,int>& mp , vector<string>& v , int& id) {
        if(mp.find(s) == mp.end()) {
            mp[s] = id++;
            v.push_back(s);
        }
        return mp[s];
    }
    void dfs(int u , vector<string>& group) {
        mark[u] = true;
        group.push_back(emails[u]);
        int deg = adj[u].size();
        for( int i = 0 ; i < deg ; i++ ) {
            int v = adj[u][i];
            if(!mark[v])
                dfs(v,group);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for( int i = 0 ; i < n ; i++ ) {
            int sz = accounts[i].size();
            string name = accounts[i][0];
            int name_id = add(name,name_ids,names,nNames);
            int prev_id = -1;
            for( int j = 1 ; j < sz ; j++ ) {
                string email = accounts[i][j];
                int email_id = add(email,email_ids,emails,nEmails);
                email_id_name_id[email_id] = name_id;
                if(prev_id != -1) {
                    adj[prev_id].push_back(email_id);
                    adj[email_id].push_back(prev_id);
                }
                prev_id = email_id;
            }
        }
        vector<vector<string>> ans;
        for( int i = 0 ; i < nEmails ; i++ )
            if(!mark[i]) {
                vector<string> group,res;
                dfs(i,group);
                res.push_back(names[email_id_name_id[i]]);
                sort(group.begin(),group.end());
                res.insert(res.end(),group.begin(),group.end());
                ans.push_back(res);
            }
        return ans;
    }
};
