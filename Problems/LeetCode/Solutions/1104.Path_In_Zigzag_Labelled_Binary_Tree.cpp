class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int lastLevel = 0;
        for( int i = 0 ; (1<<(i+1))-1 < label ; i++ )
            lastLevel = i+1;
        vector<int> ans;
        int curr = label;
        for( int level = lastLevel ; level >= 1 ; level-- ) {
            ans.push_back(curr);
            int mn = (1<<level);
            int mx = 2*mn-1;
            if(level % 2 == 0) {
                int diff = curr-mn;
                curr = (mx-diff) / 2;
            }
            else {
                int diff = mx-curr;
                curr = (mn+diff) / 2;
            }
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};