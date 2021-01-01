int rand7();

class Solution {
public:
    int rand10() {
        int num = 343;
        while(num >= 340) {
            num = 49 * (rand7()-1);
            num += 7 * (rand7()-1);
            num += 1 * (rand7()-1);
        }
        return num%10 + 1;
    }
};