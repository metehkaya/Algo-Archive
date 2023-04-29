class Solution {
public:
    int n;
    static const int maxn = 100003;
    vector<int> tree[2][maxn];
    void init() {
        for( int i = 1 ; i <= n+1 ; i++ )
            tree[0][i] = tree[1][i] = {INT_MIN,-1};
    }
    void update(int kd , int id , int val , int idx) {
        while(id <= n+1) {
            if(val > tree[kd][id][0] or (val == tree[kd][id][0] and idx < tree[kd][id][1]))
                tree[kd][id] = {val,idx};
            id += (id & (-id));
        }
    }
    vector<int> query(int kd , int id) {
        vector<int> res({INT_MIN,-1});
        while(id) {
            if(tree[kd][id][0] > res[0] or (tree[kd][id][0] == res[0] and tree[kd][id][1] < res[1]))
                res = tree[kd][id];
            id -= (id & (-id));
        }
        return res;
    }
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        this->n = nums1.size();
        init();
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({nums1[i],nums2[i],i});
        sort(v.begin(),v.end());
        int best = INT_MAX;
        vector<int> ans(2,-1);
        for( int i = 0 ; i < n ; i++ ) {
            int x = v[i][0]+1 , y = v[i][1]+1 , id = v[i][2];
            vector<int> cost = query(0,y);
            if(cost[1] != -1) {
                int tmp_cost = (x+y) - cost[0];
                int idx1 = id , idx2 = cost[1];
                if(idx1 > idx2)
                    swap(idx1,idx2);
                vector<int> indices = {idx1,idx2};
                if(tmp_cost < best or (tmp_cost == best and indices < ans)) {
                    best = tmp_cost;
                    ans = indices;
                }
            }
            cost = query(1,n+2-y);
            if(cost[1] != -1) {
                int tmp_cost = (x-y) - cost[0];
                int idx1 = id , idx2 = cost[1];
                if(idx1 > idx2)
                    swap(idx1,idx2);
                vector<int> indices = {idx1,idx2};
                if(tmp_cost < best or (tmp_cost == best and indices < ans)) {
                    best = tmp_cost;
                    ans = indices;
                }
            }
            update(0,y,x+y,id);
            update(1,n+2-y,x-y,id);
        }
        return ans;
    }
};
