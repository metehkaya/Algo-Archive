class Solution {
public:
    uint32_t ONE = 1;
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for( int i = 0 ; i < 32 ; i++ )
            if(n & (ONE << i))
                ans |= (ONE << (31-i));
        return ans;
    }
};