class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            if(ar[i] == 1)
                ans = max(ans,j-i);
        }
        return ans;
    }
};