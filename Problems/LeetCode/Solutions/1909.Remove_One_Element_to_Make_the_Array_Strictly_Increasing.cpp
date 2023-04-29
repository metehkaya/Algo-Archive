class Solution {
public:
    bool canBeIncreasing(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int last = 0;
            bool ok = true;
            for( int j = 0 ; j < n ; j++ ) {
                if(i == j)
                    continue;
                if(last >= ar[j]) {
                    ok = false;
                    break;
                }
                last = ar[j];
            }
            if(ok)
                return true;
        }
        return false;
    }
};