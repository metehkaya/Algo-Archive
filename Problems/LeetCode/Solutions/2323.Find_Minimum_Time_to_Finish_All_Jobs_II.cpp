class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        int n = jobs.size() , ans = 0;
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        for( int i = 0 ; i < n ; i++ ) {
            int j = jobs[i];
            int w = workers[i];
            ans = max(ans,(j+w-1)/w);
        }
        return ans;
    }
};
