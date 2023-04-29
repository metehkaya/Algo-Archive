class Solution {
public:
    bool isMonotonic(vector<int>& ar) {
        int n = ar.size();
        bool inc = true , dec = true;
        for( int i = 1 ; i < n ; i++ )
            if(ar[i] > ar[i-1])
                dec = false;
            else if(ar[i] < ar[i-1])
                inc = false;
        return inc or dec;
    }
};