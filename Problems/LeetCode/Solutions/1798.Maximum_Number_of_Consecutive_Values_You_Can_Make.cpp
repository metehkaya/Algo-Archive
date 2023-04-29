class Solution {
public:
    int getMaximumConsecutive(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        int sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(sum+1 >= ar[i])
                sum += ar[i];
            else
                break;
        }
        return sum+1;
    }
};