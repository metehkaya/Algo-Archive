class Solution {
public:
    int findUnsortedSubarray(vector<int>& ar) {
        int n = ar.size();
        int l = n , r = 0;
        vector<int> temp = ar;
        sort(temp.begin(),temp.end());
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] != temp[i]) {
                l = min(l,i);
                r = max(r,i);
            }
        return (l <= r) ? r-l+1 : 0;
    }
};