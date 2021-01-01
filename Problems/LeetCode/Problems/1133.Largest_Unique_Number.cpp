class Solution {
public:
    int largestUniqueNumber(vector<int>& ar) {
        int n = ar.size() , ans = -1;
        sort(ar.begin() , ar.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            if(j == i+1)
                ans = ar[i];
        }
        return ans;
    }
};