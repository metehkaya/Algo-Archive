class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int mx = 0;
        long long sum = 0;
        for(int val : damage) {
            sum += val;
            mx = max(mx,val);
        }
        return sum-min(mx,armor)+1;
    }
};
