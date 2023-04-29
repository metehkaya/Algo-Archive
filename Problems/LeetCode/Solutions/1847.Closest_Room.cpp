class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        int m = queries.size();
        for( int i = 0 ; i < m ; i++ )
            queries[i].push_back(i);
        sort(rooms.begin() , rooms.end() , [&](vector<int>& a , vector<int>& b) {
            return a[1] > b[1];
        });
        sort(queries.begin() , queries.end() , [&](vector<int>& a , vector<int>& b) {
            return a[1] > b[1];
        });
        set<int> mys;
        vector<int> ans(m);
        for( int i = 0 , idx = 0 ; i < m ; i++ ) {
            while(idx < n && rooms[idx][1] >= queries[i][1])
                mys.insert(rooms[idx++][0]);
            int id = queries[i][2];
            int pref = queries[i][0];
            int x1 = -1 , d1 = INT_MAX;
            int x2 = -1 , d2 = INT_MAX;
            set<int>::iterator it = mys.lower_bound(pref);
            if(it != mys.end()) {
                x1 = (*it);
                d1 = abs(x1-pref);
            }
            if(it != mys.begin()) {
                it--;
                x2 = (*it);
                d2 = abs(x2-pref);
            }
            if(d2 <= d1)
                ans[id] = x2;
            else
                ans[id] = x1;
        }
        return ans;
    }
};