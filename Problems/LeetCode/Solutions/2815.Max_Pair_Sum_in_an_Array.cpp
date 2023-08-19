class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> vals[10];
        for(int num : nums) {
            string s = to_string(num);
            char mx = '0';
            for(char c : s)
                mx = max(mx,c);
            vals[mx-'0'].push_back(num);
        }
        int ans = -1;
        for( int i = 1 ; i < 10 ; i++ ) {
            vector<int>& v = vals[i];
            sort(v.begin(),v.end(),greater<int>());
            if(v.size() >= 2)
                ans = max(ans,v[0]+v[1]);
        }
        return ans;
    }
};