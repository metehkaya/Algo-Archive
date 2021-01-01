class Solution {
public:
    bool validMountainArray(vector<int>& ar) {
        int n = ar.size();
        if(n < 3)
            return false;
        int index = -1;
        for( int i = 1 ; i < n-1 ; i++ )
            if( ar[i] > ar[i-1] && ar[i] > ar[i+1] ) {
                if(index != -1)
                    return false;
                index = i;
            }
        if(index == -1)
            return false;
        for( int i = 0 ; i < index ; i++ )
            if( ar[i] >= ar[i+1] )
                return false;
        for( int i = index+1 ; i < n ; i++ )
            if( ar[i] >= ar[i-1] )
                return false;
        return true;
    }
};