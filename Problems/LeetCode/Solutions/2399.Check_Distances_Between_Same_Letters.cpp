class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> last(26,-1);
        for( int i = 0 ; i < s.length() ; i++ ) {
            int c = s[i]-'a';
            if(last[c] == -1)
                last[c] = i;
            else if(i-last[c]-1 != distance[c])
                return false;
        }
        return true;
    }
};
