class Solution {
public:
    bool isNoZero(int number) {
        while(number > 0) {
            int digit = number % 10;
            if(digit == 0)
                return false;
            number /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for( int i = 1 ; i <= n/2 ; i++ )
            if(isNoZero(i) && isNoZero(n-i)) {
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        return ans;
    }
};