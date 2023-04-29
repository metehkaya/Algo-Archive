class Solution {
public:
    bool isPathCrossing(string s) {
        vector<int> curr(2,0);
        set<vector<int>> mark;
        mark.insert(curr);
        int n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c == 'N')
                curr[1]++;
            else if(c == 'S')
                curr[1]--;
            else if(c == 'E')
                curr[0]++;
            else
                curr[0]--;
            if(mark.find(curr) != mark.end())
                return true;
            mark.insert(curr);
        }
        return false;
    }
};