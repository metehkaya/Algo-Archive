class Solution {
public:
    long long minEnd(int n_int, int x_int) {
        long long x = x_int;
        vector<int> zero_bits;
        for( int i = 0 ; i <= 60 ; i++ )
            if((x & (1LL << i)) == 0)
                zero_bits.push_back(i);
        long long ans = x;
        long long n = n_int - 1;
        for( int i = 0 ; i < zero_bits.size() ; i++ ) {
            int zbit = zero_bits[i];
            if(n & (1LL << i))
                ans |= (1LL << zbit);
        }
        return ans;
    }
};