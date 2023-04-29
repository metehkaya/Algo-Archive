class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = -1;
        while(n) {
            int x = n%2;
            n /= 2;
            if(x == last)
                return false;
            last = x;
        }
        return true;
    }
};