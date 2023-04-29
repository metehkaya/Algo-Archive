class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 2 ; i < n ; i++ )
            if(ar[i]-ar[i-1] != ar[1]-ar[0])
                return false;
        return true;
    }
};