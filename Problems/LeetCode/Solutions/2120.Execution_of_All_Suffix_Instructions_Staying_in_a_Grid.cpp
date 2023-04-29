class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int m = s.length();
        for( int i = 0 ; i < m ; i++ ) {
            int r = startPos[0];
            int c = startPos[1];
            int cnt = 0;
            for( int j = i ; j < m ; j++ ) {
                if(s[j] == 'L')
                    c--;
                else if(s[j] == 'R')
                    c++;
                else if(s[j] == 'U')
                    r--;
                else
                    r++;
                if(r < 0 || r >= n || c < 0 || c >= n)
                    break;
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
