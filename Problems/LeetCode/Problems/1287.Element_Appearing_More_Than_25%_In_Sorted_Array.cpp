class Solution {
public:
    int findSpecialInteger(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            if(j - i > n / 4)
                return ar[i];
        }
        return -1;
    }
};