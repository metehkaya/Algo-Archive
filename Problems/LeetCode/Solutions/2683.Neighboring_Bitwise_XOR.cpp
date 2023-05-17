class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val = 0;
        for(int x : derived)
            val ^= x;
        return (val == 0);
    }
};
