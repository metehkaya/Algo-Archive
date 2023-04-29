class Solution {
public:
    int numRescueBoats(vector<int>& ar, int k) {
        int ans = 0;
        int n = ar.size();
        multiset<int> s;
        for( int i = 0 ; i < n ; i++ )
            s.insert(ar[i]);
        while(!s.empty()) {
            auto it = s.end();
            it--;
            int x = *it;
            int y = k-x;
            it = s.upper_bound(y);
            if(it != s.begin() && n > 1) {
                n--;
                it--;
                s.erase(it);
            }
            it = s.end();
            it--;
            s.erase(it);
            n--;
            ans++;
        }
        return ans;
    }
};