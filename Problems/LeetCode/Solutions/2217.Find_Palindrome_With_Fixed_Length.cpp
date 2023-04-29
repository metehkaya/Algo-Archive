class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int k = (intLength+1) / 2;
        int p10 = 1;
        for( int i = 1 ; i < k ; i++ )
            p10 *= 10;
        vector<long long> ans;
        for(int q : queries) {
            if(q > 9*p10)
                ans.push_back(-1);
            else {
                long long res = p10+q-1;
                string s = std::to_string(res);
                s = s.substr(0,intLength-k);
                reverse(s.begin(),s.end());
                for(char c : s)
                    res = 10*res+c-'0';
                ans.push_back(res);
            }
        }
        return ans;
    }
};
