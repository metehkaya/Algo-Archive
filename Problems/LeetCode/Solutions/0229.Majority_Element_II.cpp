class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hashh;
        unordered_map<int,int>::iterator iter;
        for( int i = 0 ; i < n ; i++ ) {
            iter = hashh.find(nums[i]);
            if(iter == hashh.end()) {
                hashh.insert(make_pair(nums[i],1));
            }
            else
                iter->second++;
        }
        vector<int> ans;
        for( iter = hashh.begin() ; iter != hashh.end() ; iter++ ) {
            if(iter->second > n/3)
                ans.push_back(iter->first);
        }
        return ans;
    }
};