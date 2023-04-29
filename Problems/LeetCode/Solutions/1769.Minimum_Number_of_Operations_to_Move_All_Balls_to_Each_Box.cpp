class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.length();
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            int cost = 0;
            for( int j = 0 ; j < n ; j++ )
                if(s[j] == '1')
                    cost += abs(i-j);
            ans.push_back(cost);
        }
        return ans;
    }
};