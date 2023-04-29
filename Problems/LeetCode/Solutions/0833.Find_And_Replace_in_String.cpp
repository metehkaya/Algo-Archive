class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans;
        int n = s.length();
        int m = indexes.size();
        vector<int> next(n,-1);
        vector<string> replaced(n,"");
        for( int i = 0 ; i < m ; i++ ) {
            int ind = indexes[i];
            if( ind + sources[i].length() <= n )
                if( s.substr(ind, sources[i].length()) == sources[i] ) {
                    next[ind] = ind+sources[i].length();
                    replaced[ind] = targets[i];
                }
        }
        int index = 0;
        while(index < n) {
            if(replaced[index] == "")
                ans.push_back(s[index++]);
            else {
                ans += replaced[index];
                index = next[index];
            }
        }
        return ans;
    }
};