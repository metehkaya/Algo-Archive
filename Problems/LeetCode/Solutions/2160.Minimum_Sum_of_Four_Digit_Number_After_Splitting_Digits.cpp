class Solution {
public:
    int minimumSum(int num) {
        int ar[4];
        ar[0] = (num/1) % 10;
        ar[1] = (num/10) % 10;
        ar[2] = (num/100) % 10;
        ar[3] = (num/1000) % 10;
        sort(ar,ar+4);
        return 10*(ar[0]+ar[1]) + ar[2]+ar[3];
    }
};
