class Solution {
public:
    vector<int> ar;
    Solution(vector<int>& ar) {
        this->ar = ar;
    }
    vector<int> reset() {
        return ar;
    }
    vector<int> shuffle() {
        vector<int> arr = ar;
        random_shuffle(arr.begin(),arr.end());
        return arr;
    }
};