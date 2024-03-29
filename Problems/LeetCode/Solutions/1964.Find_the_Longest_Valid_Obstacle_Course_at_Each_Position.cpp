class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp, ans;
        for(auto x : ar) {
            auto it = upper_bound(dp.begin(), dp.end(), x);
            ans.push_back(it - dp.begin() + 1);
            if(it == dp.end())
                dp.push_back(x);
            else
                *it = x;
        }
        return ans;
    }
};