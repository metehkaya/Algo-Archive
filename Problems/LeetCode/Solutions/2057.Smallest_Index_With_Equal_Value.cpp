class Solution {
public:
    int smallestEqual(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            if(i % 10 == ar[i])
                return i;
        return -1;
    }
};
