class Solution {
public:
    bool containsDuplicate(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 1 ; i < n ; i++ )
            if(ar[i] == ar[i-1])
                return true;
        return false;
    }
};