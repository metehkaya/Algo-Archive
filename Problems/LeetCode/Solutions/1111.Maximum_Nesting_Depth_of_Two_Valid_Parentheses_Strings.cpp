class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.length();
        vector<int> ans;
        vector<int> val(2,0);
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c == '(') {
                if(val[0] <= val[1])
                    val[0]++ , ans.push_back(0);
                else
                    val[1]++ , ans.push_back(1);
            }
            else {
                if(val[0] >= val[1])
                    val[0]-- , ans.push_back(0);
                else
                    val[1]-- , ans.push_back(1);
            }
        }
        return ans;
    }
};