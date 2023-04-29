class Solution {
public:
    bool divideArray(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i += 2 )
            if(ar[i] != ar[i+1])
                return false;
        return true;
    }
};
