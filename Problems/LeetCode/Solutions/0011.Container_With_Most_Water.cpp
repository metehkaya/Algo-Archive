class Solution {
public:
    int maxArea(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 , j = n-1 ; i < j ; ) {
            ans = max( min(ar[i],ar[j]) * (j-i) , ans );
            if(ar[i] < ar[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};