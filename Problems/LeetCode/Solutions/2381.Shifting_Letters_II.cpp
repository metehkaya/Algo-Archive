class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& ar) {
        int n = s.length();
        vector<int> add(n+1,0);
        for( int i = 0 ; i < ar.size() ; i++ ) {
            int s = ar[i][0];
            int e = ar[i][1] + 1;
            int v = (ar[i][2] == 1) ? 1 : 25;
            add[s] = (add[s] + v) % 26;
            add[e] = (add[e] - v + 26) % 26;
        }
        int sum = 0;
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            sum = (sum + add[i]) % 26;
            int c = s[i] - 'a';
            c = (c + sum) % 26;
            ans.push_back('a'+c);
        }
        return ans;
    }
};
