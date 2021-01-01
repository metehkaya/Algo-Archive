class Solution {
public:
    bool confusingNumber(int N) {
        vector<int> digits;
        if(N == 0)
            return false;
        while(N) {
            digits.push_back(N%10);
            N /= 10;
        }
        bool invalid = false;
        bool changed = false;
        int d = digits.size();
        for( int i = 0 ; i < d ; i++ ) {
            int val = digits[i];
            if( val == 6 && digits[d-i-1] != 9 )
                changed = true;
            else if( val == 9 && digits[d-i-1] != 6 )
                changed = true;
            else if( val == 8 && digits[d-i-1] != 8 )
                changed = true;
            else if( val == 1 && digits[d-i-1] != 1 )
                changed = true;
            else if( val == 0 && i == d - 1 )
                changed = true;
            else if( val == 2 || val == 3 || val == 4 || val == 5 || val == 7 )
                invalid = true;
        }
        return changed && !invalid;
    }
};