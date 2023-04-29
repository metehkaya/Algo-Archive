class Solution {
public:
    int maxChunksToSorted(vector<int>& ar) {
        int n = ar.size() , ans = 0 , mx = -1;
        for( int i = 0 ; i < n ; i++ ) {
            mx = max(mx,ar[i]);
            if(mx == i)
                ans++;
        }
        return ans;
    }
};
