class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank >= 5) {
            mainTank -= 5;
            ans += 5;
            if(additionalTank) {
                additionalTank--;
                mainTank++;
            }
        }
        ans += mainTank;
        return 10*ans;
    }
};
