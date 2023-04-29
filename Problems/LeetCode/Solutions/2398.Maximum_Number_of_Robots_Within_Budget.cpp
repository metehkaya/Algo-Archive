class Solution {
public:
    int getmax(multiset<int>& s) {
        if(s.empty())
            return 0;
        multiset<int>::reverse_iterator rit = s.rbegin();
        return (*rit);
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        multiset<int> s;
        long long sum = 0;
        int n = chargeTimes.size();
        int ans = 0;
        for( int l = 0 , r = -1 ; l < n ; l++ ) {
            if(r < l)
                r = l;
            while(r < n) {
                long long newsum = sum + runningCosts[r];
                int newmax = max(chargeTimes[r],getmax(s));
                long long newb = newsum*(r-l+1)+newmax;
                if(newb <= budget) {
                    sum = newsum;
                    s.insert(chargeTimes[r]);
                    r++;
                }
                else
                    break;
            }
            ans = max(ans,r-l);
            if(l < r) {
                multiset<int>::iterator it = s.find(chargeTimes[l]);
                s.erase(it);
                sum -= runningCosts[l];
            }
        }
        return ans;
    }
};
