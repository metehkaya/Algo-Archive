class Solution {
public:
    struct compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }
    };
    int dir[4] = {0,1,0,-1};
    vector<int> maxPoints(vector<vector<int>>& ar, vector<int>& queries) {
        int n = ar.size();
        int m = ar[0].size();
        int q = queries.size();
        vector<int> ans(q);
        vector<vector<int>> qu;
        for( int i = 0 ; i < q ; i++ )
            qu.push_back({queries[i],i});
        sort(qu.begin(),qu.end());
        int cnt = 0;
        priority_queue<vector<int>, vector<vector<int>>, compare> heap;
        heap.push({ar[0][0],0,0});
        bool mark[n][m];
        memset(mark,false,sizeof(mark));
        mark[0][0] = true;
        for( int i = 0 ; i < q ; i++ ) {
            int qval = qu[i][0];
            int qidx = qu[i][1];
            while(!heap.empty() && heap.top()[0] < qval) {
                cnt++;
                int r = heap.top()[1];
                int c = heap.top()[2];
                heap.pop();
                for( int j = 0 ; j < 4 ; j++ ) {
                    int r2 = r + dir[j];
                    int c2 = c + dir[j^1];
                    if(r2 < 0 or r2 >= n or c2 < 0 or c2 >= m)
                        continue;
                    if(mark[r2][c2])
                        continue;
                    mark[r2][c2] = true;
                    heap.push({ar[r2][c2],r2,c2});
                }
            }
            ans[qidx] = cnt;
        }
        return ans;
    }
};
