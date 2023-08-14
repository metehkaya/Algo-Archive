class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int nq = queries.size();
        vector<pair<int,int>> queries_sorted;
        for( int i = 0 ; i < nq ; i++ )
            queries_sorted.push_back(make_pair(queries[i],i));
        sort(queries_sorted.begin(),queries_sorted.end());
        int maxt = queries_sorted[nq-1].first;
        vector<int> times[n];
        for(vector<int> log : logs)
            if(log[1] <= maxt)
                times[log[0]-1].push_back(log[1]);
        map<int,int> add;
        add[0] = 0;
        add[maxt+1] = 0;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> time = times[i];
            int sz = time.size();
            if(sz == 0) {
                add[0]++;
                add[maxt+1]--;
            }
            else {
                sort(time.begin(),time.end());
                int t = time[0];
                add[0]++;
                add[t]--;
                t = time[sz-1];
                if(t+1+x <= maxt) {
                    add[t+1+x]++;
                    add[maxt+1]--;
                }
                for( int j = 1 ; j < sz ; j++ ) {
                    int t1 = time[j-1];
                    int t2 = time[j];
                    if(t1+1+x < t2) {
                        add[t1+1+x]++;
                        add[t2]--;
                    }
                }
            }
        }
        vector<int> ans(nq);
        int sum = 0 , idx = 0;
        for(auto x : add) {
            int t = x.first;
            int val = x.second;
            if(t > 0)
                while(idx < nq and queries_sorted[idx].first < t) {
                    ans[queries_sorted[idx].second] = sum;
                    idx++;
                }
            sum += val;
        }
        return ans;
    }
};
