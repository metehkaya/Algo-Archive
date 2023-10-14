class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int cnt_nums = 0 , cnt_prev = 0;
        vector<int> ans,nums;
        for(string s : words) {
            if(s == "prev") {
                cnt_prev++;
                int add = cnt_prev <= cnt_nums ? nums[cnt_nums-cnt_prev] : -1;
                ans.push_back(add);
            }
            else {
                cnt_nums++;
                cnt_prev = 0;
                nums.push_back(stoi(s));
            }
        }
        return ans;
    }
};
