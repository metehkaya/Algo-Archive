class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n = h.size() , m = q.size();
        vector<int> ans(m, -1);
        vector<vector<pair<int, int>>> add_query(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for( int i = 0 ; i < m ; i++ ) {
            int a = q[i][0] , b = q[i][1];
            if(a > b)
                swap(a,b);
            if(a == b or h[a] < h[b])
                ans[i] = b;
            else
                add_query[b].push_back(make_pair(h[a],i));
        }
        for( int i = 0 ; i < n ; i++ ) {
            for(auto& query : add_query[i])
                pq.push(query);
            while(!pq.empty() && pq.top().first < h[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
        }
        return ans;
    }
};