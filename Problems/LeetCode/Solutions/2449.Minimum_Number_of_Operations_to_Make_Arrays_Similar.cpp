class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> nums0,nums1,target0,target1;
        for(int x : nums)
            if(x % 2)
                nums1.push_back(x);
            else
                nums0.push_back(x);
        for(int x : target)
            if(x % 2)
                target1.push_back(x);
            else
                target0.push_back(x);
        sort(nums0.begin(),nums0.end());
        sort(nums1.begin(),nums1.end());
        sort(target0.begin(),target0.end());
        sort(target1.begin(),target1.end());
        long long ans = 0;
        for( int i = 0 ; i < nums0.size() ; i++ )
            ans += abs(nums0[i]-target0[i]);
        for( int i = 0 ; i < nums1.size() ; i++ )
            ans += abs(nums1[i]-target1[i]);
        return ans/4;
    }
};
