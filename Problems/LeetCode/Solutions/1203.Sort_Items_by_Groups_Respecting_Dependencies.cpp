class Solution {
public:
    int N;
    vector<vector<int>> group_items;
    vector<set<int>> after_item_set;
    vector<set<int>> after_group_set;
    vector<vector<int>> after_item;
    vector<vector<int>> after_group;
    vector<int> before_cnt_item;
    vector<int> before_cnt_group;
    vector<int> top_sort(vector<int>& vertices, vector<vector<int>>& adj, vector<int>& cnt) {
        queue<int> q;
        for(int u : vertices)
            if(cnt[u] == 0)
                q.push(u);
        vector<int> ordered;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ordered.push_back(u);
            for(int v : adj[u])
                if(--cnt[v] == 0)
                    q.push(v);
        }
        if(ordered.size() != vertices.size())
            ordered.clear();
        return ordered;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before_items) {
        N = n+m;
        group_items.resize(N);
        after_item_set.resize(n);
        after_group_set.resize(N);
        after_item.resize(n);
        after_group.resize(N);
        before_cnt_item.resize(n,0);
        before_cnt_group.resize(N,0);
        for( int i = 0 ; i < n ; i++ ) {
            if(group[i] == -1)
                group[i] = m+i;
            group_items[group[i]].push_back(i);
        }
        for( int i = 0 ; i < n ; i++ ) {
            int g_i = group[i];
            for(int j : before_items[i]) {
                int g_j = group[j];
                if(g_i == g_j)
                    after_item_set[j].insert(i);
                else
                    after_group_set[g_j].insert(g_i);
            }
        }
        for( int i = 0 ; i < n ; i++ ) {
            after_item[i].assign(after_item_set[i].begin(), after_item_set[i].end());
            for(int j : after_item[i])
                before_cnt_item[j]++;
        }
        for( int i = 0 ; i < N ; i++ ) {
            after_group[i].assign(after_group_set[i].begin(), after_group_set[i].end());
            for(int j : after_group[i])
                before_cnt_group[j]++;
        }
        vector<int> group_ids;
        for( int i = 0 ; i < N ; i++ )
            if(!group_items[i].empty())
                group_ids.push_back(i);
        vector<int> ans;
        vector<int> group_ordered = top_sort(group_ids, after_group, before_cnt_group);
        if(group_ordered.empty())
            return ans;
        for(int g : group_ordered) {
            vector<int> ordered = top_sort(group_items[g], after_item, before_cnt_item);
            if(ordered.empty()) {
                ans.clear();
                break;
            }
            for(int u : ordered)
                ans.push_back(u);
        }
        return ans;
    }
};
