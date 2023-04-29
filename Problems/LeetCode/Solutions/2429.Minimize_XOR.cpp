class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0 , ans = 0;
        for( int i = 0 ; i <= 30 ; i++ )
            if(num2 & (1<<i))
                cnt++;
        for( int i = 30 ; i >= 0 && cnt > 0 ; i-- )
            if(num1 & (1<<i))
                ans |= (1<<i) , cnt--;
        for( int i = 0 ; i <= 30 && cnt > 0 ; i++ )
            if((num1 & (1<<i)) == 0)
                ans |= (1<<i) , cnt--;
        return ans;
    }
};
