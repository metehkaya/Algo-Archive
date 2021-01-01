typedef long long LL;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& ar, int k, int t) {
        int n = ar.size();
        multiset<int> s;
        multiset<int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            if(i > k) {
                it = s.find(ar[i-k-1]);
                s.erase(it);
            }
            LL mn = max((LL)ar[i]-t,(LL)INT_MIN);
            LL mx = min((LL)ar[i]+t,(LL)INT_MAX);
            it = s.lower_bound((int)mn);
            if(it != s.end() && (*it) <= (int)mx)
                return true;
            s.insert(ar[i]);
        }
        return false;
    }
};