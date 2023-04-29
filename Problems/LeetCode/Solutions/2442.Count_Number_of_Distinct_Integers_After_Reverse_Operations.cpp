class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        for(int x : nums) {
            string s = to_string(x);
            reverse(s.begin(),s.end());
            st.insert(stoi(s));
        }
        return st.size();
    }
};
