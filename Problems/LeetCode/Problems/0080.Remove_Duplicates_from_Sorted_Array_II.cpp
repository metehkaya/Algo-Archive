class Solution {
public:
    int removeDuplicates(vector<int>& ar) {
        int n = ar.size() , idx = 0;
        for( int l = 0 , r = 0 ; l < n ; l = r ) {
            while(r < n && ar[l] == ar[r])
                r++;
            int cnt = min(r-l,2);
            while(cnt--)
                ar[idx++] = ar[r-1];
        }
        ar.erase(ar.begin()+idx,ar.end());
        return idx;
    }
};