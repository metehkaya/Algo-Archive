class Solution {
public:
    int getSum(int number) {
        int sum = 0;
        while(number) {
            int digit = number % 10;
            sum += digit * digit;
            number /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> numbers;
        numbers.insert(n);
        while(n != 1) {
            int nextN = getSum(n);
            if(numbers.find(nextN) != numbers.end())
                return false;
            n = nextN;
            numbers.insert(nextN);
        }
        return true;
    }
};