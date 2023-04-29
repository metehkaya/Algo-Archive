#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long ans = 0;
        int n = costs.size();
        int l = 0 , r = n-1;
        set<pi> s;
        while(l < c) {
            s.insert(pi(costs[l],l));
            l++;
        }
        while(r >= l && r >= n-c) {
            s.insert(pi(costs[r],r));
            r--;
        }
        while(k--) {
            auto it = s.begin();
            pi p = (*it);
            printf("%d %d\n",p.fi,p.se);
            ans += p.first;
            s.erase(it);
            if(l <= r) {
                if(p.se < l) {
                    s.insert(pi(costs[l],l));
                    l++;
                }
                else {
                    s.insert(pi(costs[r],r));
                    r--;
                }
            }
        }
        return ans;
    }
};
