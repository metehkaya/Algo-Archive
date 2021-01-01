class Solution {
public:
    int countElements(vector<int>& ar) {
        int n = ar.size();
        unordered_set<int> nums;
        for( int i = 0 ; i < n ; i++ )
            nums.insert(ar[i]);
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += nums.find(ar[i]+1) != nums.end();
        return ans;
    }
};