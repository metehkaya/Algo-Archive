class Solution {
public:
    void f(int row , int m , int n , vector<vector<string>>& ans , vector<string>& curr , vector<string>& words , map<string,vector<int>>& indices) {
        if(row == m) {
            ans.push_back(curr);
            return;
        }
        string s = "";
        for( int i = 0 ; i < row ; i++ )
            s.push_back(curr[i][row]);
        map<string,vector<int>>::iterator it = indices.find(s);
        if(it != indices.end()) {
            vector<int> v = it->second;
            for( int i = 0 ; i < v.size() ; i++ ) {
                int idx = v[i];
                curr.push_back(words[idx]);
                f(row+1,m,n,ans,curr,words,indices);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        int m = words[0].length();
        vector<vector<string>> ans;
        vector<string> curr;
        map<string,vector<int>> indices;
        for( int i = 0 ; i < n ; i++ ) {
            string s = "";
            for( int j = 0 ; j < m ; j++ ) {
                s.push_back(words[i][j]);
                indices[s].push_back(i);
            }
            indices[""].push_back(i);
        }
        f(0,m,n,ans,curr,words,indices);
        return ans;
    }
};