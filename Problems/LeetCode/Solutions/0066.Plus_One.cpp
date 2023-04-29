class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int d = digits.size();
        bool add = 1;
        for( int i = d-1 ; i >= 0 ; i-- ) {
            int sum = digits[i]+add;
            add = sum/10;
            sum %= 10;
            digits[i] = sum;
        }
        if(add) {
            digits.resize(d+1);
            for( int i = d ; i >= 1 ; i-- )
                digits[i] = digits[i-1];
            digits[0] = add;
        }
        return digits;
    }
};