class Solution {
public:
    bool find132pattern(vector<int>& ar) {
        int n = ar.size();
        multiset<int> s;
        multiset<int>::iterator it;
        for( int i = 1 ; i < n ; i++ )
            s.insert(ar[i]);
        int mn = INT_MAX;
        for( int i = 1 ; i < n ; i++ ) {
            mn = min(mn,ar[i-1]);
            it = s.find(ar[i]);
            s.erase(it);
            it = s.lower_bound(ar[i]);
            if(it != s.begin()) {
                it--;
                if(mn < (*it))
                    return true;
            }
        }
        return false;
    }
};