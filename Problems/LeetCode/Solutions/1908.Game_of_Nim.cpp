class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int ans = 0;
        for(int num : piles)
            ans ^= num;
        return ans != 0;
    }
};
