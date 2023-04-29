class Solution {
public:
    static const int maxv = 2001;
    bool mark[maxv];
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size() , ans = 0;
        sort(tasks.begin() , tasks.end() , [&](auto& a , auto& b) {
            return a[1] < b[1];
        });
        for(auto& v : tasks) {
            int l = v[0] , r = v[1] , cnt = v[2];
            for( int i = l ; i <= r ; i++ )
                cnt -= mark[i];
            for( int i = r ; i >= l and cnt > 0 ; i-- )
                if(!mark[i]) {
                    ans++;
                    cnt--;
                    mark[i] = true;
                }
        }
        return ans;
    }
};
