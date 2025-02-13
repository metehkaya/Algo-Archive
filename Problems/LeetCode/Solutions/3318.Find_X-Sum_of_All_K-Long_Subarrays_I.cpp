class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for( int i = 0 ; i <= n-k ; i++ ) {
            map<int,int> mp;
            for( int j = i ; j < i+k ; j++ )
                mp[nums[j]]++;
            vector<pair<int,int>> pairs;
            for(auto it : mp)
                pairs.push_back(make_pair(it.second,it.first));
            sort(pairs.begin(),pairs.end());
            int sz = pairs.size() , total = 0;
            for( int j = sz-1 ; j >= max(sz-x,0) ; j-- )
                total += pairs[j].first * pairs[j].second;
            ans.push_back(total);
        }
        return ans;
    }
};