class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        int val = 1;
        do {
            if(n == val)
                return true;
            if(val > INT_MAX/3 || val > n)
                return false;
            val *= 3;
        }while(val <= n);
        return false;
    }
};