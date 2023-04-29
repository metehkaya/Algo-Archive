class Solution {
public:
    bool isIdealPermutation(vector<int>& ar) {
        int n = ar.size();
        int mx = -1;
        for( int i = 2 ; i < n ; i++ ) {
            mx = max(mx,ar[i-2]);
            if(mx > ar[i])
                return false;
        }
        return true;
    }
};