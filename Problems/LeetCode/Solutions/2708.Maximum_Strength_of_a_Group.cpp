class Solution {
public:
    long long f(int id , long long mult , bool ok , vector<int>& nums) {
        if(id == nums.size())
            return ok ? mult : -10;
        return max(f(id+1,mult,ok,nums),f(id+1,mult*nums[id],true,nums));
    }
    long long maxStrength(vector<int>& nums) {
        return f(0,1,false,nums);
    }
};
