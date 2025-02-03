class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for( int t = 0 ; true ; t++ ) {
            set<int> s;
            bool ok = true;
            for( int i = 3*t ; i < n ; i++ ) {
                if(s.find(nums[i]) != s.end())
                    ok = false;
                else
                    s.insert(nums[i]);
            }
            if(ok)
                return t;
        }
        return -1;
    }
};