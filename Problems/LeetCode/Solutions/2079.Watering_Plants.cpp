class Solution {
public:
    int wateringPlants(vector<int>& ar, int capacity) {
        int curr = -1 , water = capacity , idx = 0 , n = ar.size() , ans = 0;
        while(idx < n) {
            if(water < ar[idx]) {
                ans += curr+1;
                curr = -1;
                water = capacity;
            }
            else {
                ans += idx-curr;
                curr = idx;
                water -= ar[idx++];
            }
        }
        return ans;
    }
};
