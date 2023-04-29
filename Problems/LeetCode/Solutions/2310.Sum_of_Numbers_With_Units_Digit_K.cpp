class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0)
            return 0;
        for( int i = 1 ; i <= 10 ; i++ ) {
            int sum = k*i;
            if(sum % 10 == num % 10) {
                if(sum > num)
                    return -1;
                return i;
            }
        }
        return -1;
    }
};
