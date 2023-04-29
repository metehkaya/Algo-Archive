class Solution {
public:
    int distributeCandies(vector<int>& ar) {
        int n = ar.size();
        unordered_set<int> myset;
        for( int i = 0 ; i < n ; i++ ) {
            int val = ar[i];
            myset.insert(val);
        }
        return min(n/2, (int)myset.size());
    }
};