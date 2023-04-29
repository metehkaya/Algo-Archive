class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int,long long> mp;
        long long ans = 0;
        for( int i = 0 ; i < tasks.size() ; i++ ) {
            int x = tasks[i];
            map<int,long long>::iterator it = mp.find(x);
            if(it != mp.end())
                ans = max(ans,it->second+space);
            mp[x] = ++ans;
        }
        return ans;
    }
};
