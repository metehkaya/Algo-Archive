typedef long long LL;

class Solution {
public:
    void rebalance(set<pair<int,int>>& s, set<pair<int,int>>& extra, LL& sum, int sz) {
        while(s.size() < sz) {
            auto it = extra.begin();
            sum += (*it).first;
            s.insert((*it));
            extra.erase(it);
        }
        while(!extra.empty() && (*s.rbegin()).first > (*extra.begin()).first) {
            pair<int,int> rit = *s.rbegin();
            pair<int,int> it = *extra.begin();
            sum += it.first - rit.first;
            s.insert(it);
            extra.insert(rit);
            s.erase(rit);
            extra.erase(it);
        }
    }
    LL minimumCost(vector<int>& v, int k, int dist) {
        int n = v.size();
        LL sum = 0 , ans = 0;
        set<pair<int,int>> s,extra;
        for( int i = n-1 ; i >= n-(k-2) ; i-- ) {
            sum += v[i];
            s.insert(make_pair(v[i],i));
        }
        ans = LLONG_MAX;
        for( int i = n-(k-1) ; i >= 1 ; i-- ) {
            int idx = i+dist+1;
            if(idx < n) {
                pair<int,int> p = make_pair(v[idx],idx);
                auto it = s.find(p);
                if(it != s.end()) {
                    sum -= v[idx];
                    s.erase(it);
                }
                else
                    extra.erase(p);
            }
            rebalance(s,extra,sum,k-2);
            ans = min(ans,sum+v[i]);
            extra.insert(make_pair(v[i],i));
            rebalance(s,extra,sum,k-2);
        }
        return ans+v[0];
    }
};
