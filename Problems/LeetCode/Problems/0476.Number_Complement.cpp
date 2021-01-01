class Solution {
public:
    int findComplement(int num) {
        for( int i = 30 ; i >= 0 ; i-- )
            if( num & (1<<i) ) {
                for( int j = 0 ; j <= i ; j++ )
                    num ^= (1<<j);
                break;
            }
        return num;
    }
};