class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ar[3] = {a,b,c};
        sort(ar,ar+3);
        return min(ar[0]+ar[1],(ar[0]+ar[1]+ar[2])/2);
    }
};