class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        for( int l = 1 ; l < 512 ; l *= 2 ) {
            string add = "";
            for(char c : s)
                add.push_back(c+1);
            s = s+add;
        }
        return s[k-1];
    }
};