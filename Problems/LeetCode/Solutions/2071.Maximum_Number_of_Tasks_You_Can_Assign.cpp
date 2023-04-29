class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int ans = 0 , l = 1 , r = min(n,m);
        while(l <= r) {
            int mid = (l+r) >> 1 , rem = pills;
            bool ok = true;
            multiset<int> s(workers.end()-mid,workers.end());
            for( int i = mid-1 ; i >= 0 ; i-- ) {
                auto it = s.lower_bound(tasks[i]);
                if(it == s.end()) {
                    if(rem == 0) {
                        ok = false;
                        break;
                    }
                    it = s.lower_bound(tasks[i]-strength);
                    if(it == s.end()) {
                        ok = false;
                        break;
                    }
                    rem--;
                    s.erase(it);
                }
                else
                    s.erase(it);
            }
            if(ok)
                ans = mid , l = mid+1;
            else
                r = mid-1;
        }
        return ans;
    }
};
