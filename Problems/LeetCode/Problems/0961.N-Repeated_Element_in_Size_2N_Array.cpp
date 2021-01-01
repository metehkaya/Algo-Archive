class Solution {
public:
    int repeatedNTimes(vector<int>& ar) {
        set<int> s;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(s.find(ar[i]) != s.end())
                return ar[i];
            s.insert(ar[i]);
        }
        return -1;
    }
};