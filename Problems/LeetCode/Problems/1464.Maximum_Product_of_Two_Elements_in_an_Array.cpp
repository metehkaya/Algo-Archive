class Solution {
public:
    int maxProduct(vector<int>& ar) {
        int n = ar.size();
        int first = 0 , second = 0;
        for( int i = 0 ; i < n ; i++ ) {
            ar[i]--;
            if(ar[i] >= first) {
                second = first;
                first = ar[i];
            }
            else if(ar[i] >= second)
                second = ar[i];
        }
        return first*second;
    }
};