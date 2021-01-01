class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& ar) {
        int n = ar.size();
        for( int i = 1 ; i < n-1 ; i++ )
            if(ar[i]%2 && ar[i-1]%2 && ar[i+1]%2)
                return true;
        return false;
    }
};