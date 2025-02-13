class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        vector<int> indices;
        vector<bool> mark(n,false);
        for( int i = 0 ; i < n ; i++ )
            if(isdigit(s[i])) {
                mark[i] = true;
                indices.push_back(i);
            }
        for(int idx : indices)
            for( int i = idx-1 ; i >= 0 ; i-- )
                if(!mark[i]) {
                    mark[i] = true;
                    break;
                }
        string ans = "";
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i])
                ans.push_back(s[i]);
        return ans;
    }
};