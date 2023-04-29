class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0 , digitSum = 0;
        for(int x : nums) {
            elementSum += x;
            while(x) {
                digitSum += x%10;
                x /= 10;
            }
        }
        return abs(elementSum-digitSum);
    }
};
